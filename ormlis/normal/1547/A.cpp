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
const int INFi = 2e9 + 5;
const int maxN = 1e7 + 1;
const int md = 1e9 + 7;

void solve() {
    int xa, ya, xb, yb, xf, yf; cin >> xa >> ya >> xb >> yb >> xf >> yf;
    int ans = abs(xa - xb) + abs(ya - yb);
    int to = abs(xa - xf) + abs(xf - xb) + abs(ya - yf) + abs(yb - yf);
    if (to == ans) {
        if ((ya == yf) && (yb == yf)) {
            ans += 2;
        } else if ((xa == xf) && (xf == xb)) {
            ans += 2;
        }
    }
    cout << ans << '\n';
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