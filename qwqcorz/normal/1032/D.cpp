#include<bits/stdc++.h>
using namespace std;
const double inf=1e18;

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
double sqr(double x)
{
	return x*x;
}
struct point
{
	double x,y;
}p[10];
struct line
{
	double a,b,c;
	point X(double x)
	{
		point ret;
		ret.x=x;
		ret.y=-(a*x+c)/b;
		return ret;
	}
	point Y(double y)
	{
		point ret;
		ret.x=-(b*y+c)/a;
		ret.y=y;
		return ret;
	}
}l;
double dis(point a,point b)
{
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
double f[10][10];

signed main()
{
	double a=read(),b=read(),c=read();
	double x1=read(),y1=read(),x2=read(),y2=read();
	l.a=a;
	l.b=b;
	l.c=c;
	p[0].x=x1;
	p[0].y=y1;
	p[5].x=x2;
	p[5].y=y2;
	p[1]=l.X(x1);
	p[2]=l.Y(y1);
	p[3]=l.X(x2);
	p[4]=l.Y(y2);
	for (int i=0;i<=5;i++)
	for (int j=0;j<=5;j++) f[i][j]=inf;
	f[0][5]=fabs(x1-x2)+fabs(y1-y2);
	f[0][1]=dis(p[0],p[1]);
	f[0][2]=dis(p[0],p[2]);
	f[3][5]=dis(p[3],p[5]);
	f[4][5]=dis(p[4],p[5]);
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++) f[i][j]=dis(p[i],p[j]);
	for (int k=0;k<=5;k++)
	for (int i=0;i<=5;i++)
	for (int j=0;j<=5;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	printf("%.10lf",f[0][5]);

	return 0;
}