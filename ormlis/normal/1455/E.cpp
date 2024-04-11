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
    int n = 4;
    vector<pair<int, int>> a(n);
    range(i, n) cin >> a[i].first >> a[i].second;
    ll ans = INF;

    auto dist = [&](pair<int, int> &x, pair<int, int> &y) {
        return (ll) abs(x.first - y.first) + (ll) abs(x.second - y.second);
    };

    auto check = [&](int x, int y, int x2, int y2) {
        vector<pair<int, int>> pts = {{x,  y},
                                      {x2, y2},
                                      {x,  y2},
                                      {x2, y}};
        auto b = a;
        range(_, 24) {
            ll d = 0;
            range(t, 4) {
                d += dist(pts[t], b[t]);
            }
            ans = min(ans, d);
            next_permutation(all(b));
        }
    };
    vector<int> X;
    vector<int> Y;
    range(t, 4) {
        X.push_back(a[t].first);
        Y.push_back(a[t].second);
    }
    sort(all(X));
    X.resize(unique(all(X)) - X.begin());
    sort(all(Y));
    Y.resize(unique(all(Y)) - Y.begin());
    for (auto x : X) {
        for (auto x2 : X) {
            for (auto y : Y) {
                {
                    int y2 = y + (x2 - x);
                    check(x, y, x2, y2);
                }
                {
                    int y2 = y - (x2 - x);
                    check(x, y, x2, y2);
                }
            }
        }
    }
    for (auto x : X) {
        for (auto y2 : Y) {
            for (auto y : Y) {
                {
                    int x2 = x + (y2 - y);
                    check(x, y, x2, y2);
                }
                {
                    int x2 = x - (y2 - y);
                    check(x, y, x2, y2);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}