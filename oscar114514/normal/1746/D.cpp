#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		vector<vector<int>> G(n+5);
		for(int i=2;i<=n;i++)
		{
			int p;
			cin>>p;
			G[p].push_back(i);
		}
		vector<long long> s(n+5),ex(n+5);
		for(int i=1;i<=n;i++)
			cin>>s[i];
		vector<long long> del(n+5);
		long long ans=0;
		vector<long long> c(n+5);
		c[1]=k;
		ans+=c[1]*s[1];
		function<void(int)> dfs=[&](int u)
		{
//			cerr<<"dfs "<<u<<endl;
			int sz=G[u].size();
			if(sz==0)
			{
				ex[u]=s[u];
				return;
			}
			int r=c[u]%sz;
			vector<long long> tmp;
			for(auto v:G[u])
			{
				c[v]=c[u]/sz;
				ans+=c[v]*s[v];
				dfs(v);
				tmp.push_back(ex[v]);
			}
			sort(tmp.begin(),tmp.end(),greater<long long>());
			for(int i=0;i<r;i++)
			{
//				cerr<<"add "<<u<<' '<<tmp[i]<<endl;
				ans+=tmp[i];
			}
			ex[u]=tmp[r]+s[u];
		};
		dfs(1);
		cout<<ans<<"\n";
	}
	
	return 0;
}