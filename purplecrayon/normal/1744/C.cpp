#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; char c; cin >> n >> c;
    string s; cin >> s;
    s += s;
    int ans = -1, p = MOD;
    for (int i = sz(s)-1; i >= 0; i--) {
        if (s[i] == 'g') p = i;
        if (i < n && s[i] == c) ans = max(ans, p - i);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}