#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    map<pair<int, string>, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;
        int mask = 0;
        for (char c : t) mask |= 1 << (c - 'a');

        int last = -1;
        for (int j = 0; j < sz(s); j++) if ((mask >> (s[j] - 'a')) & 1 ^ 1) {
            last = j;
        }

        mp[{mask, s.substr(0, last + 1)}].push_back(i);
    }
    cout << sz(mp) << '\n';
    for (auto& [_, v] : mp) {
        cout << sz(v) << ' ';
        for (int x : v) cout << x+1 << ' ';
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}