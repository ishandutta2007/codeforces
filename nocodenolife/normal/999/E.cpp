#include <bits/stdc++.h>
using namespace std;

/**************TEMPLATE****************************************/
#define ll long long
#define F first
#define S second
#define mod 1000000007
#define ln length()
#define pb push_back
#define input(a,n)      for(long long int c=0;c<n;cin>>a[c++]);
#define out(a,n)      for(long long int c=0;c<n;cout<<a[c++]<<" ");
// // #define output(vec,x)   for(long long int c=0;c<a.size();x<<a[c++]<<',');x<<endl;
/**************************************************************/

ll fact(ll num)
{
	ll x=1;
	for (int i = 1; i <= num; ++i)
	{
		x=x*i;
	}
	return x;
}

ll visited[5005]={0};
ll parent[5005] = {0};
ll cycle[5005]={0};
vector<ll> g[5005];
// ll par[250001];
std::vector<ll> vis;
ll viscount=0;

void dfs(ll x, ll start)
{
	// cout<<x<<" "<<ans<<endl;
	visited[x]=1;
	for (ll i = 0; i < g[x].size() ; ++i)
	{
		if(visited[g[x][i]]==0)
		{
			// par[g[x][i]]=x;
			parent[g[x][i]] = x;
			dfs(g[x][i], start);
		}
		else
		{
		    if(g[x][i]==start)
		    {
		        int par =x;
		        while(par!=start)
		        {
		            cycle[par]=start;
		            par = parent[par];
		        }
		    }
			for (int j = 0; j < vis.size(); ++j)
			{
			    int check = cycle[g[x][i]];
				if(vis[j]==check)
				{
					viscount--;
					vis.erase(vis.begin()+j);
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	ll n,i,j,m,x,k,l,y,r,z,sum=0,digits=0,count=0,total;
	ll t;
	ll minm=1000005,maxm=0;
	
	cin>>n>>m>>k;

	for (ll i = 0; i < m; ++i)
	{
		cin>>x>>y;
		g[x].pb(y);
	}

	dfs(k,k);

	for (int i = 1; i <= n; ++i)
	{
		if(visited[i]==0){
			dfs(i, i);
			cycle[i]=i;
			vis.pb(i);
			viscount++;
		}
// 		for(int j=0;j<n;j++)
// 		{
// 		    cout<<cycle[j]<<" ";
// 		}
// 		cout<<endl;
// 		for(int j=0;j<n;j++)
// 		{
// 		    cout<<parent[j]<<" ";
// 		}
// 		cout<<endl;
	}
	cout<<viscount<<endl;
	return 0;
}