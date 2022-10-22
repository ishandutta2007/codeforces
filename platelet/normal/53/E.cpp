#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define pop __builtin_popcount

using namespace std;

int n, m, K, f[1 << 10][1 << 10];

vector<int> G[10];

int main() {
#ifdef local
    freopen(".in", "r", stdin);
#endif
    cin >> n >> m >> K;
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v), G[--u].pb(--v), G[v].pb(u);
        f[1 << u | 1 << v][1 << u | 1 << v] = 1;
    }
    For(S, 0, 1 << n) {
        int ct = pop(S);
        if(ct <= 2) continue;
        for(int T = S; T; --T &= S) {
            int low = T & -T;
            for(int v : G[__builtin_ctz(low)]) if((S ^ T) >> v & 1)
                f[S][T] += f[S ^ low][T ^ low] + f[S ^ low][(T ^ low) | 1 << v];
        }
    }
    int as = 0;
    For(S, 0, 1 << n) if(pop(S) == K) as += f[(1 << n) - 1][S];
    cout << as;
    return 0;
}