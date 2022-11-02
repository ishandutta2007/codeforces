#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int f[100010][110],a[100010],n,m,s,k;
queue<pair<int,int>> q;
vector<int> g[100010];
bool vis[100010][110];
void work()
{
	for(int i=1;i<=n;i++)
	{
		f[i][a[i]]=0;
		vis[i][a[i]]=1;
		q.push({i,a[i]});
	}
	for(;!q.empty();)
	{
		auto u=q.front();q.pop();
		for(auto i:g[u.first])
		if(!vis[i][u.second])
		{
			vis[i][u.second]=1;
			q.push({i,u.second});
			f[i][u.second]=f[u.first][u.second]+1;
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	work();
	for(int i=1;i<=n;i++)
	{
		long long ans=0;
		sort(f[i]+1,f[i]+k+1);
		for(int j=1;j<=s;j++)ans+=f[i][j];
		printf("%lld%c",ans," \n"[i==n]);
	}
	return 0;
}