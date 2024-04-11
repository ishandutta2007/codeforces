#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 1.5e5 + 5, P = 998244353;

int n, x, y, idx = 1, ch[N * 30][2], sz[N * 30];
ll pw[N];

ll calc(int u, int v, int i) {
    if(!u || !v) return pw[sz[u + v]];
    if(i < 0) return u == v ? pw[sz[u]] : pw[sz[u]] * pw[sz[v]] % P;
    if(x >> i & 1) {
        ll res = calc(ch[u][0], ch[v][1], i - 1);
        return u == v ? res : res * calc(ch[u][1], ch[v][0], i - 1) % P;
    }
    ll res = calc(ch[u][0], ch[v][0], i - 1) + calc(ch[u][1], ch[v][1], i - 1) - 1;
    if(u != v) for(int x : {u, v})
        res += (pw[sz[ch[x][0]]] - 1) * (pw[sz[ch[x][1]]] - 1);
    return res % P;
}
int main() {
    cin >> n >> x;
    rep(i, 1, n) {
        scanf("%d", &y);
        int o = 1;
        per(i, 29, 0) {
            int& O = ch[o][y >> i & 1];
            if(!O) O = ++idx;
            sz[o = O]++;
        }
    }
    rep(i, 0, n) pw[i] = i ? pw[i - 1] * 2 % P : 1;
    cout << (calc(1, 1, 29) + P - 1) % P;
}