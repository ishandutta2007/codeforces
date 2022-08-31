#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <tuple>
#include <queue>
#include <set>

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
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll a, b, x, y; cin >> a >> b >> x >> y;
    ll n; cin >> n;
    ll ans = INF;
    if (n >= a - x) {
        ans = min(ans, x * max(y, b - (n - (a - x))));
    } else {
        ans = min(ans, (a - n) * b);
    }
    if (n >= b - y) {
        ans = min(ans, y * max(x, a - (n - (b - y))));
    } else {
        ans = min(ans, a * (b - n));
    }
    cout << ans << "\n";
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