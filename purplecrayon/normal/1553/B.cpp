#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    string s, t; cin >> s >> t;
    int n = sz(s);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (s[j] == t[j-i]) {
                int cur = (j-i+1), left = sz(t)-(j-i+1);
                if (j < left) continue;

                bool bad = 0;
                for (int k = j-1; k >= j-left && !bad; k--) {
                    if (t[cur+(j-1)-k] != s[k]) bad = 1;
                }
                if (!bad){ cout << "YES\n"; return; }
            } else {
                break;
            }
        }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}