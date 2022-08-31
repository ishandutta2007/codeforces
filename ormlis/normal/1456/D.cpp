#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    vector<ll> t(n + 1), x(n + 1);
    t[0] = x[0] = 0;
    range(i, n) cin >> t[i + 1] >> x[i + 1];
    vector<vector<pair<ll, ll>>> dp(n + 1);
    dp[0].emplace_back(0, 0);
    bool answer = false;
    for (int i = 1; i <= n; ++i) {
        bool can = true;
        for (int j = i - 1; j >= 0; --j) {
            if (j + 2 < i) {
                if (t[j + 2] - t[j + 1] < abs(x[j + 2] - x[j + 1])) can = false;
            }
            for (auto[free_time, pos] : dp[j]) {
                ll need = abs(x[i] - pos);
                if (need + free_time > t[i]) continue;
                if (j + 1 == i) {
                    dp[i].emplace_back(max(free_time + need, t[j]), x[i]);
                    continue;
                }
                if (!can) break;
                ll ftime = free_time + need;
                ftime = max(ftime, t[j]);
                if (abs(x[i] - x[j + 1]) + ftime > t[j + 1]) continue;
                dp[i].emplace_back(t[i - 1], x[i - 1]);
            }
        }
        sort(all(dp[i]), [](pair<ll, ll> &x, pair<ll, ll> &y) {
            return make_pair(x.second, x.first) < make_pair(y.second, y.first);
        });
        vector<pair<ll, ll>> kek;
        for (int j = 0; j < (int) dp[i].size(); ++j) {
            if (kek.empty() || dp[i][j].second != kek.back().second) {
                kek.push_back(dp[i][j]);
            }
        }
        swap(dp[i], kek);
        if (dp[i].empty()) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}