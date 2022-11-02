#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
long long f[300010],ans;
vector<pair<int,int>>g[300010];
int n,w[300010];
void dfs(int p,int fa)
{
	ans=max(ans,1ll*w[p]);
	f[p]=w[p];
	for(auto i:g[p])
	if(i.first!=fa)
	{
		dfs(i.first,p);
		ans=max(ans,f[p]+f[i.first]-i.second);
		f[p]=max(f[p],f[i.first]-i.second+w[p]);
	}
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&w[i]);
	rep(i,n-1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}