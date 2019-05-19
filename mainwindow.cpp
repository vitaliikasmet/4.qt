#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmath.h>
#include "qchartview.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{


    int a =ui->spinBox  ->value();
    int b =ui->spinBox_2->value();
    int c =ui->spinBox_3->value();
    chrt = new QChart;

    ui->vchart->setChart(chrt); // связь графика с элементом отображения
    chrt->setTitle("y=a*sin(b*x+c)");
    // ось Х
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(-50,50); // диапазон значений на оси
    axisX->setTickCount(1); // число линий сетки
    //axisX->setLabelFormat("%.3f"); // формат отображения чисел на оси
    // ось Y
    QValueAxis *axisY = new QValueAxis;
    if(a>=0)
        axisY->setRange(a*(-1), a);
    else
        axisY->setRange(a, a*(-1));
    axisY->setTickCount(1);
    axisY->setLabelFormat("%d");
    // кривые, отображаемые на графике
    QLineSeries* series1 = new QLineSeries();
    // построение графиков функций
    for(int i = -50; i<=50; i++)
        series1->append(i,a*qSin(b*i+c));
    chrt->addSeries(series1);
    // устанавливаем оси для каждого графика
    chrt->setAxisX(axisX, series1);
    chrt->setAxisY(axisY, series1);
   // chrt->setAxisX(axisX, series2);
    //chrt->setAxisY(axisY, series2);

}
