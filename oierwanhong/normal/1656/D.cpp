#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef __int128 I128;
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
/*
const int MAXN = 100011;
std::vector<pii>factor[MAXN];
int rest[MAXN],pri[MAXN],cnt;
bool vis[MAXN];
void init(int n)
{
	for(int i=1;i<=n;++i)rest[i]=i;
	for(int i=2;i<=n;++i)
	{
		if(vis[i])continue;
		pri[++cnt]=i;
		factor[i].emplace_back(pii(i,1));
		for(int j=i<<1;j<=n;j+=i)
		{
			int c=0;
			vis[j]=1;
			while(rest[j]%i==0)rest[j]/=i,++c;
			factor[j].emplace_back(pii(i,c));
		}
	}
}
*/
int main()
{
	//init(100000);
	int task=read();
	while(task--)
	{
		ll n=read(),rest=1,r=n;
		while(!(r&1))r>>=1,rest<<=1;
		if(r==1){puts("-1");continue;}
		rest<<=1;
		I128 sum=I128(1+rest)*(rest)/2;
		if(sum<=n)printf("%llu\n",rest);
		else printf("%llu\n",n/(rest>>1));
	}
	return 0;
}