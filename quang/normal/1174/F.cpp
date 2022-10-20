#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int LOG = 20;

int n;
vector<int> adj[N];
int lv[N];
int par[LOG][N];
int targetDepth;
int numGood[N];
int child[N];

int getPar(int u, int h) {
    for (int i = LOG - 1; i >= 0; i--) {
        if ((h >> i) & 1) {
            u = par[i][u];
        }
    }
    return u;
}

void dfs(int u, int p) {
    lv[u] = (u == 1 ? 0 : lv[p] + 1);
    par[0][u] = p;
    for (int i = 1; i < LOG; i++) {
        par[i][u] = par[i - 1][par[i - 1][u]];
    }
    child[u] = -1;
    numGood[u] = 0;
    if (lv[u] == targetDepth) {
        numGood[u] = 1;
        child[u] = u;
    } else {
        int maxIndex = -1;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            if (maxIndex == -1 || numGood[v] > numGood[maxIndex]) {
                maxIndex = v;
            }
            numGood[u] += numGood[v];
        }
        if (maxIndex != -1) child[u] = child[maxIndex];
    }   
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "d " << 1 << endl;
    cin >> targetDepth;
    if (targetDepth == 0) {
        cout << "! " << 1 << endl;
        return 0;
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; i++) {
    //     cout << child[i] << ' ';
    // }
    // cout << endl;
    int cur = 1;
    while (lv[cur] < targetDepth) {
        cout << "d " << child[cur] << endl;
        int d;
        cin >> d;
        assert(d % 2 == 0);
        cur = getPar(child[cur], d / 2);
        if (lv[cur] == targetDepth) break;
        cout << "s " << cur << endl;
        cin >> cur;
    }
    cout << "! " << cur << endl;
    return 0;
}