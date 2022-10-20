#include<bits/stdc++.h>
#define ll long long
#define piir pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,m,k,Q;
struct dsu
{
	bool d[N];
	int fa[N],siz[N],st[N],top=0,n;
	void send(int _n){n=_n;for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:find(fa[x]);}
	bool calc(int x){return fa[x]==x?0:calc(fa[x])^d[x];}
	bool check(int x,int y)
	{
		bool val=calc(x)^calc(y)^1;
		x=find(x),y=find(y);
		if (x!=y) return 1;
		return !val;
	}
	bool merge(int x,int y)
	{
		bool val=calc(x)^calc(y)^1;
		x=find(x),y=find(y);
		if (x==y) return 0;
		if (siz[x]>siz[y]) swap(x,y);
		fa[x]=y,d[x]=val,siz[y]+=siz[x];
		st[++top]=x;
		return 1;
	}
	void pop()
	{
		int x=st[top--];
		siz[fa[x]]-=siz[x];
		fa[x]=x,d[x]=0;
	}
}d[55];
struct Query{int id,col,pos,nxt;}q[N];
int u[N],v[N],col[N];
vector<int>a[N];
bool ans[N];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
vector<piir>t[N*4];
void add(int w,int l,int r,int ql,int qr,piir x)
{
	if (ql>qr) return;
	if (ql<=l&&r<=qr) return t[w].push_back(x),void();
	if (ql<=mid) add(ls,l,mid,ql,qr,x);
	if (qr>mid) add(rs,mid+1,r,ql,qr,x);
}
void solve(int w,int l,int r)
{
	vector<bool>tmp(t[w].size());
	for (int i=0;i<(int)t[w].size();i++) tmp[i]=d[t[w][i].se].merge(u[t[w][i].fi],v[t[w][i].fi]);
	if (l==r)
	{
		ans[l]=d[q[l].col].check(u[q[l].id],v[q[l].id]);
		if (ans[l]) col[q[l].id]=q[l].col;
		add(1,1,Q,l+1,q[l].nxt-1,mk(q[l].id,col[q[l].id]));
	}
	else solve(ls,l,mid),solve(rs,mid+1,r);
	for (int i=0;i<(int)t[w].size();i++) if (tmp[i]) d[t[w][i].se].pop();
}
#undef mid
#undef rs
#undef ls

signed main()
{
	n=read(),m=read(),k=read(),Q=read();
	for (int i=1;i<=m;i++) u[i]=read(),v[i]=read();
	for (int i=1;i<=Q;i++)
	{
		q[i].id=read(),q[i].col=read();
		q[i].pos=a[q[i].id].size();
		a[q[i].id].push_back(i);
	}
	for (int i=1;i<=m;i++) a[i].push_back(Q+1);
	for (int i=1;i<=Q;i++) q[i].nxt=a[q[i].id][q[i].pos+1];
	for (int i=1;i<=k;i++) d[i].send(n);
	solve(1,1,Q);
	for (int i=1;i<=Q;i++) puts(ans[i]?"YES":"NO");
	
	return 0;
}
/*
3 3 1 3
1 2
2 3
3 1
1 1
2 1
3 1

*/