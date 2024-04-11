#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 212345;

struct Seg {
    int l, r;
    ll val, lzy;
} T[maxn << 2];

void build(int o, int l, int r) {
    T[o].l = l, T[o].r = r;
    if (l < r) {
        int m = l + r >> 1;
        build(o << 1, l, m);
        build(o << 1 | 1, m + 1, r);
    }
}

inline void push_down(int o) {
    T[o << 1].lzy += T[o].lzy, T[o << 1 | 1].lzy += T[o].lzy;
    T[o].lzy = 0;
}

inline void push_up(int o) {
    T[o].val = min(T[o << 1].val + T[o << 1].lzy, T[o << 1 | 1].val + T[o << 1 | 1].lzy);
}

void add(int o, int l, int r, int v) {
    if (l <= T[o].l && T[o].r <= r) {
        T[o].lzy += v;
        return;
    }
    int m = T[o].l + T[o].r >> 1;
    push_down(o);
    if (l <= m) add(o << 1, l, r, v);
    if (r > m) add(o << 1 | 1, l, r, v);
    push_up(o);
}

ll query(int o, int l, int r) {
    if (l <= T[o].l && T[o].r <= r) return T[o].val + T[o].lzy;
    int m = T[o].l + T[o].r >> 1;
    push_down(o);
    ll ret = 1e15;
    if (l <= m) ret = min(ret, query(o << 1, l, r));
    if (r > m) ret = min(ret, query(o << 1 | 1, l, r));
    push_up(o);
    return ret;
}

int n, m;

int main() {
    build(1, 1, 1 << 18);
    scanf("%d", &n);
    FOR(i, 1, n) {
        int v;
        scanf("%d", &v);
        add(1, i, i, v);
    }
    scanf("%d", &m);
    while (m--) {
        int l, r, v = 1e9;
        scanf("%d %d", &l, &r);
        if (getchar() == ' ') scanf("%d", &v);
        vector<pii> lis;
        l++, r++;
        if (l > r) {
            lis.eb(l, n);
            lis.eb(1, r);
        } else lis.eb(l, r);
        if (v > 1e8) {
            ll ans = 1e15;
            for (auto it : lis) ans = min(ans, query(1, it._1, it._2));
            printf("%lld\n", ans);
        } else for (auto it : lis) add(1, it._1, it._2, v);
    }
}