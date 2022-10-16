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
const int maxk = 5;

int n, k, q, b[maxk], ALL, ans[1 << maxk][2];

struct Seg {
    int l, r, _max[1 << maxk], _min[1 << maxk];

    Seg() = default;

    Seg(int l, int r) : l(l), r(r) {
        reset(_max, 0xc0);
        reset(_min, 0x3f);
    }
} T[maxn << 2];

void update(int o, int u) {
    if (T[o].l == T[o].r) {
        REP(mask, ALL) {
            int now = 0;
            REP(i, k) now += b[i] * ((mask & (1 << i)) ? 1 : -1);
            T[o]._max[mask] = T[o]._min[mask] = now;
        }
    } else {
        int M = T[o].l + T[o].r >> 1;
        if (u <= M) update(o << 1, u);
        else update(o << 1 | 1, u);
        REP(mask, ALL) {
            T[o]._max[mask] = max(T[o << 1]._max[mask], T[o << 1 | 1]._max[mask]);
            T[o]._min[mask] = min(T[o << 1]._min[mask], T[o << 1 | 1]._min[mask]);
        }
    }
}

void query(int o, int l, int r) {
    if (l <= T[o].l && T[o].r <= r) {
        REP(mask, ALL) {
            ans[mask][0] = max(ans[mask][0], T[o]._max[mask]);
            ans[mask][1] = min(ans[mask][1], T[o]._min[mask]);
        }
        return;
    }
    int M = T[o].l + T[o].r >> 1;
    if (l <= M) query(o << 1, l, r);
    if (r > M) query(o << 1 | 1, l, r);
}

void dfs(int o, int l, int r) {
    T[o] = Seg(l, r);
    if (l == r) return;
    int m = l + r >> 1;
    dfs(o << 1, l, m);
    dfs(o << 1 | 1, m + 1, r);
}

int main() {
    dfs(1, 1, 1 << 18);
    scanf("%d%d", &n, &k);
    ALL = 1 << k;
    FOR(i, 1, n) {
        REP(j, k) scanf("%d", b + j);
        update(1, i);
    }
    scanf("%d", &q);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int u;
            scanf("%d", &u);
            REP(i, k) scanf("%d", b + i);
            update(1, u);
        } else {
            int l, r, ret = 0;
            scanf("%d%d", &l, &r);
            REP(mask, ALL) ans[mask][0] = 0xc0c0c0c0, ans[mask][1] = 0x3f3f3f3f;
            query(1, l, r);
            REP(mask, ALL) ret = max(ret, ans[mask][0] - ans[mask][1]);
            printf("%d\n", ret);
        }
    }
}