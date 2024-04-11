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
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<ar<int, 4>> ops;
    auto op = [&] (int i, int j, int x, int y) {
        ops.push_back({i + 1, j + 1, x, y});
        assert(min(a[i], a[j]) == min(x, y));
        a[i] = x;
        a[j] = y;
    };
    int mn = min_element(all(a)) - a.begin();
    range(i, n) {
        if (i == mn) continue;
        if (i % 2 == mn % 2) {
            op(i, mn, a[mn], a[mn]);
        } else {
            op(i, mn, a[mn] + 1, a[mn]);
        }
    }
    cout << ops.size() << '\n';
    for(auto &[i, j, x, y] : ops) cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
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