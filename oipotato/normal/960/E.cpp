#include<cstdio>
#include<vector>
using namespace std;
const int MOD=1E9+7;
int f[200010],ans;
int size[200010],a[200010],n;
vector<int> g[200010];
void dfs(int p,int fa)
{
	size[p]=1;
	f[p]=0;
	for(auto i:g[p])
	{
		if(i!=fa)
		{
			dfs(i,p);
			f[p]=(f[p]-f[i]+MOD)%MOD;
			size[p]+=size[i];
		}
	}
	f[p]=(f[p]+1ll*size[p]*a[p])%MOD;
}
void work(int p,int fa,int ff)
{
	f[p]=(f[p]-ff+1ll*(n-size[p])*a[p]+MOD)%MOD;
	ans=(ans+f[p])%MOD;
	for(auto i:g[p])
	{
		if(i!=fa)work(i,p,(f[p]+f[i]-1ll*size[i]*a[p]%MOD+MOD)%MOD);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=(MOD+a[i])%MOD;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	work(1,0,0);
	printf("%d\n",ans);
	return 0;
}