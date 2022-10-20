#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

namespace Graph
{
	int n;
	struct basis
	{
		int st[35],top,f[30];
		void insert(int x)
		{
			for (int i=29;i>=0;i--)
			if (x>>i&1)
			{
				if (f[i]) x^=f[i];
					 else return f[st[++top]=i]=x,void();
			}
		}
		int query(int x)
		{
			for (int i=29;i>=0;i--) if (x>>i&1) x^=f[i];
			return x;
		}
		void pop(int tmp)
		{
			while (top>tmp) f[st[top--]]=0;
		}
	}t;
	struct dsu
	{
		int st[N],top;
		int fa[N],siz[N],val[N];
		pair<int,int>find(int x)
		{
			if (fa[x]==x) return make_pair(x,0);
			auto ret=find(fa[x]);
			ret.second^=val[x];
			return ret;
		}
		int merge(int x,int y,int w)
		{
			auto a=find(x),b=find(y);
			w^=a.second^b.second;
			x=a.first,y=b.first;
			if (x==y) return w;
			if (siz[x]>siz[y]) swap(x,y);
			st[++top]=x;
			fa[x]=y;
			siz[y]+=siz[x];
			val[x]=w;
			return 0;
		}
		void pop(int tmp)
		{
			while (top>tmp)
			{
				int x=st[top--];
				siz[fa[x]]-=siz[x];
				fa[x]=x;
			}
		}
	}d;
	void send(int _n)
	{
		n=_n;
		for (int i=1;i<=n;i++) d.fa[i]=i,d.siz[i]=1;
	}
	void add_edge(int u,int v,int w)
	{
		t.insert(d.merge(u,v,w));
	}
	int query(int x,int y)
	{
		return t.query(d.find(x).second^d.find(y).second);
	}
}
struct edge{int x,y,w;};
vector<edge>t[N*4];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
void add(int w,int l,int r,int ql,int qr,edge x)
{
	if (ql<=l&&r<=qr) return t[w].push_back(x),void();
	if (ql<=mid) add(ls,l,mid,ql,qr,x);
	if (qr>mid) add(rs,mid+1,r,ql,qr,x);
}
struct Query
{
	int x,y,ans;
}q[N];
map<int,pair<int,int>>e[N];
void solve(int w,int l,int r)
{
	int tmp1=Graph::t.top,tmp2=Graph::d.top;
	for (edge i:t[w]) Graph::add_edge(i.x,i.y,i.w);
	if (l==r)
	{
		if (q[l].x) q[l].ans=Graph::query(q[l].x,q[l].y);
	}
	else
		solve(ls,l,mid),
		solve(rs,mid+1,r);
	Graph::t.pop(tmp1);
	Graph::d.pop(tmp2);
}
#undef mid
#undef rs
#undef ls

signed main()
{
	int n=read(),m=read();
	Graph::send(n);
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u][v]=make_pair(w,1);
	}
	int Q=read();
	for (int i=1;i<=Q;i++)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1) e[x][y]=make_pair(read(),i);
		if (opt==2)
		{
			add(1,1,Q,e[x][y].second,i,(edge){x,y,e[x][y].first});
			e[x].erase(y);
		}
		if (opt==3) q[i].x=x,q[i].y=y;
	}
	for (int i=1;i<=n;i++)
	for (auto j:e[i])
	add(1,1,Q,j.second.second,Q,(edge){i,j.first,j.second.first});
	solve(1,1,Q);
	for (int i=1;i<=Q;i++) if (q[i].x) print(q[i].ans);
	
	return 0;
}