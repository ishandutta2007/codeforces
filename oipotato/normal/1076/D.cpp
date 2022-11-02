#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=300010;
int n,m,k;
long long d[N];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
vector<pair<int,int>>g[N];
vector<int>ans;
bool v[N],vis[N];
struct EDGE
{
	int x,y,w;
}edge[N];
void dij()
{
	rep(i,n)d[i]=2147483647ll*10000000;
	d[1]=0;
	q.push({d[1],1});
	for(;!q.empty();)
	{
		auto u=q.top();q.pop();
		if(v[u.second])continue;
		//printf("*%d\n",u.second);
		v[u.second]=1;
		for(auto i:g[u.second])
		if(d[i.first]>u.first+i.second)
		{
			d[i.first]=u.first+i.second;
			q.push({d[i.first],i.first});
		}
	}
}
void add(int x,int y,int id)
{
	//printf("%d %d\n",x,y);
	g[x].push_back({y,id});
}
void dfs(int p)
{
	vis[p]=1;
	for(auto i:g[p])if(!vis[i.first]&&k){k--;ans.push_back(i.second);dfs(i.first);}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		g[x].push_back({y,w});
		g[y].push_back({x,w});
		edge[i]={x,y,w};
	}
	dij();
	//rep(i,n)printf("%d\n",d[i]);
	rep(i,n)g[i].clear();
	rep(i,m)if(d[edge[i].x]+edge[i].w==d[edge[i].y])add(edge[i].x,edge[i].y,i);else if(d[edge[i].y]+edge[i].w==d[edge[i].x])add(edge[i].y,edge[i].x,i);
	dfs(1);
	int tmp=ans.size();
	printf("%d\n",tmp);
	rep(i,tmp)printf("%d%c",ans[i-1]," \n"[i==tmp]);
	return 0;
}