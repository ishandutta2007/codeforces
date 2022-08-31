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
const int maxN = 2e6 + 1000;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<vector<int>> v(2);
    range(i, n) {
        int x; cin >> x;
        v[x-1].push_back(a[i]);
    }
    sort(rall(v[0]));
    sort(rall(v[1]));
    ll sum = 0;
    int r = 0;
    ll ans = 1e18;
    range(i, v[0].size() + 1) {
        while(sum >= m && r) {
            r--;
            sum -= v[1][r];
        }
        while(sum < m && r < v[1].size()) {
            sum += v[1][r];
            r++;
        }
        if (sum >= m) {
            ans = min(ans, ll(i + 2 * r));
        }
        if (i < v[0].size()) sum += v[0][i];
    }
    if (ans == 1e18) {
        cout << "-1\n";
        return;
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