#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;


const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll l, r, m; cin >> l >> r >> m;
    ll up = m + r - l;
    ll down = m - r + l;
    for(ll a = l; a <= r; ++a) {
        ll upn = up / a;
        ll downn = (down - 1) / a + 1;
        if (upn >= downn) {
            cout << a << " ";
            if (upn * a > m) {
                cout << l << " " << upn * a - m + l << '\n';
            } else {
                cout << m - upn * a + l << " " << l << "\n";
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}