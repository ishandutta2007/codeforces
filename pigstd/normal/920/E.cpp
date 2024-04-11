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

const int M=2e5+10;
int out[M],f[M],vis[M],sz[M],n,m,ans[M],cnt;
vector<int>e[M],v;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)f[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		out[u]++,out[v]++;
		e[u].pb(v),e[v].pb(u);
	}
	int minp=1;
	for (int i=2;i<=n;i++)
		if (out[i]<out[minp])minp=i;
	for (int i=0;i<e[minp].size();i++)
	{
		int to=e[minp][i];
		v.pb(to);vis[to]=1;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])f[find(i)]=find(minp);
	for (int i=0;i<v.size();i++)
	{
		memset(vis,0,sizeof(vis));
		for (int j=0;j<e[v[i]].size();j++)
		{
			int to=e[v[i]][j];
			vis[to]=1;
		}
		for (int j=1;j<=n;j++)
			if (!vis[j])f[find(j)]=find(v[i]);
	}
	for (int i=1;i<=n;i++)
		sz[find(i)]++;
	for (int i=1;i<=n;i++)
		if (sz[i])ans[++cnt]=sz[i];
	sort(ans+1,ans+1+cnt);
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++)
		cout<<ans[i]<<' ';
	return 0;
}