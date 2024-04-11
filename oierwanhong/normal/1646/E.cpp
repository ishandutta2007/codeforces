#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/

const int MAXN = 1000011;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

bool vis[MAXN*30];
bool del[MAXN];
int f[21];
int main()
{
	int n=read(),m=read();
	int now=0;
	for(int r=1;r<=20;++r)
	{
		for(int i=1;i<=m;++i)
			if(!vis[r*i])vis[r*i]=1,++now;
		f[r]=now;
	}
	ll ans=1;
	for(int x=2;x<=n;++x)
	{
		if(del[x])continue;
		ll y=x;
		int cnt=1;
		while(y<=n)
		{
			del[y]=1;
			y*=x,++cnt;
		}
		ans+=f[cnt-1];
	}
	printf("%lld\n",ans);
	return 0;
}