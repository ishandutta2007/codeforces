#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c, r = 0;
    while((c = gc) < 48);
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}
void wrt(int x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[11]; int sz = 0;
    if(x < 0) pc(45), x = -x;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(10);
}

const int N = 1e5 + 5, M = 1 << 18;

int n, q, p[N << 1], pos[N << 1];
ll sum1, sum2;
struct node {
    int x; ll y;
    node operator+(const node& b)const {
        return {x + b.x, max(y, b.y - ((ll)x << 32))};
    }
} c[M << 1];
inline void pu(int o) { c[o] = c[o << 1] + c[o << 1 | 1]; }
inline int nxt1(int i) { return i < n + 1 ? i + 1 : 1; }
inline int nxt2(int i) { return i < n * 2 + 1 ? i + 1 : n + 1; }
int dis1(int i) {
    int res = pos[i] - pos[i > 1 ? i - 1 : n + 1];
    return res < 0 ? res + n * 2 + 1 : res;
}
int dis2(int i) {
    int res = pos[i] - pos[i > n + 1 ? i - 1 : n * 2 + 1];
    return res < 0 ? res + n * 2 + 1 : res;
}
void upd1(int x, int y, int v) {
    if(x <= n + 1) sum1 += v * (dis1(x) + (nxt1(x) != y ? dis1(nxt1(x)) : 0));
    if(y <= n + 1) sum1 += v * (dis1(y) + (nxt1(y) != x ? dis1(nxt1(y)) : 0));
}
void upd2(int x, int y, int v) {
    if(x >= n + 1) sum2 += v * (dis2(x) + (nxt2(x) != y ? dis2(nxt2(x)) : 0));
    if(y >= n + 1) sum2 += v * (dis2(y) + (nxt2(y) != x ? dis2(nxt2(y)) : 0));
}
void init(int i) {
    if(p[i] < n + 1) c[M + i] = {-1, 1LL << 32 | i + 1};
    if(p[i] > n + 1) c[M + i] = {1, i};
    if(p[i] == n + 1) c[M + i] = {};
}
void upd(int i) {
    for(init(i), i += M; i > 1; pu(i >>= 1));
}
node __qry(int l, int r) {
    node L = {}, R = {};
    for(l += M - 1, r += M + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
        if(~l & 1) L = L + c[l ^ 1];
        if(r & 1) R = c[r ^ 1] + R;
    }
    return L + R;
}
bool chk(int l, int r) {
    node res = l <= r ? __qry(l, r) : __qry(l, n * 2 + 1) + __qry(1, r);
    return res.x == 0 && res.y <= INT_MAX;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    rep(i, 1, n << 1 | 1) pos[p[i] = read()] = i, init(i);
    rep(i, 1, n + 1) sum1 += dis1(i);
    rep(i, n + 1, n * 2 + 1) sum2 += dis2(i);
    per(i, M - 1, 1) pu(i);
    int u, v;
    while(q--) {
        u = read(), v = read();
        int pu = p[u], pv = p[v];
        upd1(pu, pv, -1), upd2(pu, pv, -1);
        swap(p[u], p[v]), swap(pos[pu], pos[pv]), upd(u), upd(v);
        upd1(pu, pv, 1), upd2(pu, pv, 1);
        int l = (int)c[1].y, k = pos[n + 1], ans = -1;
        if(l > n * 2 + 1) l = 1;
        if(chk(l, k) && chk(k, l - 1)) {
            if(sum1 > n * 2 + 1) ans = k == n * 2 + 1 ? 0 : k;
            if(sum2 > n * 2 + 1) ans = k - 1;
        } else ans = l - 1;
        wrt(ans);
    }
}