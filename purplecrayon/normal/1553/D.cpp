#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;


int nxt[MAXN][26][2];

void solve(){
    string s, t; cin >> s >> t; int n = sz(s), m = sz(t);

    for (int i = 0; i < 26; i++) for (int j : {0, 1}) nxt[n][i][j] = -1;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            for (int k : {0, 1}) nxt[i][j][k] = nxt[i+1][j][k];
        }
        nxt[i][s[i]-'a'][i&1] = i;
    }

    auto get = [&](int b) -> bool {
        int c = 0;
        for (char v : t) {
            if (nxt[c][v-'a'][b^1] == -1) return 0;
            c = nxt[c][v-'a'][b^1]+1;
            b ^= 1;
        }
        return (c&1)^(n&1)^1;
    };

    for (int b : {0, 1}) {
        if (get(b)){ cout << "YES\n"; return; }
    }
    cout << "NO\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}