#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n, q; cin >> n >> q;
    int e = 0, o = 0;
    ll sum = 0;
    while (n--) {
        int x; cin >> x;
        sum += x;
        if (x % 2) o++;
        else e++;
    }

    while (q--) {
        int t; ll x; cin >> t >> x;
        if (t == 0) {
            sum += x * e;
            if (x % 2) o += e, e = 0;
        } else {
            sum += x * o;
            if (x % 2) e += o, o = 0;
        }
        cout << sum << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}