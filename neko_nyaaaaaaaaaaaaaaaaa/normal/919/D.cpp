#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, x, y;
bool cycle = 0;
string s;
vector<vector<int>> adj(300007);
vector<int> v(300007);
stack<int> topo;

void dfs(int now) {
    v[now] = 1;
    for (int i = 0; i < adj[now].size(); i++) {
        if (v[adj[now][i]] == 2) {continue;}
        if (v[adj[now][i]] == 1) {cycle = 1; return;}
        dfs(adj[now][i]);
    }
    v[now] = 2;
    topo.push(now);
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n >> m >> s;
    while (m--) {
        cin >> x >> y;
        if (x == y) {cout << -1; return 0;}
        adj[--x].push_back(--y);
    }

    // topological sorting begins
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) dfs(i);
        }
        if (cycle) {cout << -1; return 0;}
    // topological sorting ends

    vector<vector<int>> dp(300007, vector<int>(26));
    int ans = 0;

    while (topo.size()) {

        int fr = topo.top();            // fr == front
        dp[fr][s[fr] - 'a'] = max(dp[fr][s[fr] - 'a'], 1);
        for (int i = 0; i < adj[fr].size(); i++) {
            for (int j = 0; j < 26; j++) {
                dp[adj[fr][i]][j] = max(dp[adj[fr][i]][j], dp[fr][j] + (s[adj[fr][i]] == ('a' + j)));
            }
        }

        topo.pop();
    }

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;

    return 0;
}