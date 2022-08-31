#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int d[10][10];
int cnt[10][10];

void solve() {
    string s; cin >> s;
    for (int i = 0; i < sz(s)-1; i++) {
        int a = s[i]-'0', b = s[i+1]-'0';
        cnt[a][b]++;
    }

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            for (int a = 0; a < 10; a++) for (int b = 0; b < 10; b++) d[a][b] = MOD;

            for (int one = 0; one < 10; one++) for (int two = 0; two < 10; two++) if (one || two) {
                for (int seed = 0; seed < 10; seed++) {
                    int new_val = (seed + one*x + two*y)%10;
                    d[seed][new_val] = min(d[seed][new_val], one + two);
                }
            }
            ll ans = 0;
            for (int a = 0; a < 10 && ans != -1; a++) {
                for (int b = 0; b < 10 && ans != -1; b++) if (cnt[a][b]) {
                    if (d[a][b] == MOD) { ans = -1; break; }
                    ans += (long long) (d[a][b] - 1) * cnt[a][b];
                }
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}