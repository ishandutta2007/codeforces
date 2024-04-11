#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
ll T, N, bd[100005], pref[100005], segtree[400005], lazy[400005];
ii cost[100005];
map<ll, ll> mp;
void build(ll node, ll tl, ll tr) {
    if (tl == tr) {
        segtree[node] = pref[tl];
        return;
    }
    ll c = (tl + tr) / 2;
    build(node * 2, tl, c); build(node * 2 + 1, c + 1, tr);
    segtree[node] = min(segtree[node * 2], segtree[node * 2 + 1]);
}
void upd(ll node, ll tl, ll tr, ll le, ll ri, ll val) {
    if (lazy[node] != 0) {
        segtree[node] += lazy[node];
        if (tl != tr) {
            lazy[node * 2] += lazy[node]; lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (tl > ri || le > tr) return;
    if (le <= tl && tr <= ri) {
        lazy[node] = val;
        segtree[node] += lazy[node];
        if (tl != tr) {
            lazy[node * 2] += lazy[node]; lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    } else {
        ll c = (tl + tr) / 2;
        upd(node * 2, tl, c, le, ri, val); upd(node * 2 + 1, c + 1, tr, le, ri, val);
        segtree[node] = min(segtree[node * 2], segtree[node * 2 + 1]);
    }
}
ll query(ll node, ll tl, ll tr, ll le, ll ri) {
    if (tl > ri || le > tr) return 1e18;
    if (lazy[node] != 0) {
        segtree[node] += lazy[node];
        if (tl != tr) {
            lazy[node * 2] += lazy[node]; lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (le <= tl && tr <= ri) {
        return segtree[node];
    } else {
        ll c = (tl + tr) / 2;
        return min(query(node * 2, tl, c, le, ri), query(node * 2 + 1, c + 1, tr, le, ri));
    }
}
int main() {
    cin >> T >> N;
    for (int i = 0; i < T; i++) {
        cin >> bd[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i].fi;
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i].se;
    }
    sort(cost, cost + N);
    for (int i = T - 1, cur = 0; i >= 0; i--) {
        while (cur < N && cost[cur].fi <= bd[i])
            mp[cost[cur++].fi] = i;
    }
    for (int i = 0; i < T; i++) {
        pref[i] = bd[i] + ((i > 0)? pref[i - 1] : 0);
    }
    // cout << "kkk";
    build(1, 0, T - 1);
    sort(cost, cost + N, [](ii &a, ii &b) {
        return a.se < b.se || (a.se == b.se && a.fi < b.fi);
    });
    // cout << "lll";
    ll ans = 0;
    T--;
    for (int i = 0; i < N; i++) {
        if (!mp.count(cost[i].fi)) continue;
        if (query(1, 0, T, mp[cost[i].fi], T) >= cost[i].se) {
            upd(1, 0, T, mp[cost[i].fi], T, -cost[i].se);
            ans++;
        }
    }
    cout << ans << endl;
}