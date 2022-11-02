#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int>>> G(n+n+5);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		G[u].emplace_back(v,w);
		G[v+n].emplace_back(u+n,w);
	}
	for(int i=1;i<=n;i++)
	{
		G[i].emplace_back(i+n,0);
	}
	vector<long long> dis(n+n+5,1e18);
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	pq.emplace(0,1);
	dis[1]=0;
	while(not pq.empty())
	{
		auto [d,u]=pq.top();pq.pop();
		if(dis[u]!=d)continue;
		for(auto [v,w]:G[u])
		{
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				pq.emplace(dis[v],v);
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		cout<<(dis[i+n]==1e18?-1:dis[i+n])<<' ';
	}
	return 0;
}