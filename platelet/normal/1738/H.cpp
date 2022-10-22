#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

#ifndef local
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;

const int N = 1e6 + 8;

char s[N];
int n, sz = 1, nw, len[N], f[N], ch[N][26], fa[20][N];
int now[N], ID[N];
bool in[N];

struct { int c[2], f; } c[N];
inline bool id(int o) { return c[c[o].f].c[1] == o; }
inline bool nrt(int o) { return c[c[o].f].c[0] == o || c[c[o].f].c[1] == o; }
inline void rot(int o, int d) {
    int k = c[o].c[!d], &x = c[k].c[d];
    if(nrt(o)) c[c[o].f].c[id(o)] = k;
    x = c[c[o].c[!d] = x].f = o;
    c[k].f = c[o].f, c[o].f = k;
}
void splay(int o) {
    int col = now[o];
    for(int f, f2; nrt(o); rot(c[o].f, !id(o)))
    if(nrt(f = c[o].f)) {
        if(!nrt(f2 = c[f].f)) col = now[f2];
        rot(id(o) == id(f) ? f2 : f, !id(o));
    } else col = now[f];
    now[o] = now[c[o].c[1]] = col;
}
void acc(int o, int i) {
    int x = 0;
    for(; o; o = c[x = o].f) {
        splay(o), c[o].c[1] = x;
    }
    now[x] = i;
}
void ins(int i) {
    auto jmp = [&](int o) {
        while(s[i - len[o] - 1] != s[i]) o = f[o];
        return o;
    };
    int o = jmp(nw), c = s[i] - 97;
    if(!ch[o][c]) {
        f[++sz] = ch[jmp(f[o])][c];
        len[ch[o][c] = sz] = len[o] + 2;
        fa[0][sz] = ::c[sz].f = f[sz];
        rep(i, 1, 19) fa[i][sz] = fa[i - 1][fa[i - 1][sz]];
    }
    nw = ch[o][c];
    acc(nw, i);
}
int main() {
    len[1] = -1, f[0] = 1;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int l = 1, r = 0, ans = 0;
    char type[10];
    while(n--) {
        cin >> type;
        if(type[1] == 'u') {
            cin >> s[++r];
            ins(r);
            int u = nw;
            if(len[u] > r - l + 1) {
                per(i, 19, 0) if(len[fa[i][u]] > r - l + 1) u = fa[i][u];
                u = f[u];
            }
            ID[r - len[u] + 1] = u;
            if(!in[u]) in[u] = 1, ans++;
        } else {
            int u = ID[l];
            if(u) {
                splay(u);
                if(now[u] - l + 1 == len[u]) {
                    in[u] = 0, ans--;
                    u = f[u];
                    if(len[u] >= 1) {
                        splay(u);
                        ID[now[u] - len[u] + 1] = u;
                    }
                }
            }
            l++;
        }
        cout << ans << '\n';
    }
}