#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=50100;
int n,k,f[M][M/100],ans;

struct egde{int to,next;}e[M*2];int cnt,head[M];
inline void add(int u,int to)
{e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}

void dfs(int u,int fa)
{
	f[u][0]=1;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)
		{
			dfs(e[i].to,u);
			for (int j=1;j<=k;j++)
				ans+=(f[u][j-1]*f[e[i].to][k-j]);
			for (int j=1;j<=k;j++)
				f[u][j]+=f[e[i].to][j-1];
		}
}

signed main()
{
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%lld%lld",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}