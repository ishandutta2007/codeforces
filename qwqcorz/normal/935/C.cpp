#include<bits/stdc++.h>
using namespace std;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

signed main()
{
	double R=read(),x1=read(),y1=read(),x2=read(),y2=read();
	double d=dis(x1,y1,x2,y2);
	if (R<=d) return printf("%.16lf %.16lf %.16lf\n",x1,y1,R),0;
	double r=(d+R)/2.0;
	double dx=x1-x2,dy=y1-y2;
	if (dx==0&&dy==0) dx=1;
	dx*=r;
	dy*=r;
	if (d)
	{
		dx/=d;
		dy/=d;
	}
	x2+=dx;
	y2+=dy;
	printf("%.16lf %.16lf %.16lf\n",x2,y2,r);

	return 0;
}