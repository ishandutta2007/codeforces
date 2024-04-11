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
    int c = gc, r = 0;
    while(c < 48) c = gc;
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

const int N = 3e5 + 5, P = 1e9 + 7;

int n, q, idx, d[N], fa[N], sz[N], son[N], tp[N], dfn[N];
int bas[N << 1], val[N << 1];
char ch[N], s[N << 1];
vector<int> G[N];

int sh(int s, int l) {
    int res = val[s + l - 1] - (ll)val[s - 1] * bas[l] % P;
    return res < 0 ? res + P : res;
}
void dfs1(int u) {
    sz[u] = 1;
    for(int v : G[u]) if(v != fa[u]) {
        fa[v] = u, d[v] = d[u] + 1, dfs1(v), sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int top) {
    tp[u] = top, dfn[u] = ++idx;
    s[idx] = ch[u - 1];
    if(son[u]) dfs2(son[u], top);
    for(int v : G[u]) if(v != fa[u] && v != son[u]) dfs2(v, v);
}
int split(int u, int v, int l[], int r[]) {
    static int L[100], R[100];
    int p1 = 0, p2 = 0;
    bool rev = 0;
    auto push = [&](int a, int b) {
        if(rev) L[++p2] = b, R[p2] = a;
        else l[++p1] = n * 2 + 1 - a, r[p1] = n * 2 + 1 - b;
    };
    for(; tp[u] != tp[v]; push(dfn[u], dfn[tp[u]]), u = fa[tp[u]])
        if(d[tp[u]] < d[tp[v]]) swap(u, v), rev ^= 1;
    if(d[u] < d[v]) swap(u, v), rev ^= 1;
    push(dfn[u], dfn[v]);
    while(p2) l[++p1] = L[p2], r[p1] = R[p2--];
    return p1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> ch;
    int u, v, a, b;
    rep(i, 2, n) u = read(), v = read(), G[u].pb(v), G[v].pb(u);
    dfs1(1), dfs2(1, 1);
    reverse_copy(s + 1, s + n + 1, s + n + 1);
    rep(i, 0, n << 1) bas[i] = i ? (ll)bas[i - 1] * 131 % P : 1;
    rep(i, 1, n << 1) val[i] = ((ll)val[i - 1] * 131 + s[i]) % P;
    q = read();
    while(q--) {
        u = read(), v = read(), a = read(), b = read();
        if(ch[u - 1] != ch[a - 1]) { wrt(0); continue; }
        static int l1[100], r1[100], l2[100], r2[100];
        int c1 = split(u, v, l1, r1), c2 = split(a, b, l2, r2), ans = 0;
        for(int i = 1, j = 1; i <= c1 && j <= c2; ) {
            int len = min(r1[i] - l1[i], r2[j] - l2[j]) + 1;
            if(sh(l1[i], len) == sh(l2[j], len))
                ans += len, l1[i] += len, l2[j] += len, l1[i] > r1[i] ? i++ : j++;
            else {
                int l = 0, r = len;
                while(l <= r) {
                    int mid = l + r >> 1;
                    sh(l1[i], mid) == sh(l2[j], mid) ? l = mid + 1 : r = mid - 1;
                }
                ans += r;
                break;
            }
        }
        wrt(ans);
    }
}