#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, c) memset(a, c, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
void wrt(ll x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[20]; int sz = 0;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(10);
}

const int K = 320, N = K * K;

int n, q, sz, id[N][2], ch[N][26], f[N], que[N], dl[N], dr[N];
string s[N];
vector<int> G[N], node[N];
vector<pair<int, int>> q1[N];
vector<tuple<int, int, int>> q2[N];
alignas(32) int s0[K], s1[N];
int cnt[N]; ll sum[N], ans[N];

void dfs(int u) {
    dl[u] = ++sz;
    for(int v : G[u]) dfs(v);
    dr[u] = sz + 1;
}
inline void add(int i, int v) {
    For(k, i / K + 1, K) s0[k] += v;
    For(k, i + 1, (i / K + 1) * K) s1[k] += v;
}
inline int qry(int i) { return s1[i] + s0[i / K]; }
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    rep(i, 1, n) {
        cin >> s[i];
        int o = 0;
        for(char c : s[i]) {
            int& oo = ch[o][c - 97];
            if(!oo) oo = ++sz;
            o = oo;
        }
        id[i][0] = o;
    }
    int l = 1, r = 0, k;
    rep(i, 0, 25) if(ch[0][i]) que[++r] = ch[0][i];
    while(l <= r) {
        int u = que[l++];
        rep(i, 0, 25) {
            int& v = ch[u][i];
            (v ? f[que[++r] = v] : v) = ch[f[u]][i];
        }
    }
    rep(i, 1, sz) G[f[i]].pb(i);
    sz = 0, dfs(0);
    rep(i, 1, n) {
        id[i][1] = dr[id[i][0]], id[i][0] = dl[id[i][0]];
        if(s[i].size() < K) {
            int o = 0;
            for(char c : s[i]) node[i].pb(dl[o = ch[o][c - 97]] + 1);
        }
    }
    rep(i, 1, q) {
        l = read(), r = read(), k = read();
        if(s[k].size() < K) q1[r].eb(k, i), q1[l - 1].eb(k, i);
        else q2[k].eb(l, r, i);
    }
    rep(i, 1, n) {
        add(id[i][0], 1), add(id[i][1], -1);
        for(auto [k, v] : q1[i]) {
            ll res = 0;
            for(int o : node[k]) res += qry(o);
            ans[v] = abs(ans[v] - res);
        }
    }
    rep(i, 1, n) if(s[i].size() >= K) {
        int o = 0;
        mem(cnt, 0);
        for(char c : s[i]) cnt[dl[o = ch[o][c - 97]]]++;
        per(j, sz, 1) cnt[j] += cnt[j + 1];
        rep(j, 1, n) sum[j] = sum[j - 1] + cnt[id[j][0]] - cnt[id[j][1]];
        for(auto [l, r, v] : q2[i]) ans[v] = sum[r] - sum[l - 1];
    }
    rep(i, 1, q) wrt(ans[i]);
}