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

const int N = 2e5 + 5, M = 3e5 + 5, Q = 5e5 + 5;
int n, m, q, p[N], a[M], b[M], ty[Q], id[Q];
bool vis[M];
int fa[N * 2], dfc = 1 << 18, dl[N * 2], dr[N * 2];
int ch[N * 2][2];
pair<int, int> c[(1 << 19) + 5];
int find(int x) { return fa[x] ? fa[x] = find(fa[x]) : x; }
void dfs(int u) {
    dl[u] = dfc;
    if(ch[u][0]) rep(i, 0, 1) dfs(ch[u][i]);
    else dfc++, c[dfc] = {p[u], dfc};
    dr[u] = dfc + 1;
}
void add(int i) {
    int u = find(a[i]), v = find(b[i]);
    if(u != v) fa[u] = fa[v] = ++n, ch[n][0] = u, ch[n][1] = v;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    rep(i, 1, n) p[i] = read();
    rep(i, 1, m) a[i] = read(), b[i] = read();
    rep(i, 1, q) ty[i] = read(), id[i] = read(), ty[i] == 2 ? vis[id[i]] = 1 : 0;
    rep(i, 1, m) if(!vis[i]) add(i);
    per(i, q, 1) if(ty[i] == 2) add(id[i]);
    else id[i] = find(id[i]); 
    rep(i, 1, n) if(!fa[i]) dfs(i);
    per(i, 1 << 18, 1) c[i] = max(c[i << 1], c[i << 1 | 1]);
    rep(i, 1, q) if(ty[i] == 1) {
        int l = dl[id[i]], r = dr[id[i]];
        pair ans(0, 0);
        while(r - l > 1) {
            if(~l & 1) ans = max(ans, c[l ^ 1]);
            if(r & 1) ans = max(ans, c[r ^ 1]);
            l >>= 1, r >>= 1;
        }
        wrt(ans.first);
        c[ans.second].first = 0;
        for(int i = ans.second >> 1; i; i >>= 1)
            c[i] = max(c[i << 1], c[i << 1 | 1]);
    }
}