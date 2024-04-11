#include <bits/stdc++.h>

using namespace std;

const int N = 250010;
const long long INF = (1ll << 50);

int n;
vector<pair<int, int>> adj[N];
int ls[N];
int used[N];
long long dp[2][N];
int sz[N];

// must guarantee that small's < big's
struct Heap {
    multiset<long long> small, big;
    long long sumSmall, sumBig;
    int cntNeg;
    long long sumNeg;
    Heap() {
        sumSmall = sumBig = 0;
        sumNeg = cntNeg = 0;
    }
    void add(long long u) {
        if (u <= 0) {
            cntNeg++;
            sumNeg += u;
            return;
        }
        if (!small.empty()) {
            int val = *small.rbegin();
            if (val > u) {
                small.insert(u);
                sumSmall += u;
                return;
            }
        }
        big.insert(u);
        sumBig += u;
    }
    void erase(long long u) {
        if (u <= 0) {
            cntNeg--;
            sumNeg -= u;
            return;
        }
        if (!small.empty() && small.count(u)) {
            small.erase(small.find(u));
            sumSmall -= u;
            return;
        }
        if (!big.empty() && big.count(u)) {
            big.erase(big.find(u));
            sumBig -= u;
            return;
        }
    }
    void normalize(int x) {
        while (small.size() < max(x, 0)) {
            long long u = *big.begin();
            big.erase(big.find(u));
            sumBig -= u;
            small.insert(u);
            sumSmall += u;
        }
        while (small.size() > max(x, 0)) {
            long long u = *small.rbegin();
            small.erase(small.find(u));
            sumSmall -= u;
            big.insert(u);
            sumBig += u;
        }
    }
    long long get(int x) {
        if (small.size() + big.size() + cntNeg < x) return INF;
        if (cntNeg >= x) return sumNeg;
        normalize(x - cntNeg);
        return sumNeg + sumSmall;
    }
} a[N];

void dfs(int u, int p, int x) {
    used[u] = x;
    while (!adj[u].empty() && sz[adj[u].back().first] <= x) {
        adj[u].pop_back();
    }
    long long sum = 0;
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        dfs(v.first, u, x);
        sum += dp[0][v.first];
        a[u].add(dp[1][v.first] + v.second - dp[0][v.first]);
    }

    dp[0][u] = sum + a[u].get(sz[u] - x);
    dp[1][u] = sum + a[u].get(sz[u] - x - 1);
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        a[u].erase(dp[1][v.first] + v.second - dp[0][v.first]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) ls[i] = i;
    sort(ls + 1, ls + n + 1, [](int u, int v) {
        return adj[u].size() < adj[v].size();
    });
    for (int i = 1; i <= n; i++) {
        auto cmp = [](pair<int, int> &u, pair<int, int> &v) {
            return adj[u.first].size() > adj[v.first].size();
        };
        sort(adj[i].begin(), adj[i].end(), cmp);
        sz[i] = adj[i].size();
    }
    memset(used, -1, sizeof used);
    int cur = 1;
    for (int x = 0; x < n; x++) {
        while (cur <= n && sz[ls[cur]] <= x) {
            // add this to dead vertices
            for (auto u : adj[ls[cur]]) {
                a[u.first].add(u.second);
            }
            cur++;
        }
        long long res = 0;
        for (int i = cur; i <= n; i++) {
            int u = ls[i];
            if (used[u] != x) {
                dfs(u, 0, x);
                res += dp[0][u];
            }
        }
        cout << res << ' ';
    }
    cout << endl;
    return 0;
}