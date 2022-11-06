#include<bits/stdc++.h>
using namespace std;
vector<int> G[233333];
int col[233333],deg[233333];
void dfs(int u,int c)
{
	col[u]=c;
	for(auto v:G[u])
	{
		if(!col[v])
		{
			dfs(v,3-c);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)G[i].clear();
		memset(col,0,sizeof(int)*(n+5));
		memset(deg,0,sizeof(int)*(n+5));
		int u,v;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			deg[u]++;
			deg[v]++;
		}
		dfs(1,1);
		for(int i=1;i<=n;i++)
		{
			if(col[i]==2)deg[i]*=-1;
			cout<<deg[i]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}