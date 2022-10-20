#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct dsu
{
	int st[N*2],top=0;
	int siz[N*2],fa[N*2],n;
	int find(int x){return fa[x]==x?fa[x]:find(fa[x]);}
	void merge(int u,int v)
	{
		if ((u=find(u))==(v=find(v))) return;
		if (siz[u]>siz[v]) swap(u,v);
		st[++top]=u;
		fa[u]=v;
		siz[v]+=siz[u];
	}
	void revoke(int _top)
	{
		while (top>_top)
		{
			int x=st[top--];
			siz[fa[x]]-=siz[x];
			fa[x]=x;
		}
	}
	void send(int _n)
	{
		n=_n;
		for (int i=1;i<=n*2;i++) fa[i]=i,siz[i]=1;
	}
}t;
int col[N];
struct edge{int u,v;};
unordered_map<int,vector<edge>>e[N];
bool is[N];

signed main()
{
	int n=read(),m=read(),k=read();
	for (int i=1;i<=n;i++) col[i]=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (col[u]>col[v]) swap(u,v);
		e[col[u]][col[v]].push_back((edge){u,v});
	}
	int tot=0;
	t.send(n);
	for (int i=1;i<=k;i++)
	{
		bool flag=1;
		for (auto j:e[i][i])
		if (t.find(j.u)==t.find(j.v))
		{
			flag=0;
			break;
		}
		else
		{
			t.merge(j.u,j.v+n);
			t.merge(j.u+n,j.v);
		}
		is[i]=flag;
		tot+=flag;
	}
	ll ans=1LL*tot*(tot-1)/2;
	for (int i=1;i<=k;i++)
	if (is[i])
	for (auto a:e[i])
	if (a.first!=i&&is[a.first])
	{
		int _top=t.top;
		bool flag=1;
		for (edge j:a.second)
		if (t.find(j.u)==t.find(j.v))
		{
			flag=0;
			break;
		}
		else
		{
			t.merge(j.u,j.v+n);
			t.merge(j.u+n,j.v);
		}
		ans-=!flag;
		t.revoke(_top);
//		print(i,' '),print(a.first,':'),print(flag);
	}
	print(ans);
	
	return 0;
}