#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    int one = n;
    int ans = 0;
    for (int l = n-1; l >= 0; l--) {
        if (s[l] == '1')
            one = l;

        ll x = 0;
        for (int r = one; r < n; r++) {
            x *= 2;
            x += s[r] - '0';
            if (x > n) break;
            if (r - l + 1 == x) ans++;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}