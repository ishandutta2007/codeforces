#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
const ll maxn = 3e5 + 5;
pair<ll, ll> t[4 * maxn];
ll f[maxn], c[maxn];
void bld(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = {c[tl], -tl};
        return;
    }
    ll left = v << 1, right = left | 1, mid = (tl + tr) >> 1;
    bld(left, tl, mid);
    bld(right, mid + 1, tr);
    t[v] = min(t[left], t[right]);
}
pair<ll, ll> qry(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > tr || r < tl) return {1e16, 1e16};
    if (l <= tl && tr <= r) return t[v];
    ll left = v << 1, right = left | 1, mid = (tl + tr) >> 1;
    pair<ll, ll> q1 = qry(left, tl, mid, l, r);
    pair<ll, ll> q2 = qry(right, mid + 1, tr, l, r);
    return min(q1, q2);
}

void upd(ll v, ll tl, ll tr, ll p) {
    if (tl == p && tr == p) {
        t[v] = {1e16, 1e16};
        return;
    }
    ll left = v << 1, right = left | 1, mid = (tl + tr) >> 1;
    if (p <= mid) upd(left, tl, mid, p);
    else upd(right, mid + 1, tr, p);
    t[v] = min(t[left], t[right]);
}


void solve() {
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }
    for (ll i = 0; i < m; i++) {
        cin >> c[i];
    }
    sort(f, f + n, [&](ll x, ll y){
       return c[x] > c[y];
    });
    ll ans = 0;
    bld(1, 0, m - 1);
    for (ll i = 0; i < n; i++) {
        pair<ll, ll> x = qry(1, 0, m - 1, 0, f[i]);
        if (x.first == 1e16) ans += c[f[i]];
        else ans += x.first, upd(1, 0, m - 1, -x.second);

    }
    cout << ans << '\n';

}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll test; cin >> test; while(test--)

    solve();

}