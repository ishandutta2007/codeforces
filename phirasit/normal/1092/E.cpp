#include <bits/stdc++.h>

using namespace std;

const int N = 5010 + 10;

vector<int> adj[N];
int A[N];
int pass[N];


int max1[N], max2[N], path[N];
int ans = 0;

void dfs1(int u, int p) {
    pass[u] = p;
    max1[u] = max2[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;

        dfs1(v, u);

        int val = max1[v] + 1;

        if (val > max1[u]) {
            path[u] = v;
            max2[u] = max1[u];
            max1[u] = val;
        } else if (val > max2[u]) {
            max2[u] = val;
        }
    }

    ans = max(ans, max1[u] + max2[u]);
}

int dfs2(int u, int p) {

    if (p != -1) {
        int val = (path[p] != u ? max1 : max2)[p] + 1;

        if (val > max1[u]) {
            path[u] = p;
            max2[u] = max1[u];
            max1[u] = val;
        } else if (val > max2[u]) {
            max2[u] = val;
        }

        ans = max(ans, max1[u] + max2[u]);
    }

    int best = u;
    for (int v : adj[u]) {
        if (v == p) continue;
        int x = dfs2(v, u);
        if (max1[x] < max1[best]) {
            best = x;
        }
    }

    return best;
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> candid;
    for (int i = 1; i <= n; ++i) {
        if (pass[i]) continue;
        dfs1(i, -1);
        candid.push_back(dfs2(i, -1));
    }


    for (int i = 1; i < candid.size(); ++i) {
        if (max1[candid[i]] > max1[candid[0]]) {
            swap(candid[0], candid[i]);
        }
    }

    const int u = candid[0];
    for (int i = 1; i < candid.size(); ++i) {
        ans = max(ans, max1[u] + max1[candid[i]] + 1);
        max1[u] = max(max1[u], max1[candid[i]] + 1);
    }

    cout << ans << endl;
    for (int i = 1; i < candid.size(); ++i) {
        cout << u << " " << candid[i] << "\n";
    }

    cout.flush();

    return 0;
}