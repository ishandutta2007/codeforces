#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int INF = 1e9;
const int LOG = 21;

int n, k;
vector<int> adj[N];
int lv[N];
int par[LOG][N];
int sum[N];
int canGo[N];
int minLv[N];

void dfsInit(int u, int p) {
    lv[u] = lv[p] + 1;
    par[0][u] = p;
    for (int i = 1; i < LOG; i++) {
        par[i][u] = par[i - 1][par[i - 1][u]];
    }
    if (u != 1 && adj[u].empty()) {
        minLv[u] = lv[u];
        return;
    }
    for (int v : adj[u]) {
        dfsInit(v, u);
        minLv[u] = min(minLv[u], minLv[v]);
    }
}

int findPar(int u, int minLv) {
    minLv = max(minLv, 1);
    for (int i = LOG - 1; i >= 0; i--) {
        if (lv[par[i][u]] >= minLv) {
            u = par[i][u];
        }
    }
    return u;
}

void dfsBuildSum(int u) {
    int foo = findPar(u, minLv[u] - k);
    if (lv[foo] < lv[u]) {
        canGo[u] = canGo[findPar(u, minLv[u] - k)];
    } else {
        canGo[u] = u;
    }
    if (adj[u].empty() && u != 1) {
        sum[canGo[u]]++;
    }
    for (int v : adj[u]) {
        dfsBuildSum(v);
    }
}

int dfsGetRes(int u) {
    int res = 0;
    for (int v : adj[u]) {
        res = max(res, dfsGetRes(v));
    }
    res += sum[u];
    return res;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 2; i <= n; i++) {
        int u;
        scanf("%d", &u);
        adj[u].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        minLv[i] = INF;
    }
    dfsInit(1, 0);
    dfsBuildSum(1);
    int res = dfsGetRes(1);
    cout << res << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << canGo[i] << " ";
    // }
    // cout << endl;
    return 0;
}