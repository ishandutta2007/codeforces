#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
const double eps=1e-10;
inline int sgn(double x)
{
	return x>eps?1:x<-eps?-1:0;
}
inline bool eql(double x,double y)
{
	return sgn(x-y)==0;
}
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	void print() const
	{
		if(sgn(x)==0) printf("0.00000 ");
		else printf("%.5lf ",x);
		//printf("sgnx=%d,%.10lf\n",sgn(x),-eps);
		if(sgn(y)==0) printf("0.00000\n");
		else printf("%.5lf\n",y);
	}
};
bool operator<(const Point a,const Point b)
{
	return eql(a.x,b.x)?a.y<b.y:a.x<b.x;
}
Point operator+(const Point a,const Point b)
{
	return Point(a.x+b.x,a.y+b.y);
}
Point operator-(const Point a,const Point b)
{
	return Point(a.x-b.x,a.y-b.y);
}
Point operator*(const Point a,const double b)
{
	return Point(a.x*b,a.y*b);
}
Point operator/(const Point a,const double b)
{
	return Point(a.x/b,a.y/b);
}
double operator*(const Point a,const Point b)
{
	return a.x*b.x+a.y*b.y;
}
double Cross(const Point a,const Point b)
{
	return a.x*b.y-a.y*b.x;
}
double getlen(const Point a)
{
	return sqrt(a*a);
}
struct Line
{
	Point p,v;
	Line(){}
	Line(Point p,Point v):p(p),v(v){}
};
Point getint(Line a,Line b)
{
//	printf("getint:a=%.1lf,%.1lf,,%.1lf,%.1lf,b=%.1lf,%.1lf,,%.1lf,%.1lf\n",a.p.x,a.p.y,a.v.x,a.v.y,b.p.x,b.p.y,b.v.x,b.v.y);
	double k=Cross(b.v,a.p-b.p)/Cross(a.v,b.v);
//	printf("k=%f\n",k);
	return a.p+a.v*k;
}
int n,h;
Point a[200005],b;
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	b=Point(a[n].x,a[n].y+h);
	int las=n;
	double ans=0;
	for(int i=n;i>1;i--)
	{
		int fl=sgn(Cross(a[i-1]-b,a[las]-b));
		if(fl<0) continue;
		if(fl==0)
		{
			int fl2=sgn(Cross(a[i]-b,a[las]-b));
			if(fl2==0)
			{
				ans+=sqrt((a[i]-a[i-1])*(a[i]-a[i-1]));
			}
			continue;
		}
		Point p=getint(Line(b,a[las]-b),Line(a[i],a[i-1]-a[i]));
	//	printf("i=%d,las=%d,p=%lf,%lf\n",i,las,p.x,p.y);
		ans+=sqrt((p-a[i-1])*(p-a[i-1]));
		las=i-1;
	}
	printf("%.9lf\n",ans);
	return 0;
}