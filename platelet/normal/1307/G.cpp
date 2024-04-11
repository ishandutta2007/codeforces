#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 55, M = 50 * 49 + 10;

int n, m, q, eid = 1, he[N], d[N], h[N], pre[N];
vector<pair<int, int>> Q;
double ans[100005];
int flow; long long cost;

struct { int v, nx, c, w; } e[M << 1];
struct node {
    int d, u;
    bool operator<(const node& b)const { return d > b.d; }
};
void add(int u, int v, int w) {
    e[++eid] = {v, he[u], 1, w}, he[u] = eid;
    e[++eid] = {u, he[v], 0, -w}, he[v] = eid;
}
void dij() {
    priority_queue<node> q;
    mem(d, 63), q.push({d[1] = 0, 1});
    while(q.size()) {
        int dis = q.top().d, u = q.top().u; q.pop();
        if(dis > d[u]) continue;
        for(int i = he[u], v; v = e[i].v; i = e[i].nx) if(e[i].c) {
            int w = d[u] + e[i].w - h[v] + h[u];
            if(w < d[v]) pre[v] = i ^ 1, q.push({d[v] = w, v});
        }
    }
    rep(i, 1, n) h[i] += d[i];
}
void aug() {
    flow++, cost += h[n];
    for(int u = n, i; i = pre[u]; u = e[i].v) e[i ^ 1].c--, e[i].c++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    int u, v, w;
    while(m--) cin >> u >> v >> w, add(u, v, w);
    cin >> q;
    rep(i, 1, q) cin >> w, Q.emplace_back(w, i);
    sort(Q.begin(), Q.end());
    dij(), aug(), dij();
    for(auto x : Q) {
        while(d[n] != d[0] && double(cost + x.first) / flow > h[n]) aug(), dij();
        ans[x.second] = double(cost + x.first) / flow;
    }
    rep(i, 1, q) printf("%.10lf\n", ans[i]);
}