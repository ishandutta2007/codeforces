#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int D = 51;
const int INF = 1e9;

int n, m, d;
vector<int> adj[N];
string s[N];

int num[N * D], low[N * D], root[N * D], cntTarjan;
vector<int> stTarjan;
int cntComp;
vector<int> ls;
int tot[N * D];
int dp[N * D];

inline int encode(int u, int v) {
    return u * d + v;
}

inline pair<int, int> decode(int u) {
    return {u / d, u % d};
}

void init() {
    memset(root, -1, sizeof root);
    memset(low, -1, sizeof low);
    memset(num, -1, sizeof num);
}

bool isOpen(int id) {
    int u = id / d, day = id % d;
    return s[u][day] == '1';
}

inline void tarjan(int u) {
    stTarjan.push_back(u);
    low[u] = num[u] = cntTarjan++;
    int id = u / d, day = u % d;
    for (int v : adj[id]) {
        int nxt = encode(v, (day + 1) % d);
        if (root[nxt] != -1) continue;
        if (low[nxt] == -1) tarjan(nxt);
        low[u] = min(low[u], low[nxt]);
    }
    if (low[u] == num[u]) {
        set<int> s;
        while (1) {
            int v = stTarjan.back();
            ls.push_back(v);
            stTarjan.pop_back();
            root[v] = cntComp;
            if (isOpen(v)) s.insert(v / d);
            if (u == v) break;
        }
        tot[cntComp++] = s.size();
    }
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) cin >> s[i];

    init();

    for (int i = 0; i < n; i++) for (int j = 0; j < d; j++) {
        int id = encode(i, j);
        if (root[id] == -1) tarjan(id); 
    }
    for (int i = 0; i < cntComp; i++) dp[i] = -INF;
    int rootId = root[encode(0, 0)];
    dp[rootId] = tot[rootId];
    int res = 0;
    for (int i = ls.size() - 1; i >= 0; i--) {
        int id = ls[i];
        int u, day;
        tie(u, day) = decode(id);
        res = max(res, dp[root[id]]);
        for (int v : adj[u]) {
            int idV = encode(v, (day + 1) % d);
            if (root[idV] == root[id]) continue;
            dp[root[idV]] = max(dp[root[idV]], dp[root[id]] + tot[root[idV]]);
        }
    }
    cout << res << endl;
    return 0;
}