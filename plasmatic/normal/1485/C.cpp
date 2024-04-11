// ./c-floor-and-mod.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

ll cntm(ll a, ll m) { // count multiples of 1..m in a
    ll res = 0, l = 1, r = 1, mulv = a;
    while (1) {
        bool done = false;
        if (r > m) r = m, done = true;
        if (r == a) done = true;

        // printf("a=%lld m=%lld l=%lld r=%lld mulv=%lld done=%d\n", a,m,l,r,mulv,done);

        res += mulv * max(0LL, r-l+1);
        if (done) return res;

        ll nxt = a / (r+1);
        mulv = nxt;
        l = r+1;
        r = a / mulv;
    }
}

ll cnt(ll l, ll r) {
    if (l > r) return 0;
    return r-l+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // printf("res=%lld\n", cntm(4, 4));
    // return 0;
    // cntm(4, 3);

    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        ll ans = 0;

        // fully covered
        ll full = 1;
        while ((full+1) * (full-1) <= a) {
            full++;
        } // overcount by 1
        full = min(full-1, (ll)b);
        ans += full * (full-1) / 2;
        // printf("a=%d b=%d full=%lld\n", a, b, full);
        // partial
        if (b+1 > full+1)
            ans += cntm(a, b+1) - cntm(a, full+1);

        cout << ans << '\n';
    }

    return 0;
}