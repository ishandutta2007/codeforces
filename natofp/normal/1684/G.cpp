#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

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

ll n, m;
const int nax = 2e4 + 5;
ll a[nax];
bool gone[nax];

void solve(){
    Hopcroft_Karp es(1005);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    int big = 0;
    for(int i=1;i<=n;i++){
        if(a[i] * 3 > m){
            big++;
            ll low = a[i] + 1;
            ll high = m - a[i];
            low -= a[i];
            high -= a[i];
            for(int j=1;j<=n;j++){
                if(a[i] % a[j] == 0 && a[j] >= low && a[j] <= high){
                    es.addEdge(i, j);
                }
            }
        }
    }

    int f = es.max_matching();
    if(f != big){
        cout << -1 << "\n";
        return;
    }
    vector<pll> ans;
    for(int i=1;i<=n;i++){
        if(es.matchL[i] != 0){
            ll from = a[i];
            ll to = a[es.matchL[i]];
            to += from;
            from += to;
            ans.pb(mp(from, to));
            gone[i] = true;
            gone[es.matchL[i]] = true;
        }
    }
    for(int i=1;i<=n;i++){
        if(!gone[i]) ans.pb(mp(a[i] * 3, a[i] * 2));
    }
    cout << ans.size() << "\n";
    for(auto cur : ans) cout << cur.st << " " << cur.nd << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}