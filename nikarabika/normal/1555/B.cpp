//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

int solve() {
    int x, y, xx, yy;
    int w, h;
    cin >> w >> h;
    cin >> x >> y >> xx >> yy;
    int n, m;
    cin >> n >> m;
    if (xx - x + n > w and yy - y + m > h)
        return cout << -1 << '\n', 0;
    int xle = x, xri = w - xx;
    int yle = y, yri = h - yy;
    int ans = 2e9;
    if (xx - x + n <= w)
        smin(ans, n - max(xle, xri));
    if (yy - y + m <= h)
        smin(ans, m - max(yle, yri));
    smax(ans, 0);
    cout << ans << '\n';
    return 0;
}