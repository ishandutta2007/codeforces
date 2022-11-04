#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const double eps=1e-4,PI=acos(-1.0);
struct Point
{
    double x,y;
    void input()
    {
        double _x,_y;
        scanf("%lf%lf",&_x,&_y);
        x=_x;y=_y;
    }
}a[5];
double Dis_PTP(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Area(double a,double b,double c)
{
    return sqrt(2*a*a*b*b+2*b*b*c*c+2*c*c*a*a
                -a*a*a*a-b*b*b*b-c*c*c*c)/4;
}
double Radius(double a,double b,double c)
{
    return a*b*c/(4*Area(a,b,c));
}
double gcd(double x,double y) {
    while(fabs(x)>eps&&fabs(y)>eps){
        if(x>y)
            x-=floor(x/y)*y;
        else
            y-=floor(y/x)*x;
    }
    return x+y;
}
int main()
{

    for(int i=0;i<3;i++)a[i].input();
    a[3]=a[0];
    double b[5];
    for(int i=0;i<3;i++){
        b[i]=Dis_PTP(a[i],a[i+1]);
    }
    double R=Radius(b[0],b[1],b[2]);
    sort(b,b+3);
    double ang0=asin(b[0]/2/R);
    double ang1=asin(b[1]/2/R);
    double ang2=PI-ang0-ang1;
    double n=PI/gcd(gcd(ang0,ang1),ang2);
    printf("%.8f\n",n*R*R*sin(2*PI/n)/2);
    return 0;
}