#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int M=2e5+10;
int n,dis[M],vis[M],ff[M],ans,s,t,w;
vector<int>e[M];

void dfs(int u,int fa)
{
	if (fa==0)dis[u]=0;ff[u]=fa;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to==fa||vis[to])continue;
		dis[to]=dis[u]+1;dfs(to,u);
	}
}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
		if (dis[i]>dis[s])s=i;
	dfs(s,0);
	for (int i=1;i<=n;i++)
		if (dis[i]>dis[t])t=i;
	ans=dis[t];
	int p=t;while(p!=s)
	{
		vis[p]=1;
		p=ff[p];
	}vis[s]=1;w=1;
	while (w==s||w==t)w++;
	for (int i=1;i<=n;i++)
		if (vis[i])dfs(i,0);
	for (int i=1;i<=n;i++)
		if (dis[i]>dis[w])w=i;
	ans+=dis[w];
	cout<<ans<<endl<<s<<' '<<t<<' '<<w<<endl;
	return 0;
}
/*

*/