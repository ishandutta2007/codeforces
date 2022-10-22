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

const int M=1e6+10;
int n,ans[M],buf[M],de[M],son[M];
int *now=buf,*f[M];
vector<int>e[M];

void dfs1(int u,int fa)
{
	for (auto v:e[u])
	{
		if (v==fa)continue;
		dfs1(v,u);
		if (de[v]>de[son[u]])son[u]=v;
	}
	de[u]=de[son[u]]+1;
}

void dfs2(int u,int fa)
{
	f[u][0]=1;
	if (son[u])
	{
		f[son[u]]=f[u]+1;
		dfs2(son[u],u),ans[u]=ans[son[u]]+1;
	}
	for (auto v:e[u])
	{
		if (v==son[u]||v==fa)continue;
		f[v]=now,now+=de[v],dfs2(v,u);
		for (int j=1;j<=de[v];j++)
		{
			f[u][j]+=f[v][j-1];
			if (f[u][j]>f[u][ans[u]]||(f[u][j]==f[u][ans[u]]&&j<ans[u]))
				ans[u]=j;
		}
	}
	if (f[u][ans[u]]==1)ans[u]=0;
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	f[1]=now,now+=de[1];
	dfs2(1,0);
	for (int i=1;i<=n;i++)cout<<ans[i]<<'\n';
	return 0;
}