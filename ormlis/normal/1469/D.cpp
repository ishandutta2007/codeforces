#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    iota(all(a), 1);
    vector<pair<int, int>> ans;
    for(int i = n - 2; i >= 1; --i) {
        int to = (a[n - 1] + a[i] - 1) / a[i];
        while (to >= a[i]) {
            ans.emplace_back(n - 1, i);
            a[n - 1] = to;
            to = (a[n - 1] + a[i] - 1) / a[i];
        }
        ans.emplace_back(i, n - 1);
        a[i] = (a[i] + a[n - 1] - 1) / a[n - 1];
    }
    sort(all(a));
    vector<int> b(n, 1);
    b[n - 1] = 2;
    assert(a == b);
    cout << ans.size() << '\n';
    for(auto &[x, y] : ans) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
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