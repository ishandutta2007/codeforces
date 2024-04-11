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
int n,a[M],f[M],prime[M],vis[M],dis[M],ff[M],cnt,ans;
vector<int>e[M],ee[M],v[M],v2;
map<int,int>t;

void dfs(int u,int fa)
{
	v2.pb(u);ff[u]=1;
	for (int i=0;i<ee[u].size();i++)
	{
		int to=ee[u][i];if (to==fa)continue;
		dis[to]=dis[u]+1;dfs(to,u);
	}
}

signed main()
{
	n=read();
	for (int i=2;i<=2e5;i++)
	{
		if (f[i])continue;
		prime[++cnt]=i;t[i]=cnt;
		for (int j=i*i;j<=2e5;j+=i)f[j]=1;
	}
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		for (int j=1;j<=cnt&&prime[j]*prime[j]<=a[i];j++)
			if (a[i]%prime[j]==0)
			{
				while(a[i]%prime[j]==0)a[i]/=prime[j];
				v[j].pb(i);
			}
		if (a[i]!=1)v[t[a[i]]].pb(i);
	}
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	for (int i=1;i<=cnt;i++)
	{
		if (v[i].size()<=ans)continue;
		for (int j=1;j<=n;j++)ee[j].clear(),dis[j]=0,vis[j]=0,ff[j]=0;
		for (int j=0;j<v[i].size();j++)vis[v[i][j]]=1;
		for (int j=0;j<v[i].size();j++)
			for (int k=0;k<e[v[i][j]].size();k++)
				if (vis[e[v[i][j]][k]])ee[v[i][j]].pb(e[v[i][j]][k]);
		for (int j=0;j<v[i].size();j++)
		{
			int u=v[i][j];if (ff[u])continue;
			v2.clear(),dfs(u,0);int s=u;
			for (int i=0;i<v2.size();i++)
				if (dis[v2[i]]>dis[s])s=v2[i];
			dis[s]=0;v2.clear(),dfs(s,0);int maxn=0;
			for (int i=0;i<v2.size();i++)
				maxn=max(dis[v2[i]],maxn);
			ans=max(ans,maxn+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}