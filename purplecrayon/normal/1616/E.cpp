#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

template<class T>
struct FT {
    vector<T> bit;
    FT(int n) : bit(n) {}
    FT(){}
    void upd(int i, T x) {
        for (; i < sz(bit); i |= i+1) bit[i] += x;
    }
    T qry(int r) {
        T ans = T();
        for (++r; r > 0; r &= r-1) ans += bit[r-1];
        return ans;
    }
    T qry(int l, int r) {
        return qry(r)-qry(l-1);
    }
};
void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    set<int> pos[26];
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].insert(i);
    }
    FT<int> bit(n);
    ll ans = INF;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        int use = n;
        for (int c = 0; c < t[i] - 'a'; c++) {
            if (sz(pos[c])) {
                use = min(use, *pos[c].begin());
            }
        }
        if (use < n) {
            ans = min(ans, cur + (use + bit.qry(use+1, n-1)) - i);
        }

        if (sz(pos[t[i] - 'a'])) {
            int use = *pos[t[i] - 'a'].begin();
            cur += (use + bit.qry(use+1, n-1)) - i;
            bit.upd(use, +1);
            pos[t[i] - 'a'].erase(use);
        } else {
            break;
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}