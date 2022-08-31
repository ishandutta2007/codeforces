#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;
    string one = to_string(a);
    string two = to_string(c);
    if (sz(one) + b == sz(two) + d) {
        while (sz(one) < sz(two)) one += '0', b--;
        while (sz(one) > sz(two)) two += '0', d--;
        assert(b == d);
        if (one > two) cout << '>';
        else if (one < two) cout << '<';
        else cout << '=';
    } else {
        if (sz(one) + b > sz(two) + d) cout << '>';
        else cout << '<';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}