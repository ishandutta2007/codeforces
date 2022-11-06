#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<int>> G(n+5,vector<int>(n+5,0x3f3f3f3f));
		for(int i=1;i<=n;i++)G[i][i]=0;
		vector<tuple<int,int,int>> eg;
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			G[u][v]=G[v][u]=min(G[u][v],1);
			eg.emplace_back(u,v,w);
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
		long long ans=0x3f3f3f3f3f3f3f3fll;
		for(auto [u,v,w]:eg)
		{
			ans=min(ans,1ll*(G[1][u]+G[v][n]+1)*w);
			ans=min(ans,1ll*(G[1][v]+G[u][n]+1)*w);
			for(int i=1;i<=n;i++)
			{
//				cerr<<"? "<<u<<' '<<v<<' '<<i<<' '<<G[1][i]+G[i][n]+G[i][u]+2<<' '<<w<<endl;
//				cerr<<"? "<<u<<' '<<v<<' '<<i<<' '<<G[1][i]+G[i][n]+G[i][v]+2<<' '<<w<<endl;
				ans=min(ans,1ll*(G[1][i]+G[i][n]+G[i][u]+2)*w);
				ans=min(ans,1ll*(G[1][i]+G[i][n]+G[i][v]+2)*w);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}