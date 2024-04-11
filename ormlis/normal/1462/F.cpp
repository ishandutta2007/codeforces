#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 3e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    vector<pair<int, int>> lr(n);
    range(i, n) {
        cin >> l[i] >> r[i];
        lr[i] = {l[i], r[i]};
    }
    sort(all(r));
    sort(all(l));
    sort(all(lr));
    int ans = n;
    for(auto [li, ri] : lr) {
        int res = lower_bound(all(r), li) - r.begin();
        res += n;
        res -= upper_bound(all(l), ri) - l.begin();
        ans = min(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}