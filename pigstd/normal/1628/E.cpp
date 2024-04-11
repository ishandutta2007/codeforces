#include<bits/stdc++.h>
//#define int long long
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

const int M=3e5+10;
int n,f[25][M<<1],q,tot,a[M<<1],fa[M<<1],de[M<<1];
struct edge{int u,v,w;}e[M];
vector<int>E[M<<1];
bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void init()
{
	for (int i=1;i<=20;i++)
		for (int j=1;j<=2*n-1;j++)
			f[i][j]=f[i-1][f[i-1][j]];
}

void dfs(int u){for (auto v:E[u])de[v]=de[u]+1,dfs(v);}

int LCA(int u,int v)
{
	if (de[u]<de[v])swap(u,v);
	for (int i=20;i>=0;i--)
		if (de[f[i][u]]>=de[v])u=f[i][u];
	if (u==v)return u;
	for (int i=20;i>=0;i--)
		if (f[i][u]!=f[i][v])u=f[i][u],v=f[i][v];
	return f[0][u];
}

struct segment_tree
{
	struct tree
	{
		int tl,tr,tag,val,p;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define tag(x) t[(x)].tag
	#define val(x) t[(x)].val
	#define p(x) t[(x)].p
	#define lson k<<1
	#define rson k<<1|1
	void pushdown(int k)
	{
		if (tag(k)==-1)return;
		if (tag(k))
		{
			tag(lson)=tag(rson)=1,
			val(lson)=p(lson),val(rson)=p(rson);
		}
		else val(lson)=tag(lson)=val(rson)=tag(rson)=0;
		tag(k)=-1;
	}
	void build(int k,int l,int r)
	{
		tag(k)=-1,l(k)=l,r(k)=r;
		if (l==r)return p(k)=l,void();
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		p(k)=LCA(p(lson),p(rson));
	}
	int merge(int a,int b)
	{
		if (!a||!b)return a^b;
		return LCA(a,b);
	}
	void update0(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r)return tag(k)=val(k)=0,void();
		pushdown(k);
		update0(lson,l,r),update0(rson,l,r);
		val(k)=merge(val(lson),val(rson)); 
	}
	void update1(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r)return tag(k)=1,val(k)=p(k),void();
		pushdown(k);
		update1(lson,l,r),update1(rson,l,r);
		val(k)=merge(val(lson),val(rson)); 
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return merge(query(lson,l,r),query(rson,l,r));
	}
}T;

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),q=read();
	for (int i=1;i<n;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+n,cmp);tot=n;
	for (int i=1;i<=n;i++)fa[i]=i,a[i]=-1;
	for (int i=1;i<n;i++)
	{
		int U=find(e[i].u),V=find(e[i].v);a[++tot]=e[i].w;
		fa[U]=fa[V]=fa[tot]=tot,E[tot].pb(U),E[tot].pb(V);
		f[0][U]=f[0][V]=tot;
//		cout<<tot<<' '<<U<<' '<<V<<'\n'; 
	}assert(tot==2*n-1);
	de[tot]=1;dfs(tot);init();T.build(1,1,n);
//	cout<<LCA(7,9)<<'\n';
	while(q--)
	{
		int opt=read();
		if (opt==1)
		{
			int l=read(),r=read();
			T.update1(1,l,r);
		}
		if (opt==2)
		{
			int l=read(),r=read();
			T.update0(1,l,r);
		}
		if (opt==3)
		{
			int x=read(),F=T.query(1,x,x);
			if (!F)T.update1(1,x,x);
			int res=T.query(1,1,n);
			cout<<a[res]<<'\n';
//			cout<<res<<"\n";
			if (!F)T.update0(1,x,x);
		}
	}
	return 0;
}
/*
5 4
2 1 2
3 1 4
4 3 5
5 1 5
1 5 5
1 1 4
1 5 5
3 5

*/