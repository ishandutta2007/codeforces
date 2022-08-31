#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 4e4+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n = sz(s);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < i; j++) {
            bool one = 0, two = 0;
            char last = '?';
            bool bad = 0;
            for (int k = 0; k < n; k++) if (s[k] - 'a' == i || s[k] - 'a' == j) {
                if (s[k] - 'a' == i) one = 1;
                if (s[k] - 'a' == j) two = 1;
                if (last == s[k]) {
                    bad = 1;
                }
                last = s[k];
            }
            if (one && two && bad) {
                cout << "NO\n";
                return;
            }
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