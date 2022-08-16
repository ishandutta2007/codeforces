#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    for (int i = 1; i < sz(s); i++) {
        if (s[i] == s[i-1]) {
            s[i] = 'a';
            while (s[i] == s[i-1] || (i < sz(s)-1 && s[i] == s[i+1])) s[i]++;
        }
    }
    cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}