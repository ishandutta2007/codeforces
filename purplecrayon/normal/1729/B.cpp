#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string ans;
    while (sz(s)) {
        if (sz(s) >= 3 && s.back() == '0') {
            s.pop_back();
            ans += char(stoi(s.substr(sz(s)-2, 2)) + 'a' - 1);
            s.pop_back(), s.pop_back();
        } else {
            ans += char(s.back() - '1' + 'a');
            s.pop_back();
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}