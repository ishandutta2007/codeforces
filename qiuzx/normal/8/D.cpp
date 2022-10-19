//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
const double eps=1e-10;
double p1,p2,dxa,dya,dxb,dyb,dxc,dyc;
double dist(double dx1,double dy1,double dx2,double dy2)
{
	return sqrt((dx1-dx2)*(dx1-dx2)+(dy1-dy2)*(dy1-dy2));
}
pair<pair<double,double>,pair<double,double> > intersect(double dx1,double dy1,double dr1,double dx2,double dy2,double dr2)
{
	bool flp=false;
	if(dx1==dx2)
	{
		flp=true;
		swap(dy1,dx1);
		swap(dy2,dx2);
	}
	if(dx1>dx2)
	{
		swap(dx1,dx2);
		swap(dy1,dy2);
		swap(dr1,dr2);
	}
	double d=dist(dx1,dy1,dx2,dy2);
	double x=(dr1*dr1+d*d-dr2*dr2)/(d*2);
	double al=(abs(x/dr1-1.0)<=eps)?0:acos(x/dr1),bt=atan((dy2-dy1)/(dx2-dx1));
	double the1=bt+al,the2=bt-al;
	pair<double,double> ans1=make_pair(dr1*cos(the1)+dx1,dr1*sin(the1)+dy1);
	pair<double,double> ans2=make_pair(dr1*cos(the2)+dx1,dr1*sin(the2)+dy1);
	if(flp)
	{
		swap(ans1.F,ans1.S);
		swap(ans2.F,ans2.S);
	}
	if(ans1>ans2)
	{
		swap(ans1,ans2);
	}
	return make_pair(ans1,ans2);
}
bool isintersect(double dx1,double dy1,double dr1,double dx2,double dy2,double dr2)
{
	return dist(dx1,dy1,dx2,dy2)<=dr1+dr2+eps;
}
bool isinclude(double dx1,double dy1,double dr1,double dx2,double dy2,double dr2)
{
	if(dr1<dr2)
	{
		swap(dx1,dx2),swap(dy1,dy2),swap(dr1,dr2);
	}
	return dist(dx1,dy1,dx2,dy2)+dr2<=dr1;
}
bool isinside(pair<double,double> pr,double dx,double dy,double dr)
{
	return dist(pr.F,pr.S,dx,dy)<=dr+eps;
}
bool check(double res)
{
	double rb=p1-res,rc=p2-res,ra=res;
	if(!(isintersect(dxa,dya,ra,dxb,dyb,rb)&&isintersect(dxa,dya,ra,dxc,dyc,rc)&&isintersect(dxb,dyb,rb,dxc,dyc,rc)))
	{
		return false;
	}
	if(isinclude(dxb,dyb,rb,dxc,dyc,rc)||isinclude(dxa,dya,ra,dxc,dyc,rc)||isinclude(dxb,dyb,rb,dxc,dyc,rc))
	{
		return true;
	}
	pair<pair<double,double>,pair<double,double> > t1=intersect(dxa,dya,ra,dxb,dyb,rb);
	pair<pair<double,double>,pair<double,double> > t2=intersect(dxa,dya,ra,dxc,dyc,rc);
	pair<pair<double,double>,pair<double,double> > t3=intersect(dxb,dyb,rb,dxc,dyc,rc);
	if(isinside(t1.F,dxa,dya,ra)&&isinside(t1.F,dxb,dyb,rb)&&isinside(t1.F,dxc,dyc,rc))
	{
		return true;
	}
	if(isinside(t1.S,dxa,dya,ra)&&isinside(t1.S,dxb,dyb,rb)&&isinside(t1.S,dxc,dyc,rc))
	{
		return true;
	}
	if(isinside(t2.F,dxa,dya,ra)&&isinside(t2.F,dxb,dyb,rb)&&isinside(t2.F,dxc,dyc,rc))
	{
		return true;
	}
	if(isinside(t2.S,dxa,dya,ra)&&isinside(t2.S,dxb,dyb,rb)&&isinside(t2.S,dxc,dyc,rc))
	{
		return true;
	}
	if(isinside(t3.F,dxa,dya,ra)&&isinside(t3.F,dxb,dyb,rb)&&isinside(t3.F,dxc,dyc,rc))
	{
		return true;
	}
	if(isinside(t3.S,dxa,dya,ra)&&isinside(t3.S,dxb,dyb,rb)&&isinside(t3.S,dxc,dyc,rc))
	{
		return true;
	}
	return false;
}
int main(){
	ll i;
	double l,r,mid;
	cin>>p1>>p2>>dxa>>dya>>dxb>>dyb>>dxc>>dyc;
	swap(p1,p2);
	double d1=dist(dxa,dya,dxb,dyb),d2=dist(dxa,dya,dxc,dyc),d3=dist(dxb,dyb,dxc,dyc);
	if(d2+d3<=d1+p1+eps)
	{
		printf("%.10lf\n",min(d2+d3+p2,d1+p1));
		return 0;
	}
	p2+=d2;
	p1+=d1;
	l=0,r=min(p1,p2);
	while(l+eps<=r)
	{
		mid=(l+r)*(double)0.5;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	printf("%.10lf\n",l);
	return 0;
}