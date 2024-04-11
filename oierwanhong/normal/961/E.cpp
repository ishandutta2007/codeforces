#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
int n;
namespace BIT
{
#define lowb (i&-i)
	int t[MAXN];
	void modify(int i,int k){while(i<=n)t[i]+=k,i+=lowb;}
	int Qsum(int i)
	{
		int res=0;
		while(i)res+=t[i],i-=lowb;
		return res;
	}
}
int a[MAXN];
std::vector<int>g[MAXN];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]<=n)g[a[i]].push_back(i);
		BIT::modify(i,1);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>i)ans+=BIT::Qsum(min(a[i],n))-BIT::Qsum(i);
		for(auto p:g[i])BIT::modify(p,-1);
	}
	printf("%lld\n",ans);
	return 0;
}