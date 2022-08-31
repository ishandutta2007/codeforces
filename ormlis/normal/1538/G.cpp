#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5;

const int K = 2e4;

void solve() {
    int x, y, a, b; cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    if (a > b) swap(a, b);
    int ans = 0;
    for(int d = 0; d <= K; ++d) {
        int x1 = x - d * (a + b);
        int y1 = y - d * (a + b);
        if (x1 < 0 || y1 < 0) break;
        ans = max(ans, d * 2 + min(x1 / a, y1 / b));
    }
    for(int d = 0; d <= K; ++d) {
        int x1 = x - d * a;
        int y1 = y - d * b;
        if (x1 < 0 || y1 < 0) break;
        ans = max(ans, d + 2 * (min(x1, y1) / (a + b)));
    }
    if (a != b) {
        int f = b - a;
        int k = (y - x) / f;
        for(int d = max(k - 500, 0); d <= k + 500; ++d) {
            ll x1 = x - 1ll * d * a;
            ll y1 = y - 1ll * d * b;
            if (x1 < 0 || y1 < 0) break;
            ans = max(ans, d + 2 * ((int)min(x1, y1) / (a + b)));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    // cout << setprecision(15) << fixed;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}