#include<bits/stdc++.h>
#define int long long
#define pb push_back
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
int n,fa[M],f[M],g[M];
vector<int>v[M],pre[M],suf[M],son[M];

void dfs1(int u,int fa)
{
	f[u]=1,pre[u].pb(1),suf[u].pb(1);
	for (int i=0;i<v[u].size();i++)
	{
		int to=v[u][i];if (to==fa)continue;
		dfs1(to,u),f[u]=f[u]*(f[to]+1)%Mod;
		son[u].pb(to);pre[u].pb(f[to]+1),suf[u].pb(f[to]+1);
	}pre[u].pb(1),suf[u].pb(1);
//	cout<<pre[u].size()<<' '<<suf[u].size()<<' '<<son[u].size()<<endl; 
	for (int i=1;i<=son[u].size();i++)
		pre[u][i]=pre[u][i-1]*(f[son[u][i-1]]+1)%Mod;
	for (int i=son[u].size();i>=1;i--)
		suf[u][i]=suf[u][i+1]*(f[son[u][i-1]]+1)%Mod;
	suf[u][0]=suf[u][1],pre[u][son[u].size()+1]=pre[u][son[u].size()];
}

void dfs2(int u)
{
	for (int i=0;i<son[u].size();i++)
	{
		int to=son[u][i];
		g[to]=(g[u]*suf[u][i+2]%Mod*pre[u][i]+1)%Mod;
		dfs2(to);
	}
}

signed main()
{
	n=read();
	for (int i=2;i<=n;i++)
		fa[i]=read(),
		v[fa[i]].pb(i),v[i].pb(fa[i]);
	dfs1(1,0);g[1]=1;dfs2(1);
	for (int i=1;i<=n;i++)
		cout<<g[i]*f[i]%Mod<<' ';
	return 0;
}