#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int gcd(int x,int y){return !y?x:gcd(y,x%y);}
struct point
{
	ll x,y;
	point(ll _x=0,ll _y=0){x=_x,y=_y;}
	ll ang(){return atan2(y,x);}
	ll len(){return sqrt(x*x+y*y);}
	friend point operator -(const point &a,const point &b){return (point){a.x-b.x,a.y-b.y};}
	friend point operator +(const point &a,const point &b){return (point){a.x+b.x,a.y+b.y};}
	friend point operator /(const point &a,const ll &b){return (point){a.x/b,a.y/b};}
	friend point operator *(const point &a,const ll &b){return (point){a.x*b,a.y*b};}
	bool operator <(const point &a)const{return x!=a.x?x<a.x:y<a.y;}
	bool operator ==(const point &a)const{return x==a.x&&y==a.y;}
	point &init()
	{
		x=read()*2,y=read()*2;
		return *this;
	}
	point dj()
	{
		int g=gcd(x,y);
		return (point){x/g,y/g};
	}
}a[N],m;
ll cross(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
ll dis[N];
bool vis[N];
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) m=m+(a[i].init());
	for (int i=1;i<=n;i++) a[i]=a[i]*n;
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j++)
	if (m==(a[i]+a[j])/2) vis[i]=vis[j]=1;
	int b=0;
	for (int i=1;i<=n;i++) if (!vis[i]) b=i;
	if (!b) return puts("-1"),void();
	for (int i=1;i<=n;i++) a[i]=a[i]-m;
	vector<point>ans;
	for (int i=1;i<=n;i++)
	{
		point mid=(a[i]+a[b])/2;
		for (int j=1;j<=n;j++) dis[j]=cross(mid,a[j]);
		sort(dis+1,dis+1+n);
		bool flag=1;
		for (int j=1;j<=n/2;j++) flag&=dis[j]==-dis[n-j+1];
		if (flag) ans.push_back(mid.dj());
	}
	sort(ans.begin(),ans.end());
	print(unique(ans.begin(),ans.end())-ans.begin());
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}