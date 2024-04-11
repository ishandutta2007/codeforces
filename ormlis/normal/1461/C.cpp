#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n) a[i]--;
    int mxi = n - 1;
    while(mxi >= 0 && a[mxi] == mxi) mxi--;
    long double ans = 1;
    range(i, m) {
        int r; long double p;
        cin >> r >> p;
        if (r > mxi) ans *= 1 - p;
    }
    if (mxi == -1) {
        ans = 1;
        cout << ans << "\n";
        return;
    }
    cout << 1 - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}