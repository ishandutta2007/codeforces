#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

bool get(ll s, ll e, bool end) {
    ll bound = e+1;

    bool win[2];
    win[0] = win[1] = end;

    while (1) {
        ll l = (bound+1)/2, r = bound-1;

        if (!win[0]) {
            win[0] = win[1] = 1;
        } else {
            bool nxt = !win[r&1^1];
            if (nxt) win[r&1] = 1, win[r&1^1] = 0;
            else win[r&1] = 0, win[r&1^1] = 1;
        }

        if (l <= s && s <= r) {
            return win[s&1];
        }

        bound = l;
    }
}
void solve(){
    int n; cin >> n;

    bool prev_win = 0, prev_lose = 1;
    while (n--) {
        ll s, e; cin >> s >> e;

        bool first_win = get(s, e, true); //everything later is winning
        bool first_lose = get(s, e, false); //everything later is losing


        bool new_win = 0, new_lose = 0;
        if (first_win && prev_lose || !first_win && prev_win)
            new_win = 1;
        if (first_lose && prev_lose || !first_lose && prev_win)
            new_lose = 1;

        prev_win = new_win, prev_lose = new_lose;

    }
    cout << prev_win << ' ' << prev_lose << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}