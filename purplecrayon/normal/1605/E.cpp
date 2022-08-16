#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

// c = b - a
//
// inc[1] = -c[1] -> -x
// inc[2] = -c[2] - (-c[1]) = -c[2] + c[1] -> +x
// inc[3] = -c[3] - (-c[1]) = -c[3] + c[1] -> +x
// inc[4] = -c[4] - (-c[1] -c[2]+c[1]) = -c[4] + c[2]
// inc[6] = -c[6] - (-c[1] -c[2]+c[1] -c[3]+c[1]) = -c[6] - (-c[2] -c[3] +c[1]) = -c[6] + c[2] + c[3] - c[1]
//
// inc[8] = -c[8] - (-c[1] -c[2]+c[1] -c[4]+c[2]) = -c[8] + c[4]
// inc[12] = -c[12] - (-c[1] -c[2]+c[1] -c[3]+c[1]
//

struct SRQ {
    vector<pair<ll, ll>> v;
    void upd(ll l, ll r, ll x) {
        v.emplace_back(l, +x);
        v.emplace_back(r+1, -x);
    }
    void bld() {
        sort(v.begin(), v.end());
        for (int i = 1; i < sz(v); i++) v[i].second += v[i-1].second;
    }
    ll qry(ll x) {
        int i = upper_bound(v.begin(), v.end(), make_pair(x, std::numeric_limits<ll>::max())) - v.begin() - 1;
        if (i < 0) return 0;
        return v[i].second;
    }
} pos_sum, pos_contrib, neg_sum, neg_contrib;

int n;
ll c[MAXN], change[MAXN], contrib[MAXN];
ll base = 0, one = -1;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (i == 0) one = a;
        else c[i] -= a;
    }
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        c[i] += b;
    }
    contrib[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 2*(i+1); j <= n; j += i+1) {
            contrib[j-1] -= contrib[i];
        }
    }
    for (int i = 0; i < n; i++) change[i] = c[i];

    for (int i = 1; i < n; i++) {
        base += abs(change[i]);
        for (int j = 2*(i+1); j <= n; j += i+1) change[j-1] -= change[i];
    }

    const int MX = 2e6+10;

    ll pos = 0, neg = 0;
    for (int i = 1; i < n; i++) {
        if (contrib[i] == 0) continue;
        for (ll sign : {1, -1}) {
            ll fake_cur = sign * contrib[i];
            if ((fake_cur < 0 && change[i] <= 0) || (fake_cur > 0 && change[i] >= 0)) {
                if (sign == 1) pos += abs(contrib[i]);
                else neg += abs(contrib[i]);
            } else {
                ll a = abs(contrib[i]), b = abs(change[i]);
                // largest x such that a*x <= b
                // b/a
                ll x = b / a;
                if (sign == 1) {
                    pos_contrib.upd(0, x, -a);

                    pos_contrib.upd(x+1, MX, a);
                    pos_sum.upd(x+1, MX, -2*b);
                } else {
                    neg_contrib.upd(0, x, -a);

                    neg_contrib.upd(x+1, MX, a);
                    neg_sum.upd(x+1, MX, -2*b);
                }
            }
        }
    }

    pos_contrib.bld();
    pos_sum.bld();
    neg_contrib.bld();
    neg_sum.bld();

    int q; cin >> q;
    while (q--) {
        ll x; cin >> x;
        ll me = x - one;
        
        ll ans = abs(one - x) + base;
        if (me == 0) { cout << ans << '\n'; continue; }
        else if (me < 0) {
            ans += neg * abs(me) + neg_contrib.qry(abs(me)) * abs(me) + neg_sum.qry(abs(me));
        } else {
            ans += pos * abs(me) + pos_contrib.qry(me) * abs(me) + pos_sum.qry(me);
        }

        /*
        for (int i = 1; i < n; i++) {
            if (contrib[i] == 0) continue;
            ll cur = me*contrib[i];
            if ((cur < 0 && change[i] <= 0) || (cur > 0 && change[i] >= 0)) {
                ans += abs(cur);
            } else if (abs(cur) <= abs(change[i])) {
                ans += -abs(cur);
            } else {
                ans += abs(cur) - 2*abs(change[i]);
            }
        }
        */

        // if me * contrib has the same sign as change, ans += abs(me*contrib)
        // else if abs(me * contrib) < abs(change), ans += -abs(me*contrib)
        // else ans += abs(me*contrib) - 2*abs(change)
        
        // abs(x+y), x < 0, y > 0
        // y < x, ans -= y
        // y >= x, ans += y-2*x

        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}

// 2 -1 2 1 0 -1