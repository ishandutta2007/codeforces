#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1e5 + 5, Inf = 0x3f3f3f3f;
int n, m, f[N], ct[N];

int find(int x) { return f[x] < 0 ? x : f[x] = find(f[x]); }

int chk(int x) {
    for(; x; x /= 10) if(x % 10 != 4 && x % 10 != 7) return 0;
    return 1;
}
int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    cin >> n >> m;
    rep(i, 1, n) f[i] = -1;
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        u = find(u), v = find(v);
        if(u ^ v) f[u] += f[v], f[v] = u;
    }
    rep(i, 1, n) if(f[i] < 0) ct[-f[i]]++;
    mem(f, 63), f[0] = 0;
    rep(i, 1, n) for(int j = ct[i]; j; j /= 2) {
        int v = (j + 1) / 2;
        per(k, n, v * i) f[k] = min(f[k], f[k - i * v] + v);
    }
    int as = Inf;
    rep(i, 1, n) if(chk(i)) as = min(as, f[i]);
    cout << (as < Inf ? as - 1 : -1);
    return 0;
}