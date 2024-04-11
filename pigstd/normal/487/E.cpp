#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=2e5+10;
int n,m,q,cnt,dfn[M],ti,low[M],vis[M],st[M],tp,a[M];
int dep[M],son[M],sz[M],top[M],fa[M];
vector<int>e1[M],e[M];
multiset<int>s[M];

int getmin(multiset<int>&s)
{
	if (s.size()==0)return inf;
	else return *s.begin();
}

struct segment_tree
{
	struct tree
	{
		int tl,tr,val;
	}t[M<<2];int ed[M];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,val(k)=inf;
		if (l==r)return ed[l]=k,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void pushup(int k){val(k)=min(val(lson),val(rson));}
	void upd(int k,int w)
	{
		int now=ed[k];val(now)=w;
		while(now!=1)now>>=1,pushup(now);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return inf;
		return min(query(lson,l,r),query(rson,l,r));
	}
}T;

void tarjan(int u)
{
	dfn[u]=low[u]=++ti,vis[u]=1,st[++tp]=u;
	for (auto v:e1[u])
		if (!dfn[v])
		{
			tarjan(v),ckmin(low[u],low[v]);
			if (low[v]==dfn[u])
			{
				++cnt;
				while(1)
				{
					int tmp=st[tp];tp--;
					vis[tmp]=0,e[tmp].pb(cnt),e[cnt].pb(tmp);
					if (tmp==v)break;
				}
				e[cnt].pb(u),e[u].pb(cnt);
			}
		}
		else if (vis[v])ckmin(low[u],dfn[v]);
}

void dfs1(int u,int f=0)
{
	sz[u]=1,dep[u]=dep[f]+1,fa[u]=f;
	for (auto v:e[u])
	{
		if (v==f)continue;
		dfs1(v,u),sz[u]+=sz[v];
		if (sz[v]>sz[son[u]])son[u]=v;
	}
}

void dfs2(int u,int topf)
{
	top[u]=topf,dfn[u]=++ti;
	if (son[u])dfs2(son[u],topf);
	for (auto v:e[u])
	{
		if (v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}

void upd(int x)
{
	if (x==0)return;
	if (x<=n)T.upd(dfn[x],a[x]);
	else T.upd(dfn[x],getmin(s[x]));
}

int query(int x,int y)
{
	int res=inf;
	while(top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]])swap(x,y);
		ckmin(res,T.query(1,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if (dep[x]>dep[y])swap(x,y);
	ckmin(res,T.query(1,dfn[x],dfn[y]));
	if (x>n)ckmin(res,a[fa[x]]);
	return res;
}

signed main()
{
	cnt=n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e1[u].pb(v),e1[v].pb(u);
	}
	tarjan(1);ti=0;
	dfs1(1),dfs2(1,1);
	T.build(1,1,cnt);
	for (int i=1;i<=n;i++)
		upd(i),s[fa[i]].insert(a[i]);
	for (int i=n+1;i<=cnt;i++)upd(i);
	while(q--)
	{
		string S;cin>>S;
		if (S=="C")
		{
			int x=read(),w=read();
			if (fa[x]!=0)s[fa[x]].erase(s[fa[x]].find(a[x])),s[fa[x]].insert(w);
			a[x]=w;upd(x),upd(fa[x]);
		}
		else
		{
			int x=read(),y=read();
			cout<<query(x,y)<<'\n';
		}
	}
	return 0;
}