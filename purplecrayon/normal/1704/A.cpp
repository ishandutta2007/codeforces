#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 998244353;

void solve() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    if (s == t) {
        cout << "YES\n";
        return;
    }
    if (n <= m) {
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < sz(t)-1; i++) {
        if (s[sz(s) - i - 1] != t[sz(t) - i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = sz(s) - sz(t); i >= 0; i--) {
        if (s[i] == t[0]) {
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