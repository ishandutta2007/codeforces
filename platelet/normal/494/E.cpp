#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

struct {
    int x, l, r, v;
    bool operator <(auto b)const {
        return x < b.x;
    }
} r[N];

int n, m, k, lim;
alignas(64) int pr[1 << 18], c[1 << 18][2];
ll g[N];

inline void pu(int o) {
    c[o][0] = c[o][1] ? pr[o] : o < lim ? c[o << 1][0] ^ c[o << 1 | 1][0] : 0;
}
void add(int l, int r, int v) {
    for(l += lim - 1, r += lim + 1; l ^ r ^ 1; pu(l >>= 1), pu(r >>= 1)) {
        if(~l & 1) c[l ^= 1][1] += v, pu(l);
        if(r & 1) c[r ^= 1][1] += v, pu(r);
    }
    while(l > 1) pu(l >>= 1);
}
int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0;
    while(c < 48) c = gc;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    int a, b, c, d, p = 0;
    rep(i, 1, m) {
        a = read(), b = read(), c = read(), d = read();
        g[p] = uint64_t(b - 1) << 32 | &r[p].l - (int*)r;
        g[p + 1] = uint64_t(d) << 32 | &r[p].r - (int*)r;
        r[p].x = a - 1, r[p].v = 1;
        r[p + 1].x = c, r[p + 1].v = -1, p += 2;
    }
    sort(g, g + p);
    int idx = 1;
    pr[1] = g[1] >> 32;
    For(i, 0, p) {
        auto ptr = (int*)r + (int)g[i];
        if(i && ((g[i] ^ g[i - 1]) & UINT64_MAX - UINT32_MAX)) pr[lim + ++idx] = (g[i] ^ g[i - 1]) >> 32;
        ptr[0] = ptr[4] = idx;
    }
    sort(r, r + p);
    for(lim = 1; lim <= idx; lim <<= 1);
    memcpy(pr + lim, pr, idx + 1 << 2);
    per(i, lim - 1, 1) pr[i] = pr[i << 1] ^ pr[i << 1 | 1];
    int ls = 0, ans = 0;
    For(i, 0, p) {
        ans ^= (r[i].x ^ ls) & ::c[1][0], ls = r[i].x;
        add(r[i].l + 1, r[i].r, r[i].v);
    }
    cout << (ans & (2 << __lg(k)) - 1 ? "Hamed" : "Malek");
}