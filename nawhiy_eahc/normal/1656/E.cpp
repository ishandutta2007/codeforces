#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;
vector<int> adj[100002];
ll a[100002];
void dfs(int x, int p, int h)
{
    int m = adj[x].size();
    if(h%2 == 1) a[x] = m;
    else a[x] = -m;
    for(int i : adj[x])
    {
        if(i == p) continue;
        dfs(i, x, h+1);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1, 0);

        for(int i=1;i<=n;i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}