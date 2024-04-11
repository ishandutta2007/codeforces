#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

ll solve(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n1 = a.size(), n2 = b.size(), n3 = c.size();
    ll ans = INF;
    for (int i = 0; i < n1; ++i) {
        int mx = a[i];
        int j = upper_bound(all(b), mx) - b.begin();
        j--;
        if (j < 0) continue;
        int e = upper_bound(all(c), b[j]) - c.begin();
        e--;
        if (e < 0) continue;
        int mn = c[e];
        int sr = (mx + mn) / 2;
        j = lower_bound(all(b), sr) - b.begin();
        if (j != b.size()) {
            ll x = mx - b[j], y = mx - mn, z = b[j] - mn;
            ans = min(ans, x * x + y * y + z * z);
        }
        if (j != 0) {
            j--;
            ll x = mx - b[j], y = mx - mn, z = b[j] - mn;
            ans = min(ans, x * x + y * y + z * z);
        }
    }
    return ans;
}

void solve() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> a(n1), b(n2), c(n3);
    range(i, n1) cin >> a[i];
    range(i, n2) cin >> b[i];
    range(i, n3) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    ll ans = min(min(min(solve(a, b, c),
                         solve(b, c, a)),
                     solve(a, c, b)),
                 min(min(solve(b, a, c),
                         solve(c, a, b)),
                     solve(c, b, a)));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}