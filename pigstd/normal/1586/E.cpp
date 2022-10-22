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

const int M=3e5+10;
int cnt[M],f[M],ff[M],de[M],u[M],v[M],n,m,q;
int v1[M],v2[M];
vector<int>e[M];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void dfs(int u,int fa)
{
	ff[u]=fa,de[u]=de[fa]+1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to!=fa)dfs(to,u);
	}
}

int LCA(int u,int v)
{
	if (de[u]<de[v])swap(u,v);
	while(de[u]!=de[v])u=ff[u];
	while(u!=v)u=ff[u],v=ff[v];
	return v;
}

void work(int u,int v)
{
	int f=1,cnt1=0,cnt2=0;
	if (de[u]<de[v])swap(u,v),f=-1;
	int lca=LCA(u,v);
	while(u!=lca)v1[++cnt1]=u,u=ff[u];
	while(v!=lca)v2[++cnt2]=v,v=ff[v];
	v2[++cnt2]=lca;
	for (int i=cnt2;i>=1;i--)v1[++cnt1]=v2[i];
	cout<<cnt1<<endl;
	if (f==-1)for (int i=cnt1;i>=1;i--)cout<<v1[i]<<' ';
	else for (int i=1;i<=cnt1;i++)cout<<v1[i]<<' ';puts("");
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)f[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (find(u)!=find(v))
			f[find(u)]=find(v),e[u].pb(v),e[v].pb(u);
	}dfs(1,0);
	q=read();
	for (int i=1;i<=q;i++)
		u[i]=read(),v[i]=read(),cnt[u[i]]++,cnt[v[i]]++;
	int res=0;
	for (int i=1;i<=n;i++)
		res+=cnt[i]&1;
	if (res!=0)
	{
		NO cout<<res/2<<endl;
		return 0;
	}YES
	for (int i=1;i<=q;i++)work(u[i],v[i]);
	return 0;
}