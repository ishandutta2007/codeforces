#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

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
void wrt(int x, int end) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[11]; int sz = 0;
    if(x < 0) pc(45), x = -x;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(end);
}

const int N = 2000 + 5;

int n, m, q, pop[65536], p[N];
unsigned long long a[N][32];

set<pair<int, int>> s;
stack<int> st;

bool chk(int y) {
    int x = prev(s.find(pair(p[y], y)))->second, p = 0, q = 0;
    if(x == 0 || y > n) return 0;
    rep(i, 0, 31) {
        auto P = ~(~a[x][i] | a[y][i]);
        auto Q = ~(~a[y][i] | a[x][i]);
        if(!p && P) p = i * 64 + __builtin_ctzll(P) + 1;
        if(!q && Q) q = i * 64 + __builtin_ctzll(Q) + 1;
        if(p && q) break;
    }
    if(p) wrt(min(x, y), 32), wrt(min(p, q), 32), wrt(max(x, y), 32), wrt(max(p, q), 10);
    return p;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    rep(i, 1, 65535) pop[i] = pop[i & i - 1] + 1;
    p[n + 1] = 1e9;
    rep(i, 0, n + 1) s.emplace(p[i], i);
    int x, l, r;
    while(q--) {
        x = read(), l = read() - 1, r = read(), st.push(x);
        st.push(s.erase(s.find(pair(p[x], x)))->second);
        while(l < r) if(!(l & 63) && l + 63 < r)
            a[x][l >> 6] ^= -1, l += 64;
        else a[x][l >> 6] ^= 1ULL << (l & 63), l++;
        p[x] = 0;
        rep(i, 0, 31) {
            auto S = a[x][i];
            p[x] += pop[S & 65535] + pop[S >> 16 & 65535] + pop[S >> 32 & 65535] + pop[S >> 48];
        }
        st.push(next(s.emplace(p[x], x).first)->second);
        while(st.size() && !chk(st.top())) st.pop();
        if(st.empty()) wrt(-1, 10);
    }
}