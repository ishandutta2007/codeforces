#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

bool is_prime(int x) {
    for (int i = 2; i*i <= x; i++) if (x % i == 0) return 0;
    return 1;
}


const int P = 62;
int mobius[P], pf[P];
int get_mul(int c) {
    int ans = 0;
    while (c > 1) {
        int p = pf[c];
        c /= p;
 
        if (c%p == 0)
            return 0;
 
        ans ^= 1;
    }
    return (ans == 0 ? -1 : +1);
}
void pre() {
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < P; i++) if (pf[i] == -1) {
        for (int j = i; j < P; j += i) pf[j] = i;
    }
    for (int i = 0; i < P; i++) {
        mobius[i] = get_mul(i);
    }
}
#define ll __int128
ll po(ll b, int p) {
    ll ans = 1;
    for (; p; b=b*b, p>>=1) if (p&1) ans *= b;
    return ans;
}
ll pth_root(ll x, int p) {
    // floor(x ^ (1 / p))
    ll ans = floor(pow(x, (double) 1 / p));
    while (po(ans, p) > x) ans--;
    while (po(ans, p) <= x) ans++;
    ans--;

    return (long long) ans;
}
#undef ll

ll get(ll x) {
    ll ans = 1;
    for (int p = 2; p < P; p++) {
        ll mx = pth_root(x, p);
        ans += max(mx-1, 0LL) * mobius[p];
    }
    return ans;
}
void solve() {
    ll l, r; cin >> l >> r;
    ll ans = get(r);
    if (l > 1) ans -= get(l-1);

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    pre();

    int T=1;
    cin >> T;
    while (T--) solve();
}