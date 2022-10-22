#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,m,f[M],g[M],ff[M],Fa[M],size[M],p[M];
vector<pair<int,int> >e[M];

void add(int u,int x)
{
	g[u]=max(g[u],x);
	if (g[u]>f[u])swap(g[u],f[u]);
}

void dfs1(int u,int fa)
{
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;if (to==fa)continue;
		dfs1(to,u);add(u,f[to]+w);
	}
}

void dfs2(int u,int fa)
{
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x,w=e[u][i].y;if (to==fa)continue;
		add(to,w+((w+f[to])==f[u]?g[u]:f[u]));dfs2(to,u);
	}
}

bool cmp(int a,int b)
{
	return f[a]<f[b];
}

void dfs3(int u,int fa)
{
	Fa[u]=fa;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i].x;
		if (to==fa)continue;
		dfs3(to,u);
	}
}

int find(int x){return ff[x]==x?x:ff[x]=find(ff[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y)return;
	ff[y]=x,size[x]+=size[y],size[y]=0;
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),to=read(),w=read();
		e[to].pb(mp(u,w)),e[u].pb(mp(to,w));
	}
	dfs1(1,0),dfs2(1,0);
	for (int i=1;i<=n;i++)p[i]=i;
	sort(p+1,p+1+n,cmp);
	dfs3(p[1],p[1]);
	m=read();
	while(m--)
	{
		int l=read();int ans=0;
		for (int i=1;i<=n;i++)size[i]=1,ff[i]=i;
		for (int i=n,now=n;i>=1;i--)
		{
			while(f[p[now]]-f[p[i]]>l&&now>=1)size[find(p[now])]--,now--;
			ans=max(ans,size[find(p[i])]);
			merge(p[i],Fa[p[i]]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
5
1 2 3
2 3 4
4 5 3
3 4 2
4
2 3 4 5
*/