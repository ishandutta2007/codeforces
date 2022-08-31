#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 31, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    ar<int, 26> cnt; cnt.fill(0);
    for (auto c : s) cnt[c - 'a']++;

    int ans = 0;
    for (int i = 0; i < sz(s); i++) {
        if (cnt[s[i] - 'a'] > 1) {
            ans++;
            cnt[s[i] - 'a']--;
        } else {
            break;
        }
    }
    cout << s.substr(ans) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}