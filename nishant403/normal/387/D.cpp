#include <bits/stdc++.h>
using namespace std;
  
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

//1 indexed Hopcroft-Karp Matching in O(E sqrtV)

struct Hopcroft_Karp
{
	static const int inf = 1e9;

	int n;
	vector<int> matchL, matchR, dist;
	vector<vector<int> > g;

	Hopcroft_Karp(int n) :
		n(n), matchL(n+1), matchR(n+1), dist(n+1), g(n+1) {}

	void addEdge(int u, int v)
	{
		g[u].push_back(v);
	}

	bool bfs()
	{
		queue<int> q;
		for(int u=1;u<=n;u++)
		{
			if(!matchL[u])
			{
				dist[u]=0;
				q.push(u);
			}
			else
				dist[u]=inf;
		}
		dist[0]=inf;

		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:g[u])
			{
				if(dist[matchR[v]] == inf)
				{
					dist[matchR[v]] = dist[u] + 1;
					q.push(matchR[v]);
				}
			}
		}

		return (dist[0]!=inf);
	}

	bool dfs(int u)
	{
		if(!u)
			return true;
		for(auto v:g[u])
		{
			if(dist[matchR[v]] == dist[u]+1 &&dfs(matchR[v]))
			{
				matchL[u]=v;
				matchR[v]=u;
				return true;
			}
		}
		dist[u]=inf;
		return false;
	}

	int max_matching()
	{
		int matching=0;
		while(bfs())
		{
			for(int u=1;u<=n;u++)
			{
				if(!matchL[u])
					if(dfs(u))
						matching++;
			}
		}
		return matching;
	}
};

const int N = 504;
int g[N][N];
pii ed[N+N];

signed main()
{
    fast;
    
    int n,m;
    cin >> n >> m;
    
    f(i,m)
    {
        cin >> ed[i].F >> ed[i].S;
        g[ed[i].F][ed[i].S] = 1;
    }
    
    int res = (N*N);
    
    for(int i=1;i<=n;i++)
    {
        int ans = 0;
        
        for(int j=1;j<=n;j++) ans+=(1 - g[i][j]);
        for(int j=1;j<=n;j++) ans+=(1 - g[j][i]);
        ans-=1 - g[i][i];
        
        Hopcroft_Karp go(n+n);
        
        int cnt = 0;
        
        f(j,m) if(ed[j].F != i && ed[j].S != i) go.addEdge(ed[j].F,ed[j].S),cnt++;
        
        int no_delete = go.max_matching();    
        
        ans+=cnt - no_delete;
        
        int to_add = (n-1) - no_delete;
        
        ans+=to_add;
        
        res = min(res,ans);
    }
    
    cout << res;
}