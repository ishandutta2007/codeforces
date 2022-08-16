#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int one = min(a, x), two = min(b, y);
    a -= one, x -= one;
    b -= two, y -= two;
    if (c >= x + y) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}