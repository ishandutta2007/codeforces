#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = 0;
    for(int x = a; x <= b; ++x) {
        int min_y = max(b, d + 1 - x);
        ans += max(0, c - min_y + 1);
    }
    ll ans2 = ans;
    for(int z = d - 1; z >= c; --z) {
        int max_y = min(c, z + 1 - a);
        int min_y = max(b, z + 1 - b);
        ans += max(0, max_y - min_y + 1);
        ans2 += ans;
    }
    cout << ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}