// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const double eps=1e-10;
struct quadra
{
	int a;
	double b,c,l,r;
	quadra(const int a=0,const double b=0.0,const double c=0.0,const double l=0.0,const double r=0.0){this->a=a;this->b=b;this->c=c;this->l=l;this->r=r;}
	quadra move(const double t,const double l,const double r){return quadra(a,b-(2.0*a)*t,(1.0*a)*t*t-b*t+c,l,r);}
	inline double qmin(double& pos)
	{
		pos=-0.5*b/(a*1.0);
		if(pos<l)pos=l;
		if(pos>r)pos=r;
		return a*pos*pos+b*pos+c;
	}
};
struct function
{
	quadra a[12011],ta[12011];
	int n,tn;
	inline double qmin(double &pos)
	{
		double ret=1e100,cpos,c;
		for(int i=1;i<=n;i++)
		{
			if(ret>(c=a[i].qmin(cpos)))
			{
				ret=c;
				pos=cpos;
			}
		}
		return ret;
	}
	inline double addone(const quadra&t,double&P,int aa,int bb,double l,double r)
	{
		double pos,mn;
		mn=qmin(pos);
		tn=0;
		bool flag=0;
		for(int i=1;i<=n;i++)
		{	
			if(pos>=a[i].l&&pos<=a[i].r&&!flag)
			{
				flag=1;
				ta[++tn]=a[i].move(aa,a[i].l+aa*1.0,pos+aa*1.0);
				ta[++tn]=quadra(0,0,mn,pos+aa*1.0,pos+bb*1.0);
				ta[++tn]=a[i].move(bb,pos+bb*1.0,a[i].r+bb*1.0);
			}
			else if(pos>=a[i].r)
				ta[++tn]=a[i].move(aa,a[i].l+aa*1.0,a[i].r+aa*1.0);
			else if(pos<=a[i].l)
				ta[++tn]=a[i].move(bb,a[i].l+bb*1.0,a[i].r+bb*1.0);
		}
		for(int i=1;i<=tn;i++)
		{
			ta[i].a+=t.a;
			ta[i].b+=t.b;
			ta[i].c+=t.c;
			ta[i].l=max(ta[i].l,l);
			ta[i].r=min(ta[i].r,r);
		}
		n=0;
		for(int i=1;i<=tn;i++)
			if(ta[i].l<ta[i].r)
				a[++n]=ta[i];
		return qmin(P);
	}
}thor;
int n,q,a,b,y[6666];
double p[6666],mn[6666],ans[6666];
int main()
{
	get2(n,q);get2(a,b);
	for(int i=1;i<=n;i++)
	{
		int &x=y[i];
		get1(x);
		if(i==1)
		{
			thor.n=1;
			thor.a[1]=quadra(1,-2.0*x,1.0*x*x,1,q);
			p[1]=x;mn[1]=0.0;
		}
		else mn[i]=thor.addone(quadra(1,-2.0*x,1.0*x*x,1+(i-1)*a,q),p[i],a,b,1+(i-1)*a,q);
//		thor.out();
	}
	ans[n]=p[n];
	for(int i=n-1;i>=1;i--)
	{
		if(p[i]+a>ans[i+1])ans[i]=ans[i+1]-a;
		else if(p[i]+b<ans[i+1])ans[i]=ans[i+1]-b;
		else ans[i]=p[i];
	}
	double sum=0;
	for(int i=1;i<=n;i++)
		sum=sum+(ans[i]-y[i])*(ans[i]-y[i]);
	for(int i=1;i<=n;i++)printf("%.8lf ",ans[i]);
	printf("\n%.8lf\n",sum);
	return 0;
}