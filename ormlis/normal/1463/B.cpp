#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 999999001;

void solve() {
    int n ;cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    ll sum1 = 0;
    range(i, n) {
        if (i % 2) sum1 += a[i] - 1;
    }
    ll s = accumulate(all(a), 0ll);
    if (sum1 * 2 <= s) {
        range(i, n) {
            if (i % 2) cout << "1 ";
            else cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    range(i, n) {
        if (i % 2) cout << a[i] << ' ';
        else cout << "1 ";
    }
    cout << '\n';
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