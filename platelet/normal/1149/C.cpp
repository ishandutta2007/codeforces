#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define mid ((l + r) / 2)
#define lc o * 2
#define rc o * 2 + 1
#define lch l, mid, lc
#define rch mid + 1, r, rc

using namespace std;

const int N = 2e5 + 5;

int n, q, a[N];
char s[N];
int t[N * 4], mi[N * 4], ma[N * 4], cl[N * 4], cr[N * 4], c[N * 4];

void pu(int o) {
    mi[o] = min(mi[lc], mi[rc]), ma[o] = max(ma[lc], ma[rc]);
    cl[o] = max({cl[lc], cl[rc], ma[lc] - 2 * mi[rc], -mi[o]});
    cr[o] = max({cr[lc], cr[rc], ma[rc] - 2 * mi[lc], -mi[o]});
    c[o] = max({c[lc], c[rc], cl[lc] + ma[rc], cr[rc] + ma[lc]});
}
void put(int o, int v) {
    mi[o] += v, ma[o] += v, cl[o] -= v, cr[o] -= v, t[o] += v;
}
void pd(int o) {
    if(t[o]) put(lc, t[o]), put(rc, t[o]), t[o] = 0;
}
void bld(int l, int r, int o) {
    if(l == r) {
        a[l] = a[l - 1] + (s[l] == '(' ? 1 : -1);
        mi[o] = ma[o] = a[l], cl[o] = cr[o] = -a[l];
    } else bld(lch), bld(rch), pu(o);
}
void upd(int L, int R, int v, int l, int r, int o) {
    if(L <= l && r <= R) return put(o, v);
    pd(o);
    if(L <= mid) upd(L, R, v, lch);
    if(R > mid) upd(L, R, v, rch);
    pu(o);
}

int main() {
    scanf("%d%d%s", &n, &q, s + 1), n = n * 2 - 2;
    bld(1, n, 1), printf("%d\n", c[1]);
    int a, b;
    while(q--) {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        if(s[a] != s[b]) upd(a, b - 1, s[a] == '(' ? -2 : 2, 1, n, 1);
        swap(s[a], s[b]), printf("%d\n", c[1]);
    }
}