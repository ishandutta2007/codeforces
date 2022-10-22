#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll a[500011];
int main()
{
	ll n=read(),m=read(),g=0;
	for(int i=1;i<=n;++i)a[i]=read();
	for(ll i=2;i<=n;++i)g=gcd(g,abs(a[i]-a[i-1]));
	for(ll i=1;i<=m;++i)printf("%lld ",gcd(a[1]+read(),g));
	puts("");
	return 0;
}