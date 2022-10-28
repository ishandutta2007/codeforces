#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

const int MAXA = 20;
int n, q, m=1, nxt[MAXN*MAXA][2], cnt[MAXN*MAXA];
bool has[MAXN];
int tot=0;

int get_sz(int c){ return (c == -1 ? 0 : cnt[c]); }
void solve(){
    cin >> n >> q;
    memset(nxt, -1, sizeof(nxt)), memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (has[x]) continue;
        has[x] = 1;

        int c=0;
        for (int j = MAXA-1; j >= 0; j--) {
            bool b = (x>>j)&1;
            if (nxt[c][b] == -1) nxt[c][b] = m++;
            cnt[nxt[c][b]]++, c = nxt[c][b];
        }
    }
    while (q--) {
        int x; cin >> x; tot ^= x;

        int c=0, ans = 0;
        for (int j = MAXA-1; j >= 0; j--) {
            bool b = (tot>>j)&1;
            int l=nxt[c][0^b], r=nxt[c][1^b];
            if (get_sz(l) == (1<<j)) c = r, ans ^= 1<<j;
            else c = l;
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}