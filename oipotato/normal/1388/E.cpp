#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=2010;
struct Rational
{
	int a,b;
	Rational(){}
	Rational(int x,int y)
	{
		if(y<0)x=-x,y=-y;
		a=x;b=y;
	}
	bool operator<(const Rational&A)const{return 1ll*a*A.b<1ll*b*A.a;}
	long double work(int x,int y)const{return x+1.L*a/b*y;}
	void print()const{printf("%d/%d\n",a,b);}
}p[N*N];
pair<Rational,Rational>seg[N*N];
struct data
{
	int xl,xr,y;
	void scan(){scanf("%d%d%d",&xl,&xr,&y);}
	bool operator<(const data&a)const{return y<a.y;}
}a[N];
struct Convex
{
	pair<int,int>q[N];
	int t,w;
	void init(){t=1;w=0;}
	void add(int x,int y)
	{
		for(;w>=2&&Rational(q[w].first-q[w-1].first,q[w].second-q[w-1].second)<Rational(x-q[w].first,y-q[w].second);w--);
		q[++w]=mp(x,y);
	}
	long double get(const Rational&x)
	{
		for(;t<w&&Rational(q[t].first-q[t+1].first,q[t+1].second-q[t].second)<x;t++);
		return x.work(q[t].first,q[t].second);
	}
	void print(){puts("Convex:");rep(i,w)printf("%d %d\n",q[i].first,q[i].second);}
}Hmin,Hmax;
int n;
int main()
{
	scanf("%d",&n);
	rep(i,n)a[i].scan();
	sort(a+1,a+n+1);
	if(a[1].y==a[n].y)
	{
		int l=a[1].xl,r=a[1].xr;
		rep(i,n)l=min(l,a[i].xl),r=max(r,a[i].xr);
		printf("%d\n",r-l);
		return 0;
	}
	Hmin.init();Hmax.init();
	for(int i=n;i;i--)
	{
		int j=i;
		for(;j&&a[j].y==a[i].y;j--);
		int x=a[i].xl;
		for(int k=j+1;k<=i;k++)x=min(x,a[k].xl);
		Hmin.add(x,a[i].y);
		i=j+1;
	}
	rep(i,n)
	{
		int j=i;
		for(;j<=n&&a[j].y==a[i].y;j++);
		int x=a[i].xr;
		for(int k=i;k<j;k++)x=max(x,a[k].xr);
		Hmax.add(x,a[i].y);
		i=j-1;
	}
	//Hmin.print();
	//Hmax.print();
	int cnt=0,tot=0;
	rep(i,n)rep(j,n)if(a[i].y<a[j].y)
	{
		p[++cnt]=Rational(a[i].xl-a[j].xr,a[j].y-a[i].y);
		p[++cnt]=Rational(a[i].xr-a[j].xl,a[j].y-a[i].y);
		seg[++tot]=mp(p[cnt-1],p[cnt]);
	}
	sort(p+1,p+cnt+1);
	sort(seg+1,seg+tot+1);
	int tmp=0;
	rep(i,tot)if(tmp&&seg[i].first<seg[tmp].second)seg[tmp].second=max(seg[tmp].second,seg[i].second);else seg[++tmp]=seg[i];
	tot=tmp;tmp=1;
	long double ans=1e18;
	rep(i,cnt)
	{
		for(;tmp<=tot&&!(p[i]<seg[tmp].second);tmp++);
		if(tmp<=tot&&seg[tmp].first<p[i])continue;
		ans=min(ans,Hmax.get(p[i])-Hmin.get(p[i]));
		// p[i].print();printf("%.10Lf %.10Lf\n",Hmin.get(p[i]),Hmax.get(p[i]));
		// rep(j,n)printf("%.10Lf%c",p[i].work(a[j].xl,a[j].y)," \n"[j==n]);
		// rep(j,n)printf("%.10Lf%c",p[i].work(a[j].xr,a[j].y)," \n"[j==n]);
	}
	printf("%.10Lf\n",ans);
	return 0;
}