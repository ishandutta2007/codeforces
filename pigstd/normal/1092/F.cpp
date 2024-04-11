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
int ans,n,a[M],size[M],f[M],ssum;
vector<int>v[M];

void dfs1(int u,int fa,int dis)
{
	f[1]+=dis*a[u],size[u]=a[u];
	for (int i=0;i<v[u].size();i++)
	{
		int to=v[u][i];
		if (to==fa)continue;
		dfs1(to,u,dis+1),size[u]+=size[to];
	}
}

void dfs2(int u,int fa)
{
	for (int i=0;i<v[u].size();i++)
	{
		int to=v[u][i];
		if (to==fa)continue;
		f[to]=f[u]-size[to]+(ssum-size[to]);
		dfs2(to,u);
	}
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read(),ssum+=a[i];
	for (int i=1;i<n;i++)
	{
		int u=read(),to=read();
		v[u].pb(to),v[to].pb(u);
	}
	dfs1(1,0,0);dfs2(1,0);
	for (int i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<ans<<endl; 
	return 0;
}