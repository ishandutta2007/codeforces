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

const int M=2e5+10;
int n,m,fa[M],dfn[M],ti,a[M],sz[M],c[M],u[M],v[M],ff[25][M],dep[M];
vector<int>e[M];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void dfs(int u,int fa=0)
{
	dfn[u]=++ti,sz[u]=1,dep[u]=dep[fa]+1,ff[0][u]=fa;
	for (auto x:e[u])
		if (x!=fa)dfs(x,u),sz[u]+=sz[x];
}

void upd(pii x,int k){a[x.x]+=k,a[x.y+1]-=k;}

void init()
{
	for (int i=1;i<=20;i++)
		for (int j=1;j<=n;j++)
			ff[i][j]=ff[i-1][ff[i-1][j]];
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
		if (find(u[i])!=find(v[i]))fa[find(u[i])]=find(v[i]),e[u[i]].pb(v[i]),e[v[i]].pb(u[i]);
		else c[i]=1;
	}
	dfs(1);init();
	for (int i=1;i<=m;i++)
		if (c[i]==1)
		{
			pii x=mp(dfn[u[i]],dfn[u[i]]+sz[u[i]]-1),y=mp(dfn[v[i]],dfn[v[i]]+sz[v[i]]-1);
			if (x>y)swap(x,y),swap(u[i],v[i]);
			if (x.y>=y.y)
			{
				int qwq=v[i];
				for (int j=20;j>=0;j--)
					if (dep[ff[j][qwq]]>dep[u[i]])qwq=ff[j][qwq];
				x=mp(dfn[qwq],dfn[qwq]+sz[qwq]-1);
				upd(x,1),upd(y,-1);
			}
			else upd(mp(1,n),1),upd(x,-1),upd(y,-1);
		}
	for (int i=1;i<=n;i++)a[i]+=a[i-1];
	for (int i=1;i<=n;i++)
		if (a[dfn[i]])cout<<0;
		else cout<<1;
	return 0;
}