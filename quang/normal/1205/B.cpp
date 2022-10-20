#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 60;

int n;
long long a[N];
vector<int> ls[LOG];
set<int> adj[N];
int mark[N];
int used[N];
int res = 1000;

void dfs(int u, int lv, int last) {
    used[u] = 1;
    mark[u] = lv;
    for (int v : adj[u]) {
        if (v == last) continue;
        if (mark[v] != 0) res = min(res, lv + 1 - mark[v]);
        else dfs(v, lv + 1, u);
    }
    mark[u] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < LOG; j++) {
            if (a[i] & (1ll << j)) {
                ls[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < LOG; i++) {
        if (ls[i].size() >= 3) {
            cout << 3 << endl;
            return 0;
        }
        if (ls[i].size() != 2) continue;
        adj[ls[i][0]].insert(ls[i][1]);
        adj[ls[i][1]].insert(ls[i][0]);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, 1, 0);
        }
    }
    if (res == 1000) cout << -1 << endl;
    else 
    cout << res << endl;
    return 0;
}