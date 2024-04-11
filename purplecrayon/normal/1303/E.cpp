#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e2+10, MOD = 1e9+7;

int nxt[MAXN][26], dp[MAXN][MAXN];

void upd(int& a, int b) {
    if (a == -1) a = b;
    if (b == -1) return;
    a = min(a, b);
}
bool get(string s, string a, string b) {
    memset(nxt, -1, sizeof(nxt));
    for (int i = sz(s)-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][s[i]-'a'] = i;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <= sz(a); i++) {
        for (int j = 0; j <= sz(b); j++) {
            int me = dp[i][j];
            if (me == -1) continue;

            if (i < sz(a) && nxt[me][a[i]-'a'] != -1) {
                upd(dp[i+1][j], nxt[me][a[i]-'a']+1);
            }
            if (j < sz(b) && nxt[me][b[j]-'a'] != -1) {
                upd(dp[i][j+1], nxt[me][b[j]-'a']+1);
            }
        }
    }
    return dp[sz(a)][sz(b)] != -1;
}
void solve(){
    string s, t; cin >> s >> t;
    for (int i = 1; i <= sz(t); i++) {
        string a = t.substr(0, i), b = "";
        if (i < sz(t)) b = t.substr(i, sz(t)-i);
        if (get(s, a, b)) {
            cout << "YES\n";
            return;
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