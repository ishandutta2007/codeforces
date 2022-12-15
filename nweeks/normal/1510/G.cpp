#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
vector<int> par;
vector<int> depth;
int aVisiter;
vector<int> sol;
set<int> surChemin;

void dfs(int u) {
    if (!aVisiter)
        return ;
    aVisiter--;
    sol.push_back(u);
    for (int v : adj[u])
        if (!surChemin.count(v)) {
            dfs(v);
            if (sol.back() != u)
            sol.push_back(u);
        }
   
}

void solve() {
    int nbSommets;
    cin >> nbSommets >> aVisiter;
    adj = vector<vector<int>>(nbSommets);
    par = vector<int>(nbSommets);
    sol = {};
    depth.assign(nbSommets, 0);
    surChemin.clear();
    for (int i = 1; i < nbSommets; ++i) {
        cin >> par[i];
        --par[i];
        adj[par[i]].push_back(i);
        depth[i] = 1 + depth[par[i]];
    }
    int dernier = 0;
    for (int i = 1; i < nbSommets; ++i)
        if (depth[i] < aVisiter and depth[i] > depth[dernier])
            dernier = i;
    aVisiter -= depth[dernier] + 1;
    int cur = dernier;
    while (true) {
        surChemin.insert(cur);
        if (!cur)
            break;
        cur = par[cur];
    }
    cur = dernier;
    while (true) {
        sol.push_back(cur);
        for (int u : adj[cur])
            if (!surChemin.count(u)) {
                dfs(u);
                if (sol.back() == u)
                    sol.push_back(cur);
            }

        if (!cur)
            break;
        cur = par[cur];
    }
    reverse(sol.begin(), sol.end());
    cout << sol.size()-1 << '\n';
    for (int x : sol)
        cout << x + 1 << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}