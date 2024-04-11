#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

const ll mod = 998244353;

ll a[1002];
int in[1002], ord[1002];
vector<int> adj[1002], inv[1002];
vector<pair<ll, ll>> dp[1002];

void solve()
{
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        in[i] = 0;
        adj[i].clear();
        inv[i].clear();
        dp[i].clear();
        dp[i].push_back({0, a[i]});
    }
    for(int i=1;i<=m;i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        inv[v].push_back(u);
        in[v]++;
    }
    
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i] == 0) q.push(i);
    }
    
    for(int i=1;i<=n;i++)
    {
        int x = q.front(); q.pop();
        ord[i] = x;
        for(int y : adj[x])
        {
            in[y]--;
            if(in[y] == 0) q.push(y);
        }
    }
    
    for(int t=1;t<=n;t++)
    {
        int x = ord[t];
        for(int y : inv[x])
        {
            for(auto u : dp[y])
            {
                if(u.second > 0) dp[x].push_back({u.first + 1, u.second});
            }
        }
        sort(dp[x].begin(), dp[x].end());
        vector<pair<ll, ll>> tmp;
        
        int s = dp[x].size();
        tmp.push_back(dp[x][0]);
        
        for(int i=1;i<s;i++)
        {
            auto u = tmp.back();
            if(u.first + u.second < dp[x][i].first) tmp.push_back(dp[x][i]);
            else
            {
                tmp.back().second += dp[x][i].second;
                if(tmp.back().second > mod)
                {
                    tmp.back().second %= mod;
                    tmp.back().second += mod;
                }
            }
        }
        dp[x] = tmp;
        
        /*
        cout << "dp[" << x << "]\n";
        for(auto u : dp[x]) cout << u.first << " " << u.second << "\n";
        cout << "\n";
         */
    }
    
    int E = ord[n];
    
    int s = dp[E].size();
    cout << (dp[E][s-1].first + dp[E][s-1].second)%mod << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}