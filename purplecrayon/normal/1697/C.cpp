#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    string ac_s, ac_t, b_s, b_t;
    for (char c : s) {
        if (c == 'a' || c == 'c') ac_s += c;
        else b_s += c;
    }
    for (char c : t) {
        if (c == 'a' || c == 'c') ac_t += c;
        else b_t += c;
    }
    if (ac_s != ac_t || b_s != b_t) {
        cout << "NO\n";
        return;
    }
    vector<int> pos_s[3], pos_t[3];
    for (int i = 0; i < n; i++) {
        pos_s[s[i] - 'a'].push_back(i);
        pos_t[t[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < sz(pos_s[0]); i++) {
        if (pos_s[0][i] > pos_t[0][i]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < sz(pos_s[2]); i++) {
        if (pos_s[2][i] < pos_t[2][i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}