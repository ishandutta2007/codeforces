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
const int MAXN = 400011;
std::vector<int>g[MAXN];
pll f[MAXN][2];
void operator+= (pll& a,pll b){a.first+=b.first,a.second+=b.second;}
pll better(pll a,pll b){return a.first>b.first||(a.first==b.first&&a.second<b.second)?a:b;}
void dfs1(int u,int fa)
{
	f[u][0]=pll(0,1);
	f[u][1]=pll(1,0);
	for(auto v:g[u])
		if(v!=fa)
		{
			dfs1(v,u);
			pll t0=f[v][0],t1=f[v][1];
			++t1.second;
			f[u][0]+=better(t0,t1);
			f[u][1]+=t0,++f[u][1].second;
			//printf("Merge(%d,%d) F[%d,0]=(%lld,%lld),F[%d,1]=(%lld,%lld)\n",u,v,u,f[u][0].first,f[u][0].second,u,f[u][1].first,f[u][1].second);
		}
}
ll res[MAXN];
void dfs2(int u,int fa,int type)
{
	if(type==1)res[u]=g[u].size();
	else res[u]=1;
	for(auto v:g[u])
		if(v!=fa)
		{
			if(type==1)dfs2(v,u,0);
			else
			{
				pll t0=f[v][0],t1=f[v][1];
				++t1.second;
				if(better(t0,t1)==t0)dfs2(v,u,0);
				else dfs2(v,u,1);
			}
		}
}
int main()
{
	int n=read();
	for(int i=1;i<n;++i){int u=read(),v=read();g[u].emplace_back(v),g[v].emplace_back(u);}
	if(n==2)
	{
		printf("2 2\n1 1\n");
		return 0;
	}
	dfs1(1,0);
	pll ans=better(f[1][0],f[1][1]);
	printf("%lld %lld\n",ans.first,ans.second);
	dfs2(1,0,ans==f[1][0]?0:1);
	for(int i=1;i<=n;++i)printf("%lld ",res[i]);
	return 0;
}