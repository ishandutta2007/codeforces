#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e2+10, MOD = 998244353;

void solve() {
    int n, p; cin >> n >> p;
    string s; cin >> s;
    vector<ar<bool, 2>> has(p, {0, 0});
    for (int i = 0; i < n; i++) {
        if (s[i] != '.') {
            has[i % p][s[i] - '0'] = 1;
        }
    }
    for (int i = 0; i < n; i++) if (s[i] == '.') {
        if (has[i % p][0]) s[i] = '1', has[i % p][1] = 1;
        else s[i] = '0', has[i % p][0] = 1;
    }
    for (int i = p; i < n; i++) if (s[i] != s[i - p]) {
        cout << s << '\n';
        return;
    }
    cout << "No\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}