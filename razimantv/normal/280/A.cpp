# include <cstdio>
# include <cmath>
# include <algorithm>
# include <iostream>

using namespace std;

int main()
{
	double w,h;
	int theta;
	scanf("%lf%lf%d",&w,&h,&theta);
	if(w<h)swap(w,h);
	if(theta>90)theta=180-theta;
	
	if(theta==0)
	{
		printf("%.8lf\n",w*h);
		return 0;
	}
	else if(theta==90)
	{
		printf("%.8lf\n",h*h);
		return 0;
	}
	
	double alpha=theta*atan(1)/45;
	double x1=w*cos(alpha)+h*sin(-alpha),y1=w*-sin(-alpha)+h*cos(alpha);
	double x2=-w*cos(alpha)+h*sin(-alpha),y2=-w*-sin(-alpha)+h*cos(alpha);
	double x3=w*cos(alpha)+-h*sin(-alpha),y3=w*-sin(-alpha)+-h*cos(alpha);
	
	double x4=x1+(h-y1)*(x2-x1)/(y2-y1),x5=x1+(h-y1)*(x3-x1)/(y3-y1);
	double y4=y1+(-w-x1)*(y2-y1)/(x2-x1),y5=y1+(w-x1)*(y3-y1)/(x3-x1);
	
	double removearea=((x4+w)*(h-y4)+(w-x5)*(h-y5))/4;
	if(y4<-h)
	{
		printf("%.8lf\n",h*(h/sin(alpha)));
		return 0;
	}
	printf("%.8lf\n",w*h-removearea);
	
	return 0;
}