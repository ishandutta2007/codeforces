#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

string qry(string s) {
    cout << "? " << s << endl;
    string ans; cin >> ans;
    return ans;
}
void solve() {
    string t; cin >> t;
    int n = sz(t);
    vector<int> who(n); // who ends up at the ith index
    string one(n, '?'), two(n, '?'), three(n, '?');
    for (int i = 0; i < n; i++) one[i] = char('a' + i % 26);
    for (int i = 0; i < n; i++) two[i] = char('a' + (i / 26) % 26);
    for (int i = 0; i < n; i++) three[i] = char('a' + (i / 26 / 26) % 26);
    auto a = qry(one), b = qry(two), c = qry(three);
    for (int i = 0; i < n; i++) {
        who[i] = (a[i] - 'a') + 26 * (b[i] - 'a') + 26 * 26 * (c[i] - 'a');
    }
    string ans(n, '?');
    for (int i = 0; i < n; i++) ans[who[i]] = t[i];
    cout << "! " << ans << endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}