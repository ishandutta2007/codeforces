#include <bits/stdc++.h>
#include <immintrin.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l + r) >> 1)
#define lch l, mid, lc
#define rch mid + 1, r, rc
#pragma GCC target("avx2")

using namespace std;
using ll = long long;
using ymm = __m256i;
using ptr = ymm*;

const int N = 1e5 + 5, M = 1 << 17, inf = 0x3f3f3f3f;

int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0;
    while(c < 48) c = gc;
    if(c > 57) return c;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}
void wrt(int x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[11]; int sz = 0;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(10);
}

int n, m, q;
bool s[4][N];
struct {
    int c[M * 2 + 5][2];
    bool t[M * 2 + 5];
    void pu(int o) {
        c[o][t[o]] = c[lc][0] + c[rc][0], c[o][!t[o]] = c[lc][1] + c[rc][1];
    }
    void flip(int l, int r) {
        for(l += M - 1, r += M + 1; l ^ r ^ 1; pu(l >>= 1), pu(r >>= 1)) {
            if(~l & 1) swap(c[l ^ 1][0], c[l ^ 1][1]), t[l ^ 1] ^= 1;
            if(r & 1) swap(c[r ^ 1][0], c[r ^ 1][1]), t[r ^ 1] ^= 1;
        }
        while(l) pu(l >>= 1);
    }
    void bld(bool a[], int n) {
        rep(i, 1, n) c[M | i][0] = a[i], c[M | i][1] = !a[i];
        per(i, M - 1, 1) pu(i);
    }
} T[4];
struct {
    alignas(64) int c[M * 2 + 5][2][2][4];
    char t[M * 2 + 5];
    ymm idx[4];
    void put(int o, int v) {
        ymm perm = idx[v];
        t[o] ^= v;
        *(ptr)c[o][0] = _mm256_permutevar8x32_epi32(*(ptr)c[o][0], perm);
        *(ptr)c[o][1] = _mm256_permutevar8x32_epi32(*(ptr)c[o][1], perm);
    }
    void pu(int o) {
        ymm a = *(ptr)c[lc][0], b = *(ptr)c[lc][1], x = *(ptr)c[rc][0], y = *(ptr)c[rc][1];
        ymm perm = idx[t[o]];
        ymm a0 = _mm256_permute4x64_epi64(a, 0x44), a1 = _mm256_permute4x64_epi64(a, 0xee);
        ymm b0 = _mm256_permute4x64_epi64(b, 0x44), b1 = _mm256_permute4x64_epi64(b, 0xee);
        ymm p = _mm256_min_epi32(_mm256_add_epi32(a0, x), _mm256_add_epi32(a1, y));
        ymm q = _mm256_min_epi32(_mm256_add_epi32(b0, x), _mm256_add_epi32(b1, y));
        *(ptr)c[o][0] = _mm256_permutevar8x32_epi32(p, perm);
        *(ptr)c[o][1] = _mm256_permutevar8x32_epi32(q, perm);
    }
    void flip(int l, int r, int v) {
        for(l += M - 1, r += M + 1; l ^ r ^ 1; pu(l >>= 1), pu(r >>= 1)) {
            if(~l & 1) put(l ^ 1, v);
            if(r & 1) put(r ^ 1, v);
        }
        while(l > 1) pu(l >>= 1);
    }
    void bld(bool a[], bool b[], int w, int n) {
        rep(i, 0, 3) {
            alignas(32) int tmp[8];
            rep(j, 0, 7) tmp[j] = j ^ i;
            idx[i] = *(ptr)tmp;
        }
        rep(j, 0, M) rep(i, 0, 3) c[j + M][0][1][i] = c[j + M][1][0][i] = inf;
        rep(j, 1, n) rep(i, 0, 3) {
            int s0 = a[j] ^ (i & 1), s1 = b[j] ^ (i >> 1);
            c[j | M][0][0][i] = s0 + s1;
            c[j | M][0][1][i] = w + !s0 + !s1;
            c[j | M][1][0][i] = w + s0 + s1;
            c[j | M][1][1][i] = !s0 + !s1;
        }
        per(i, M - 1, 1) pu(i);
    }
} A, B;
void solve() {
    int ans = 1e9;
    rep(i, 0, 1) rep(j, 0, 1) ans = min({ans,
        T[2].c[1][i] + A.c[1][i][j][0] + T[3].c[1][j],
        T[0].c[1][i] + B.c[1][i][j][0] + T[1].c[1][j],
    });
    wrt(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    rep(i, 0, 1) {
        rep(j, 1, n) s[i][j] = read() == 'R';
        T[i].bld(s[i], n);
    }
    rep(i, 2, 3) {
        rep(j, 1, m) s[i][j] = read() == 'R';
        T[i].bld(s[i], m);
    }
    A.bld(s[0], s[1], m, n), B.bld(s[2], s[3], n, m);
    solve();
    int t, l, r;
    while(q--) {
        t = read(), l = read(), r = read();
        t = t == 'L' ? 0 : t == 'R' ? 1 : t == 'U' ? 2 : 3;
        T[t].flip(l, r);
        if(t < 2) A.flip(l, r, t + 1);
        else B.flip(l, r, t - 1);
        solve();
    }
}