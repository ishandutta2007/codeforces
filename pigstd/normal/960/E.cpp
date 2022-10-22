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

const int Mod=1e9+7;
const int M=2e5+10; 
int n,val[M],ans[M],res,f[M][2],de[M],sz[M];
vector<int>e[M];

void dfs1(int u,int fa)
{
	f[u][0]=1,de[u]=de[fa]^1,sz[u]=1;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs1(to,u),sz[u]+=sz[to];
		f[u][0]+=f[to][1],f[u][1]+=f[to][0];
	}
}

void dfs2(int u,int fa)
{
	ans[u]=(ans[u]+sz[u]*(f[1][de[u]^1]-f[u][0]-f[1][de[u]]+f[u][1]+1+2*Mod))%Mod;
//	cout<<u<<"qwq"<<ans[u]<<endl;
	ans[u]=(ans[u]+(n-sz[u]))%Mod;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (to==fa)continue;
		dfs2(to,u);
		ans[u]=(ans[u]+(f[to][1]-f[to][0]+Mod)*(n-sz[to]))%Mod;
	}
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)val[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0),dfs2(1,0);
	for (int i=1;i<=n;i++)
		res=(res+ans[i]*(val[i]+Mod))%Mod;
	cout<<res<<endl;
	return 0;
}