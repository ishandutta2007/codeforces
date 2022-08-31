#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

const int MAXA = 27;

int q, m=1, nxt[MAXN*MAXA][2], cnt[MAXN*MAXA];

void solve(){
    cin >> q;

    memset(nxt, -1, sizeof(nxt)), memset(cnt, 0, sizeof(cnt));
    auto add = [&](int x, int delta) {
        int c = 0;
        for (int i = MAXA-1; i >= 0; i--) {
            bool b = (x>>i)&1;
            if (nxt[c][b] == -1) nxt[c][b] = m++;
            c = nxt[c][b], cnt[c] += delta;
        }
    };
    auto get_sz = [&](int c) {
        return c == -1 ? 0 : cnt[c];
    };

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            add(x, +1);
        } else if (t == 2) {
            int x; cin >> x;
            add(x, -1);
        } else {
            int x, y; cin >> x >> y;

            int ans = 0, c = 0;
            for (int i = MAXA-1; i >= 0; i--) {
                bool b = (x>>i)&1;
                bool side = (y>>i)&1;
                if (side) {
                    ans += get_sz(nxt[c][b]);
                }
                bool next_b = b^side;
                if (nxt[c][next_b] == -1) nxt[c][next_b] = m++;
                c = nxt[c][next_b];
            }
            cout << ans << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}