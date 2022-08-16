#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    string s, c; cin >> s >> c;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == c[0] && i % 2 == 0 && (sz(s) - i - 1) % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}