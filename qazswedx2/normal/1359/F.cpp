#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
//#define double long double
const double eps=1e-8;
int sgn(double x)
{
	if(x>eps) return 1;
	if(x<-eps) return -1;
	return 0;
}
typedef struct Point
{
	double x,y;
	int id;
	Point(double x=0,double y=0,int id=0):x(x),y(y),id(id){}
	bool operator<(const Point p) const
	{
		return x==p.x?y<p.y:x<p.x;
	}
}Vector;
Point operator+(const Point &a,const Point &b)
{
	return Point(a.x+b.x,a.y+b.y);
}
Point operator-(const Point &a,const Point &b)
{
	return Point(a.x-b.x,a.y-b.y);
}
Point operator*(const Point &a,const double &b)
{
	return Point(a.x*b,a.y*b);
}
Point operator*(const double &a,const Point &b)
{
	return b*a;
}
double operator*(const Point &a,const Point &b)
{
	return a.x*b.x+a.y*b.y;
}
double Cross(const Point &a,const Point &b)
{
	return a.x*b.y-a.y*b.x;
}
struct Line
{
	Point p,v,vv;
}a[100005],b[100005];
Point lltop(Line l1,Line l2)
{
	double x=Cross(l2.p-l1.p,l1.v)/Cross(l1.v,l2.v);
	return l2.p+l2.v*x;
}
bool check2(Line l1,Line l2)
{
	//printf("l=%f,%f,%f,%f,l2=%f,%f,%f,%f,C=%f\n",l1.p.x,l1.p.y,l1.p.x+l1.v.x,l1.p.y+l1.v.y,l2.p.x,l2.p.y,l2.p.x+l2.v.x,l2.p.y+l2.v.y,Cross(l1.vv,l2.vv));
	if(sgn(Cross(l1.vv,l2.vv))==0)
	{
	//	printf("--------------------\n");
		return sgn(Cross(l1.vv,l2.p-l1.p))==0&&sgn((l2.p-l1.p)*(l2.p-l1.p-l1.v))<=0;
	}
	Point p=lltop(l1,l2);
//	if(sgn((p-l1.p)*(p-l1.p-l1.v))<=0&&sgn((p-l2.p)*(p-l2.p-l2.v))<=0)
	return sgn((p-l1.p)*(p-l1.p-l1.v))<=0&&sgn((p-l2.p)*(p-l2.p-l2.v))<=0;
}
Point c[100005];
int n,sp[100005],vis[100005];
set<Line>::iterator lit[100005];
set<Line> st;
double xx;
double getlen(Vector v)
{
	return sqrt(v.x*v.x+v.y*v.y);
}
bool operator<(const Line l1,const Line l2)
{
	return sgn((l1.p.y+(xx-l1.p.x)/l1.v.x*l1.v.y)-(l2.p.y+(xx-l2.p.x)/l2.v.x*l2.v.y))<0;
}
bool check(double t)
{
	for(int i=1;i<=n;i++)
	{
		a[i].p=b[i].p;
		a[i].v=b[i].v*(sp[i]*t/getlen(b[i].v));
		a[i].vv=a[i].v;
		vis[i]=0;
		c[i]=a[i].p;
		c[i+n]=a[i].p+a[i].v;
		c[i].id=c[i+n].id=i;
		//printf("a=Segment %f %f %f %f\n",a[i].p.x,a[i].p.y,a[i].p.x+a[i].v.x,a[i].p.y+a[i].v.y);
	}
	//printf("t=%f\n",t);
	sort(c+1,c+2*n+1);
	st.clear();
	for(int i=1;i<=2*n;i++)
	{
		int id=c[i].id;
		/*printf("id=%d,c=%f,%f\n",id,c[i].x,c[i].y);
		for(int j=1;j<=n;j++)
		{
			printf("j=%d,ans=%f\n",j,a[j].p.y+(xx-a[j].p.x)/a[j].v.x*a[j].v.y);
		}
		printf("sz=%d\n",(int)st.size());
		for(set<Line>::iterator it=st.begin();it!=st.end();it++)
		{
			printf("it=%f,%f,%f,%f\n",it->p.x,it->p.y,it->v.x,it->v.y);
		}*/
		set<Line>::iterator it;
		if(!vis[id])
		{
			vis[id]=1;
			it=st.lower_bound(a[id]);
		//	printf("***it=%f,%f,%f,%f,qwq=%d\n",it->p.x,it->p.y,it->v.x,it->v.y,(int)(it==st.begin()));
			if(it!=st.end())
				if(check2(a[id],*it))
				{
			//		printf("a\n");
					return 0;
					
				}
			if(it!=st.begin())
			{
				it--;
				if(check2(a[id],*it))
				{
			//		printf("b\n");
					return 0;
				}
			}
			int ssz=st.size();
			xx=c[i].x;
			lit[id]=st.insert(a[id]).first;
			if((int)st.size()==ssz)
				return 0;
		}
		else
		{
			it=lit[id];
			if(it!=st.begin())
			{
		//		printf("id=%d,it=%f,%f,%f,%f\n",id,it->p.x,it->p.y,it->v.x,it->v.y);
				it--;
				if(check2(a[id],*it))
				{
			//		printf("c\n");
					return 0;
				}
			}
			it=lit[id];
			if(it!=st.end())
			{
				it++;
				if(it!=st.end()&&check2(a[id],*it))
				{
			//		printf("d\n");
					return 0;
				}
			}
			st.erase(lit[id]);
		}
		xx=c[i].x;
	}
	//printf("qwq\n");
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,xx,yy;
		scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&sp[i]);
		b[i].p.x=x,b[i].p.y=y;
		b[i].v.x=xx,b[i].v.y=yy;
	}
	double l=0,r=1e14,mid;
//	if(!check(10)) r=5;
	for(int i=1;i<=70;i++)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	//check(3.6);
	if(r<=5e13) printf("%.10f",r);
	else printf("No show :(");
	return 0;
}