#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    ll a, b, x; cin >> a >> b >> x;
    while (1) {
        if (a == x || b == x) {
            cout << "YES\n";
            return;
        }
        if (a < b) swap(a, b);
        if (b > a - b) b = a - b;
        if (x > max(a, b) || a == 0 || b == 0) break;
        a -= b * max(1ll, (a - max(x, b)) / (2 * b));
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}