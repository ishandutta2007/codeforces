//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
#define MAXN 200011
struct point
{
	double x,y;
	double mul()
	{
		return x*x+y*y;
	}
}a[MAXN];
std::vector<point>vec;
int main()
{
	ll n=read();
	for(ll i=0;i<n;++i)a[i].x=read(),a[i].y=read();
	for(ll i=0;i<n;++i)
	{
		vec.push_back(point{a[(i+1)%n].x-a[i].x,a[(i+1)%n].y-a[i].y});
	}
	bool flag=1;
	ll c=n/2;
	for(ll i=0;i<c;++i)
	{
		double k1=vec[i].y/vec[i].x;
		double k2=vec[c+i].y/vec[c+i].x;
		if(fabs(k1)!=fabs(k2)||(vec[i].mul()!=vec[c+i].mul()))flag=0;
	}
	puts(flag?"YES":"NO");
	return 0;
}