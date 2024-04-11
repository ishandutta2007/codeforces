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

const int M=3e5+10;
int n,m,f[M],c[M],vis[M];
vector<int>e[M];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void dfs(int u,int fa)
{
	vis[u]=1;
	if (c[u]==0)
	{
		c[u]=1;
		for (int i=0;i<e[u].size();i++)
		{
			int to=e[u][i];
			if (c[to])continue;
			c[to]=2;
		}
	}
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];if (vis[to])continue;
		dfs(to,u);
	}
}

signed main()
{
	WT
	{
		n=read(),m=read();
		for (int i=1;i<=n;i++)f[i]=i,e[i].clear(),c[i]=vis[i]=0;
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			e[u].pb(v),e[v].pb(u);
			f[find(u)]=find(v);
		}int fl=0;
		for (int i=2;i<=n;i++)
			if (find(i)!=find(i-1))fl=1;
		if (fl){puts("NO");continue;}
		puts("YES");dfs(1,0);int sum=0;
		for (int i=1;i<=n;i++)sum+=c[i]==1;
		cout<<sum<<endl;
		for (int i=1;i<=n;i++)
			if (c[i]&1)cout<<i<<' ';
		puts("");
	}
	return 0;
}