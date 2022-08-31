#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

vector<pair<int, int>> g[maxN];
vector<int> to[maxN][51];
int d[maxN][101];

void solve() {
    int n, m;
    cin >> n >> m;
    range(_, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        to[u][w].push_back(v);
        to[v][w].push_back(u);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 101});
    range(i, maxN) range(j, 101) d[i][j] = INFi;
    d[1][0] = 0;
    while (!q.empty()) {
        auto[dist, V] = q.top();
        q.pop();
        int v = V / 101;
        int i = V % 101;
        if (d[v][i] != dist) continue;
        if (i == 0) {
            for (auto &[u, w] : g[v]) {
                if (d[u][w] > dist + w * w) {
                    d[u][w] = dist + w * w;
                    q.push({d[u][w], u * 101 + w});
                }
            }
            continue;
        }
        if (i <= 50) {
            int s = d[v][i];
            for (int w = 51; w <= 100; ++w) {
                s += i * 2;
                if (d[v][w] > s) {
                    d[v][w] = s;
                    q.push({s, v * 101 + w});
                }
            }
            continue;
        }
        i -= 50;
        for (auto &u : to[v][i]) {
            if (d[u][0] > dist + i * i) {
                d[u][0] = dist + i * i;
                q.push({d[u][0], u * 101});
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if (d[i][0] == INFi) cout << "-1 ";
        else cout << d[i][0] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }


    return 0;
}