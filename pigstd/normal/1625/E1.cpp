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

const int M=3e5+10;
int n,q,tot,dp[M],L[M],R[M],cnt,tt[M];
int sz[M],top[M],fa[M],dfn[M],ti;
vector<int>e[M];
pii p[M];
char s[M];

struct segment_tree
{
	struct tree{int tl,tr,val,tag;};
	vector<tree>t;
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define len(x) (r(x)-l(x)+1)
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k){val(k)=val(lson)+val(rson);}
	void pushdown(int k){val(lson)+=tag(k)*len(lson),val(rson)+=tag(k)*len(rson);tag(lson)+=tag(k),tag(rson)+=tag(k);tag(k)=0;}
	void build(int k,int l,int r)
	{
		if (k==1)t.resize(r*4+1);
		l(k)=l,r(k)=r;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r){val(k)+=z*len(k),tag(k)+=z;return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T1,T2,TT[M];

void dfs(int u)
{
	sz[u]=1;dfn[u]=++ti;int sum=0;tt[u]=e[u].size();
	if (tt[u])cnt++;
	int now=0,K=cnt;
	if (tt[u])
		TT[K].build(1,1,tt[u]);
	for (auto to:e[u])
	{
		dfs(to);
		p[to]=mp(K,++now);
		sz[u]+=sz[to];dp[u]+=dp[to];
		sum+=dp[to];
		T2.update(1,dfn[to],dfn[to],sum); 
		TT[K].update(1,now,now,1);
	}dp[u]+=1+(tt[u]-1)*tt[u]/2;
}

int Get(int x){return T2.query(1,dfn[x],dfn[x])+T1.query(1,dfn[x],sz[x]+dfn[x]-1);}
int GetP(int x){return dp[x]+T1.query(1,dfn[x],sz[x]+dfn[x]-1);}
void del(int x)
{
	TT[p[x].x].update(1,p[x].y,p[x].y,-1);
	int f=fa[x],G2=GetP(x),tmp=G2+tt[f]-1;tt[f]--;
//	cout<<tmp<<endl;
	T2.update(1,dfn[x]+1,n,-tmp),T1.update(1,dfn[x],dfn[x],-tmp); 
}
int query(int l,int r)
{
//	cout<<Get(r)<<' '<<Get(l)<<' ';
	int res=Get(r)-Get(l)+GetP(l),tmp=TT[p[r].x].query(1,p[l].y,p[r].y);
//	cout<<res<<' '<<tmp<<' ';
	return res+(tmp-1)*tmp/2;
}

signed main()
{
	n=read(),q=read();int now=0;
	scanf("%s",s+1);
	T1.build(1,1,n),T2.build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='(')tot++,fa[tot]=now,e[now].pb(tot),now=tot,L[i]=tot;
		else R[i]=now,now=fa[now];
	}
	dfs(0);
	while(q--)
	{
		int opt=read(),l=read(),r=read();
		if (opt==1)del(L[l]);
		else printf("%lld\n",query(L[l],R[r]));
	}
	return 0;
}
/*
8 3
()(())()
1 1 2
1 4 5
2 3 8

*/