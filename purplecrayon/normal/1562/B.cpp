#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

bool is_prime(ll x) {
    if (x == 1) return 0;
    for (ll i = 2; i*i <= x; i++) if (x%i == 0) return 0;
    return 1;
}
string s;
ll ans = -1;

void rec(ll mask, int c, int k) {
    if (ans != -1) return;
    if (c == sz(s)) {
        if (k) return;

        ll me = 0;
        for (int j = 0; j < sz(s); j++) if ((mask>>j)&1) me *= 10, me += s[j]-'0';
        if (!is_prime(me)) {
            ans = me;
        }
        return;
    }
    if (k) {
        rec(mask|(1ll<<c), c+1, k-1);
        if (ans != -1) return;
    }
    rec(mask, c+1, k);
}
void solve(){
    int n; cin >> n;
    cin >> s;

    ans = -1;
    for (int l = 1; ; l++) {
        rec(0, 0, l);
        if (ans != -1) {
            cout << l << '\n' << ans << '\n';
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}