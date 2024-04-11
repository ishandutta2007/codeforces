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

const int maxn = 112345;

struct Seg {
    int l, r, val, cnt;
} T[maxn << 2];

int s[maxn], n, t;

inline void push_up(int o) {
    int lson = o << 1, rson = o << 1 | 1;
    if (T[lson].val < 0 || T[rson].val < 0) {
        T[o].val = -1;
        T[o].cnt = 0;
        return;
    }
    T[o].val = __gcd(T[lson].val, T[rson].val);
    T[o].cnt = 0;
    if (T[o].val == T[lson].val) T[o].cnt += T[lson].cnt;
    if (T[o].val == T[rson].val) T[o].cnt += T[rson].cnt;
}

void build(int o, int l, int r) {
    T[o].l = l, T[o].r = r;
    if (l == r) {
        if (l <= n) {
            T[o].val = s[l];
            T[o].cnt = 1;
        } else T[o].val = -1;
    } else {
        int m = l + r >> 1;
        build(o << 1, l, m);
        build(o << 1 | 1, m + 1, r);
        push_up(o);
    }
}

pii query(int o, int l, int r) {
    if (l <= T[o].l && T[o].r <= r) return {T[o].val, T[o].cnt};
    int m = T[o].l + T[o].r >> 1;
    pii res[2] = {};
    if (l <= m) res[0] = query(o << 1, l, r);
    if (r > m) res[1] = query(o << 1 | 1, l, r);
    int g = __gcd(res[0]._1, res[1]._1), ret = 0;
    REP(i, 2) if (res[i]._1 == g) ret += res[i]._2;
    return {g, ret};
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", s + i);
    build(1, 1, 1 << 17);
    scanf("%d", &t);
    while (t--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", r - l + 1 - query(1, l, r)._2);
    }
}