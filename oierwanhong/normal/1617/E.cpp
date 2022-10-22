#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
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
const int MAXN = 8000011;
std::map<int,int>f;
int fa[MAXN],maxl[MAXN];
int fir[MAXN];
std::vector<int>g[MAXN];
int ans,bestx,besty;
int lg2(int x)
{
	int res=0;
	while(x)++res,x>>=1;
	return res;
}
void solve(int u)
{
	maxl[u]=0;
	std::sort(g[u].begin(),g[u].end());
	g[u].resize(std::unique(g[u].begin(),g[u].end())-g[u].begin());
	for(auto v:g[u])
	{
		solve(v);
		if(fir[u])
		{
			if(umax(ans,maxl[u]+maxl[v]+1))bestx=fir[u],besty=fir[v];
		}
		if(umax(maxl[u],maxl[v]+1))fir[u]=fir[v];
	}
}
int main()
{
	int n=read(),all=0;
	for(int i=1;i<=n;++i)
	{
		//printf("i=%d:\n",i);
		int x=read(),pre=0;
		while(1)
		{
			if(!f.count(x))f[x]=++all;//,printf("F[%d]=%d\n",x,all);
			int now=f[x];
			if(pre)fa[pre]=now,g[now].emplace_back(pre);//,printf("Addedge %d %d\n",now,pre);
			else fir[now]=i;
			pre=now;
			if(x==0)break;
			int k=lg2(x);
			if(x==(1<<(k-1)))x=0;
			else x=(1<<k)-x;
		}
	}
	int R=f[0];
	solve(R);
	printf("%d %d %d\n",bestx,besty, ans);
	return 0;
}