#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct edge{int to,val;};
vector<edge>e[N];
namespace lca
{
	ll sum[N];
	int ndfn[N],dfn[N],deep[N],siz[N],son[N],fa[N],top[N],cntdfn=0;
	void dfs0(int now,int father)
	{
		siz[now]=1,son[now]=0;
		ndfn[dfn[now]=++cntdfn]=now;
		deep[now]=deep[fa[now]=father]+1;
		for (edge i:e[now])
		{
			int to=i.to,val=i.val;
			if (to==father) continue;
			sum[to]=sum[now]+val;
			dfs0(to,now);
			siz[now]+=siz[to];
			if (siz[to]>siz[son[now]]) son[now]=to;
		}
	}
	void dfs1(int now,int father,int Top)
	{
		top[now]=Top;
		if (son[now]) dfs1(son[now],now,Top);
		for (edge i:e[now])
		{
			int to=i.to;
			if (to==father||to==son[now]) continue;
			dfs1(to,now,to);
		}
	}
	int find(int x,int y)
	{
		while (top[x]!=top[y])
		{
			if (deep[top[x]]<deep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
		if (deep[x]<deep[y]) swap(x,y);
		return y;
	}
	ll query(int x,int y)
	{
		x=ndfn[x],y=ndfn[y];
		int lca=find(x,y);
		return sum[x]+sum[y]-sum[lca]*2;
	}
}
using lca::dfn;
using lca::ndfn;

void GreenDay()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	lca::dfs0(1,0);
	lca::dfs1(1,0,1);
	ll ans=0;
	set<int>S;
	int Q=read();
	while (Q--)
	{
		char c; cin>>c;
		if (c=='?') print(ans/2);
		if (c=='+')
		{
			int x=dfn[read()];
			auto now=S.insert(x).first,pre=now,nxt=now;
			if (now!=S.begin()) pre--;
						   else pre=prev(S.end());
			if (next(now)!=S.end()) nxt++;
							   else nxt=S.begin();
			ans+=lca::query(*pre,*now)+lca::query(*now,*nxt)-lca::query(*pre,*nxt);
		}
		if (c=='-')
		{
			int x=dfn[read()];
			auto now=S.find(x),pre=now,nxt=now;
			if (now!=S.begin()) pre--;
						   else pre=prev(S.end());
			if (next(now)!=S.end()) nxt++;
							   else nxt=S.begin();
			ans+=lca::query(*pre,*nxt)-lca::query(*pre,*now)-lca::query(*now,*nxt);
			S.erase(x);
		}
	}
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();

	return 0;
}