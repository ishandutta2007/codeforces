#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 998244353;

vector<int> g[maxN];
bool was[maxN];
int edg = 0;
int vert = 0;

void dfs(int v) {
    vert++;
    edg += g[v].size();
    was[v] = true;
    for (auto &u : g[v]) {
        if (was[u]) continue;
        dfs(u);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    range(i, n) {
        range(j, m) {
            cin >> a[j][i];
        }
    }
    vector<int> mx(m);
    range(i, m) mx[i] = *max_element(all(a[i]));
    vector<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](const int &i, const int &j) {
        return mx[i] > mx[j];
    });
    if (m > n) {
        ord.resize(n);
    }
    int sz = ord.size();
    vector<int> dp(1 << n, 0);
    auto get_dp = [&](int i) {
        vector<int> dp2(1 << n, 0);
        range(_, n) {
            range(mask, 1 << n) {
                int s = 0;
                range(b, n) {
                    if (mask & (1 << b)) {
                        s += a[i][b];
                    }
                }
                dp2[mask] = max(dp2[mask], s);
            }
            range(t, n - 1) swap(a[i][t], a[i][t + 1]);
        }
        return dp2;
    };
    range(i, sz) {
        auto dp2 = get_dp(ord[i]);
        for (int mask = (int) (1 << n) - 1; mask >= 0; --mask) {
            for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                dp[mask] = max(dp[mask], dp[submask] + dp2[mask ^ submask]);
            }
            dp[mask] = max(dp[mask], dp2[mask]);
        }
    }
    cout << dp[(int) (1 << n) - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}