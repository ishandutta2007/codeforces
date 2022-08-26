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
const int maxN = 1e6 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ar<int, 2>> l(n + 1, {0, 0}), r(n + 1, {0, 0});
    for(int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'L') {
            l[i][0] = l[i - 1][1] + 1;
        } else {
            l[i][1] = l[i - 1][0] + 1;
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        if (s[i] == 'R') {
            r[i][0] = r[i + 1][1] + 1;
        } else {
            r[i][1] = r[i + 1][0] + 1;
        }
    }
    range(i, n + 1) {
        int ans = l[i][0] + r[i][0] + 1;
        cout << ans << ' ';
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