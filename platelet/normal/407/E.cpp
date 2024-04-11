#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)
#define lch l, mid, lc
#define rch mid + 1, r, rc

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, k, d, a[N], L0[N], L1[N];
ll c[N * 4], t[N * 4];

void pu(int o) { c[o] = min(c[lc], c[rc]); }
void put(int o, ll v) { c[o] += v, t[o] += v; }
void pd(int o) {
    if(t[o]) put(lc, t[o]), put(rc, t[o]), t[o] = 0;
}
void bld(int l, int r, int o) {
    c[o] = (ll)d * l;
    if(l < r) bld(lch), bld(rch);
}
void add(int L, int R, ll v, int l, int r, int o) {
    if(L <= l && r <= R) return put(o, v);
    pd(o);
    if(L <= mid) add(L, R, v, lch);
    if(R > mid) add(L, R, v, rch);
    pu(o);
}
int qry(int L, ll v, int l, int r, int o) {
    if(c[o] > v) return 0;
    if(l == r) return l;
    pd(o);
    int res = L <= mid ? qry(L, v, lch) : 0;
    return res ? res : qry(L, v, rch);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> d;
    int L = 1, l = 1, r = 0;
    if(!d) rep(i, 1, n) {
        cin >> a[i];
        if(a[i] != a[i - 1]) L = i;
        if(i - L > r - l) l = L, r = i;
    } else {
        bld(1, n, 1);
        map<int, int> lst;
        rep(i, 1, n) {
            cin >> a[i];
            if((a[i] - a[i - 1]) % d) L = i;
            L = max(L, lst[a[i]] + 1), lst[a[i]] = i;
            for(int& j = L0[i] = i - 1; j && a[j] <= a[i]; j = L0[j])
                add(L0[j] + 1, j, a[i] - a[j], 1, n, 1);
            for(int& j = L1[i] = i - 1; j && a[j] >= a[i]; j = L1[j])
                add(L1[j] + 1, j, a[j] - a[i], 1, n, 1);
            int j = qry(L, d * ll(k + i), 1, n, 1);
            if(i - j > r - l) l = j, r = i;
        }
    }
    cout << l << ' ' << r;
}