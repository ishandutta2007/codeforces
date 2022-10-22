#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, m, s, sz[N], fa[N];
ll d[N];
vector<pair<int, int>> G[N];
vector<int> pre[N];

struct node {
    ll d; int u;
    bool operator<(const node& b)const {
        return d > b.d;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    int u, v, w;
    while(m--) cin >> u >> v >> w, G[u].eb(v, w), G[v].eb(u, w);
    priority_queue<node> q;
    q.push({0, s}), mem(d, 63), d[s] = 0, m = 0;
    int ans = 0;
    while(q.size()) {
        auto [dis, u] = q.top(); q.pop();
        if(dis > d[u]) continue;
        if(pre[u].size()) {
            fa[u] = fa[pre[u][0]];
            if(!fa[u]) fa[u] = u;
            else for(int v : pre[u]) if(fa[v] != fa[u]) { fa[u] = u; break; }
            ans = max(ans, ++sz[fa[u]]);
        }
        for(auto [v, w] : G[u]) if(ll t = dis + w; t < d[v])
            d[v] = t, pre[v] = {u}, q.push({t, v});
        else if(t == d[v]) pre[v].pb(u);
    }
    cout << ans;
}