//AFO countdown:???
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=5e5+10;
int n,m,q,p[M],b[M],fa[M][25],vis[M];
int dfn[M],sz[M],pp[M],f[M],ti;
pair<int,int>c[M];
vector<int>e[M];
map<int,int>t;
struct node{int u,v,w;}a[M];
bool cmp(node a,node b){return a.w>b.w;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

struct segment_tree
{
	struct tree
	{
		int tl,tr,val;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=max(val(lson),val(rson));}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){val(k)=pp[l];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int x)
	{
		if (l(k)>x||r(k)<x)return;
		if (l(k)==x&&r(k)==x){val(k)=0;return;}
		update(lson,x),update(rson,x);
		pushup(k); 
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		return max(query(lson,l,r),query(rson,l,r));
	}
}T;

void dfs(int u,int ff)
{
	fa[u][0]=ff;dfn[u]=++ti;sz[u]=vis[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		dfs(to,u);sz[u]+=sz[to];
	}
}

void init(int n)
{
	for (int j=1;j<=20;j++)
		for (int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}

signed main()
{
	n=read(),m=read(),q=read();int cnt=0,tot=n;
	for (int i=1;i<=n;i++)p[i]=read(),f[i]=i,b[i]=q+1;
	for (int i=1;i<=m;i++)
		a[i].u=read(),a[i].v=read(),a[i].w=q+1;
	for (int i=1;i<=q;i++)
	{
		int opt=read(),x=read();
		if (opt==1)c[++cnt]=mp(i,x);
		else a[x].w=i;
	}
	sort(a+1,a+1+m,cmp);
	for (int i=1;i<=m;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v); 
		if (fx==fy)continue;b[++tot]=a[i].w;
		f[tot]=f[fx]=f[fy]=tot;e[tot].pb(fx),e[tot].pb(fy);
//		cout<<tot<<' '<<fx<<endl;
//		cout<<tot<<' '<<fy<<endl;
	}//puts("qwq");
	for (int i=tot;i>=1;i--)
		if (!vis[i])dfs(i,0);
	init(tot);
	for (int i=1;i<=n;i++)pp[dfn[i]]=p[i],t[p[i]]=dfn[i];
//	for (int i=1;i<=tot;i++)
//		cout<<b[i]<<' ';puts("");
	T.build(1,1,tot);
	for (int i=1;i<=cnt;i++)
	{
		int x=c[i].x,u=c[i].y;
		for (int i=20;i>=0;i--)
			if (b[fa[u][i]]>x)
				u=fa[u][i];
		int ans=T.query(1,dfn[u],dfn[u]+sz[u]-1);
//		cout<<u<<' ';
		printf("%lld\n",ans);
		T.update(1,t[ans]);
	}
	return 0;
}