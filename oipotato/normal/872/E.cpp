#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MOD=1E9+7;
int ans,n,edgenum,pnum,x[100010],y[100010],a[100010],b[100010];
bool vis[200010];
vector<int> g[200010];
queue<int> q;
void add(int x,int y){g[x].push_back(y);}
void BFS(int x)
{
	for(;!q.empty();)
	{
		q.pop();
	}
	q.push(x);
	vis[x]=1;
	edgenum=0;
	pnum=1;
	for(;!q.empty();)
	{
		int u=q.front();
		q.pop();
		int cnt=g[u].size();
		edgenum+=cnt;
		for(int i=0;i<cnt;i++)
		{
			if(!vis[g[u][i]])
			{
				vis[g[u][i]]=1;
				pnum++;
				q.push(g[u][i]);
			}
		}
	}
	int tans=1;
	for(int i=1;i<=pnum;i++)
	{
		tans=2ll*tans%MOD;
	}
	if(edgenum/2<pnum)
	{
		tans=(tans+MOD-1)%MOD;
	}
	ans=1ll*ans*tans%MOD;
}
int main()
{
	scanf("%d",&n);
	ans=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		a[i]=x[i];
		b[i]=y[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	memset(vis,1,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		x[i]=lower_bound(a+1,a+n+1,x[i])-a;
		y[i]=lower_bound(b+1,b+n+1,y[i])-b;
		add(x[i],y[i]+n);
		add(y[i]+n,x[i]);
		vis[x[i]]=0;
		vis[y[i]+n]=0;
	}
	for(int i=1;i<=2*n;i++)
	{
		if(!vis[i])
		{
			BFS(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}