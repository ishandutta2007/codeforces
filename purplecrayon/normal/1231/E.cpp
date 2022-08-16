#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e2+10, MOD = 1e9+7;

string sorted(string s) {
    sort(s.begin(), s.end());
    return s;
}
int nxt[N][26];
void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (sorted(s) != sorted(t)) {
        cout << -1 << '\n';
        return;
    }
    memset(nxt, -1, sizeof(nxt));
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i+1][j];
        }
        nxt[i][s[i]-'a'] = i;
    }
    int ans = 0;
    for (int l = 0; l < n; l++) {
        int c = 0;
        for (int r = l; r < n; r++) {
            // cout << c << ' ' << t[r]-'a' << ' ' << nxt[c][t[r] - 'a'] << endl;
            if (nxt[c][t[r] - 'a'] == -1) break;
            // cout << c << ' ' << l << ' ' << r  << endl;
            ans = max(ans, r - l + 1);
            c = nxt[c][t[r] - 'a'] + 1;
            if (!c || c == n) break;
            // stays the same in s
        }
    }
    cout << n - ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}