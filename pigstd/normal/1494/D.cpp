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

const int inf=1e18;
const int M=1010;
int d[M][M],vis[M][M],fl[M],n,cnt,sum,a[M],f[M];
pair<int,int>ans[M];
vector<int>v,e[M];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void dfs(int u)
{
	fl[u]=0,v.pb(u);
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (!fl[to])continue;
		dfs(to);
	}
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)d[i][j]=read();
	cnt=n;for (int i=1;i<=n;i++)
		a[i]=d[i][i],f[i]=i,vis[i][i]=1;
	while(1)
	{
		int minn=inf;
		for (int i=1;i<=cnt;i++)fl[i]=0;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (!vis[i][j])minn=min(minn,d[i][j]);
		if (minn==inf)break;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (d[i][j]==minn)
				{
					vis[i][j]=1;fl[find(i)]=fl[find(j)]=1;
					e[find(i)].pb(find(j)),e[find(j)].pb(find(i));
				}int C=cnt;
		for (int i=1;i<=C;i++)
			if (fl[i])
			{
				a[++cnt]=minn;f[cnt]=cnt;
				v.clear();dfs(i);
				for (int j=0;j<v.size();j++)
					ans[++sum]=mp(v[j],cnt),f[v[j]]=cnt;
			}
	}
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++)cout<<a[i]<<' ';puts("");
	cout<<cnt<<endl;
	for (int i=1;i<=sum;i++)
		cout<<ans[i].x<<' '<<ans[i].y<<endl;
	return 0;
}