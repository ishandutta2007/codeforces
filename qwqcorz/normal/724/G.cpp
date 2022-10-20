#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool vis[N];
int deep[N];
ll sum[N];
vector<pair<int,ll>>e[N];
struct edge{int u,v;ll w;};
vector<int>V;
vector<edge>E;
void dfs(int now,int father)
{
	V.push_back(now);
	vis[now]=1;
	for (auto [to,w]:e[now])
	if (!vis[to])
	{
		sum[to]=sum[now]^w;
		deep[to]=deep[now]+1;
		dfs(to,now);
	}
	else if (deep[to]<deep[now]&&to!=father) E.push_back((edge){now,to,w});
}
struct basis
{
	ll t[64];
	void insert(ll x)
	{
		for (int i=60;i>=0;i--)
		if (x>>i&1)
		{
			if (t[i]) x^=t[i];
				 else return t[i]=x,void();
		}
	}
}b;
int tot[64][2],f[64][2],g[64][2];

signed main()
{
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		ll w=read();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for (int i=1;i<=n;i++)
	if (!vis[i])
	{
		V.clear(),E.clear();
		memset(b.t,0,sizeof(b.t));
		memset(tot,0,sizeof(tot));
		memset(f,0,sizeof(f));
		dfs(i,0);
		for (auto [u,v,w]:E) b.insert(sum[u]^sum[v]^w);
		for (int i:V)
		for (int j=0;j<=60;j++) tot[j][sum[i]>>j&1]++;
		for (int i=0;i<=60;i++) f[i][0]=1;
		for (int i=0;i<=60;i++) if (b.t[i])
		{
			memset(g,0,sizeof(g));
			for (int j=0;j<=60;j++)
			for (int k=0;k<=1;k++)
				g[j][k]=(g[j][k]+f[j][k])%p,
				g[j][k^(b.t[i]>>j&1)]=(g[j][k^(b.t[i]>>j&1)]+f[j][k])%p;
			memcpy(f,g,sizeof(f));
		}
		for (int i=0;i<=60;i++)
		{
			int tot0=(1LL*tot[i][0]*(tot[i][0]-1)/2+1LL*tot[i][1]*(tot[i][1]-1)/2)%p;
			int tot1=1LL*tot[i][0]*tot[i][1]%p;
			ans=(ans+(1LL<<i)%p*(1LL*tot0*f[i][1]%p+1LL*tot1*f[i][0]%p))%p;
		}
	}
	print(ans);
	
	return 0;
}