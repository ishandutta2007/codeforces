#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
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
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 2000011;
bool vis[MAXN];
int a[MAXN];
void sieve(int n)
{
	vis[1]=1;
	for(int i=2;i<=n;++i)
		if(!vis[i])
			for(int j=i<<1;j<=n;j+=i)vis[j]=1;
}
int main()
{
	sieve(2000000);
	int task=read();
	while(task--)
	{
		int n=read(),k=read();
		ll ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i)
			if(!vis[a[i]])
			{
				ll l=1,r=1;
				while(i-l*k>=1&&a[i-l*k]==1)++l;
				while(i+r*k<=n&&a[i+r*k]==1)++r;
				ans+=l*r-1;
			}
		printf("%lld\n",ans);
	}
	return 0;
}