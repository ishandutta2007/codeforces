#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    auto get_div = [&](int x) {
        vector<int> ans;
        for (int i = 1; i * i <= x; i++) if (x % i == 0) {
            ans.push_back(i);
            if (i * i != x)
                ans.push_back(x / i);
        }
        return ans;
    };

    auto one = get_div(a), two = get_div(b);
    for (int i : one) for (int j : two) {
        ll x_small = (long long) i * j;
        ll x = (c / x_small) * x_small;
        ll y_small = ((long long) a / i) * (b / j);
        ll y = (d / y_small) * y_small;

        if (a < x && x <= c && b < y && y <= d) {
            cout << x << ' ' << y << '\n';
            assert((x * y) % ((long long) a * b) == 0);
            return;
        }
    }
    cout << -1 << ' ' << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}