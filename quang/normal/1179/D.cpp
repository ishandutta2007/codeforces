#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const long long INF = (1ll << 60);

int n;
vector<int> adj[N];
int numChild[N];
long long best[N];
long long res = -INF;

struct ConvexHull {
    long long a[N], b[N];
    double x[N];
    int bot, top;

    void init() {
        bot = top = 0;
    }

    void add(long long A, long long B) {
        double X = -INF;
        while (top > bot) {
            if (A == a[top - 1]) {
                if (B >= b[top - 1]) return;
                top--;
                continue;
            }
            X = 1.0 * (B - b[top - 1]) / (a[top - 1] -  A);
            if (X > x[top - 1]) break;
            top--;
        }
        x[top] = X;
        a[top] = A;
        b[top] = B;
        top++;
    }

    long long get(long long u) {
        if (bot == top) return INF;
        while (bot + 1 < top && x[bot + 1] <= u) {
            bot++;
        }
        return a[bot] * u + b[bot];
    }
} h;

void dfs(int u, int p) {
    if (adj[u].size() == 1 && u != 1) {
        best[u] = numChild[u] = 1;
        return;
    }
    numChild[u] = 1;
    vector<pair<long long, long long>> vals;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        numChild[u] += numChild[v];
        vals.push_back({numChild[v], best[v] - 2ll * n * numChild[v] + 1ll * numChild[v] * numChild[v]});
    }
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    long long now = INF;

    h.init();
    for (auto v : vals) {
        now = min(now, h.get(2ll * v.first) + v.second);
        h.add(v.first, v.second);
    }


    if (now != INF) {
        res = max(res, 1ll * n * (n - 1) - now);
    }

    best[u] = INF;
    for (int v : adj[u]) {
        if (v == p) continue;
        best[u] = min(best[u], best[v] + 1ll * (numChild[u] - numChild[v]) * (numChild[u] - numChild[v]));
        res = max(res, 1ll * n * (n - 1) + 1ll * n * n - (best[v] + 1ll * (n - numChild[v]) * (n - numChild[v])));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    assert(res % 2 == 0);
    cout << res / 2 << endl;
    return 0;   
}