#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    string s; cin >> s;
    map<char, int> loc;
    int n = sz(s);
    for (int i = 0; i < n; i++) if (s[i] != '!') {
        loc[s[i]] = i % 4;
    }
    int cnt[4] = {};
    for (int i = 0; i < n; i++) if (s[i] == '!') cnt[i % 4]++;

    string t = "RBYG";
    for (char c : t) cout << cnt[loc[c]] << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}