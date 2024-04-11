#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    int po = 0;
    string s, other;
    while (n--) {
        cin >> s;
        if (s == "0") {
            cout << 0 << '\n';
            return;
        }
        if (s[0] == '1' && s.substr(1, sz(s) - 1) == string(sz(s) - 1, '0')) {
            po += sz(s) - 1;
        } else {
            other = s;
        }
    }
    if (!sz(other)) other = "1";
    other += string(po, '0');
    cout << other << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}