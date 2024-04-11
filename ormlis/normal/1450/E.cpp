#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int dist[202][202];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ar<int, 3>> edges;
    range(i, 202) range(j, 202) dist[i][j] = INFi;
    range(_, m) {
        int i, j, b;
        cin >> i >> j >> b;
        edges.push_back({i, j, b});
        dist[i][j] = min(dist[i][j], 1);
        dist[j][i] = min(dist[j][i], 1);
        if (b == 1) {
            dist[j][i] = min(dist[j][i], -1);
        }
    }
    range(i, n) dist[i + 1][i + 1] = 0;
    range(k, n) {
        range(i, n) {
            range(j, n) {
                dist[i + 1][j + 1] = min(dist[i + 1][j + 1],
                                         dist[i + 1][k + 1] + dist[k + 1][j + 1]);
            }
        }
    }
    vector<pair<int, int>> norm;
    range(i, n) {
        bool bb = false;
        for (auto[v, u, b] : edges) {
            int t = abs(dist[i + 1][v] - dist[i + 1][u]);
            if (t != 1) bb = true;
            if (b == 1 && dist[i + 1][v] + 1 != dist[i + 1][u]) bb = true;
        }
        if (!bb) {
            int as = *max_element(dist[i + 1] + 1, dist[i + 1] + n + 1) - *min_element(dist[i + 1] + 1, dist[i + 1] + n + 1);
            norm.emplace_back(as, i + 1);
        }
    }
    sort(rall(norm));
    if (norm.empty()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int s = norm[0].first;
    cout << s << '\n';
    int v = norm[0].second;
    range(i, n) {
        cout << dist[v][i + 1] + 1000 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}