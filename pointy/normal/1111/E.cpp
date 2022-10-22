// Author: Little09
// Problem: CF1111E Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1111E
// Memory Limit: 250 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) (x&(-x))
const ll mod=1e9+7;
int n,q;
const int N=2e5+5,M=305;
int h[N],cnt,nxt[N],t[N];
int dp[N/2][M];
void addedge(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
int dfn[N],siz[N],rk[N];
int fa[N][21],deth[N];
int tot;
int d[N];
struct point
{
	int b,c;
}b[N];
void dfs(int x,int f)
{
	dfn[x]=++tot,rk[tot]=x,siz[x]=1;
	deth[x]=deth[f]+1;
	fa[x][0]=f;
	for (int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==f) continue;
		dfs(t[i],x);
		siz[x]+=siz[t[i]];
	}
}
int LCA(int x,int y)
{
	if (deth[x]<deth[y]) swap(x,y);
	for (int i=20;i>=0;i--) if (deth[fa[x][i]]>=deth[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int tree[N];
void add(int x,int k)
{
	for (;x<=n;x+=lowbit(x)) tree[x]+=k;
}
int ask(int x)
{
	int res=0;
	for (;x;x-=lowbit(x)) res+=tree[x];
	return res;
}

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}

bool cmp(point x,point y)
{
	return x.c<y.c;
}

int work(int k,int m,int r)
{
	for (int i=1;i<=k;i++) b[i].b=read(),d[b[i].b]++;
	for (int i=1;i<=k;i++)
	{
		add(dfn[b[i].b],1);
		add(dfn[b[i].b]+siz[b[i].b],-1);
	}
	for (int i=1;i<=k;i++) 
	{
		int lca=LCA(b[i].b,r);
		b[i].c=ask(dfn[b[i].b])+ask(dfn[r]);
		b[i].c-=ask(dfn[lca])*2;
		b[i].c+=d[lca];
		b[i].c--;
	}
	sort(b+1,b+k+1,cmp);
	dp[1][1]=1;
	for (int i=2;i<=k;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (j<b[i].c) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=(dp[i-1][j-1]+1ll*dp[i-1][j]*(j-b[i].c)%mod)%mod;
		}
	}
	int ans=0;
	for (int i=1;i<=m;i++) ans=(ans+dp[k][i])%mod;
	for (int i=1;i<=k;i++)
	{
		add(dfn[b[i].b],-1);
		add(dfn[b[i].b]+siz[b[i].b],1);
		d[b[i].b]--;
	}
	return ans;
}

int main()
{
	n=read(),q=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y),addedge(y,x);
	}
	dfs(1,0);
	while (q--)
	{
		int k=read(),m=read(),r=read();
		printf("%d\n",work(k,m,r));
	}
	return 0;
}