#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn=300005;
typedef long long LL;
struct edge{
	int to,val,id;
};
bool cmp(edge a,edge b)
{
	return a.val<b.val;
}
vector<edge> g[maxn];
LL dist[maxn];
int vv[maxn];
void dijkstra(int s)
{
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > >pq;
	pq.push(mp(0,s));
	dist[s]=0;
	while(!pq.empty())
	{
		int x=pq.top().ss;
		LL d=pq.top().ff;
		pq.pop();
		if(dist[x]>d)continue;
		for(int i=0;i<g[x].size();i++)
		{
			if(dist[g[x][i].to]==-1||dist[g[x][i].to]>d+g[x][i].val)
			{
				dist[g[x][i].to]=d+g[x][i].val;
				pq.push(mp(dist[g[x][i].to],g[x][i].to));
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].pb(edge{y,z,i});
		g[y].pb(edge{x,z,i});
		vv[i]=z;
	}
	int u;
	scanf("%d",&u);
	dijkstra(u);
	LL a=0;
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		if(dist[i]<1)continue;
		int mx=0;
		for(int j=0;j<g[i].size();j++)if((dist[g[i][j].to]+g[i][j].val==dist[i])&&(mx==0||vv[mx]>g[i][j].val))
			mx=g[i][j].id;
		ans.pb(mx);
		a+=vv[mx];
	}
	sort(ans.begin(),ans.end());
	cout<<a<<endl;
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
	return 0;
}