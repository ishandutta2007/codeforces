#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}
#define point complex<double>
#define x real()
#define y imag()

double cross(point a,point b){return a.x*b.y-a.y*b.x;}
point a[N];
point get(point a,point b,double Y)
{
	if (a.y==b.y) return a;
	return a+(b-a)*((Y-a.y)/(b.y-a.y));
}
vector<tuple<double,int,double,double>>q;
void add_segment(point a,point b,double k)
{
	if (a.x==b.x) return;
	if (a.x>b.x) return add_segment(b,a,-k);
	double K=(b.y-a.y)/(b.x-a.x);
	double B=a.y-a.x*K;
	q.push_back({a.x,0,k*-B,k*-K/2});
	q.push_back({b.x,0,k*B,k*K/2});
}
double ans[N];

signed main()
{
	int n=read(),Q=read(),mn=0;
	for (int i=0;i<n;i++)
	{
		int X=read(),Y=read();
		a[i]=point(X,Y);
		if (a[i].y<a[mn].y) mn=i;
	}
	double area=0;
	for (int i=0;i<n;i++)
	{
		int j=(i+1)%n;
		area+=cross(a[i],a[j]);
		if (a[i].y<a[j].y) add_segment(a[i],a[j],1);
					  else add_segment(a[j],a[i],1);
	}
	area=abs(area/2);
	rotate(a,a+mn,a+n);
	point now=a[0];
	for (int i=0,j=n;i+1<j;)
	if (a[i+1].y<a[j-1].y)
	{
		point nxt=(a[i+1]+get(a[j%n],a[j-1],a[i+1].y))*0.5;
		add_segment(nxt,now,2);
		now=nxt;
		i++;
	}
	else
	{
		point nxt=(a[j-1]+get(a[i],a[i+1],a[j-1].y))*0.5;
		add_segment(nxt,now,2);
		now=nxt;
		j--;
	}
	for (int i=1;i<=Q;i++)
	{
		int X=read();
		q.push_back({X,i,-1,-1});
	}
	sort(q.begin(),q.end());
	double a=0,b=0;
	for (auto [X,id,A,B]:q)
	if (id) ans[id]=area+a*X+b*X*X;
	   else area-=A*X+B*X*X,a+=A,b+=B;
	for (int i=1;i<=Q;i++) printf("%.10lf\n",ans[i]);
	
	return 0;
}