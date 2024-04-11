#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define SZ(x) int((x).size())

using namespace std;

const int N = 3e5 + 5;

int n, m, dir[N * 2];
vector<pair<int, int>> G[N * 2];

void add(int u, int v, int i) {
    G[u].emplace_back(v, i), G[v].emplace_back(u, -i);
}
void dfs(int u) {
    while(G[u].size()) {
        auto [v, i] = G[u].back(); G[u].pop_back();
        if(!dir[abs(i)]) i > 0 ? dir[i] = 1 : dir[-i] = 2, dfs(v);
    }
}
int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    cin >> n >> m;
    int u, v, w;
    rep(i, 1, m) {
        scanf("%d%d%d", &u, &v, &w);
        w == 1 ? add(u, v, i) : add(u + n, v + n, i);
    }
    int ans = 0;
    rep(i, 1, n) ans += SZ(G[i]) & 1;
    cout << ans << endl;
    rep(i, 1, n) if(SZ(G[i]) % 2 && SZ(G[i + n]) % 2) add(i, i + n, i + m);
    else {
        if(SZ(G[i]) % 2) add(i, n * 2 + 1, i + m);
        if(SZ(G[i + n]) % 2) add(i + n, n * 2 + 1, i + m);
    }
    rep(i, 1, n * 2 + 1) dfs(i);
    rep(i, 1, m) printf("%d", dir[i]);
}