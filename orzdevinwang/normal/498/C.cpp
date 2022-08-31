#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db long double
#define mp make_pair
const int N = 105;
const int fN = N * 20;
const int inf = 1e8;
int n, m, s, t, tot, a[N];
bool vis[fN];
int edge_id = 1, head[fN];
struct node { int to, val, next; } e[fN << 1];
void add_edge(int u, int v, int val) {
    ++edge_id, e[edge_id].val = val, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void add(int u, int v, int val) { add_edge(u, v, val), add_edge(v, u, 0); }
int dis[fN];
bool bfs() {
    fill(vis + 1, vis + tot + 1, 0), fill(dis + 1, dis + tot + 1, inf);
    queue<int> q; dis[s] = 0, vis[s] = 1, q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(e[i].val && !vis[v]) dis[v] = dis[u] + 1, vis[v] = 1, q.push(v);
        }
    }
    return dis[t] < inf;
}
int dfs(int x, int flow) {
    if(x == t) return flow;
    if(dis[x] > dis[t]) return 0;
    int p = flow;
    for(int i = head[x]; i; i = e[i].next) {
        int v = e[i].to;
        if(dis[v] == dis[x] + 1 && e[i].val) {
            int dl = dfs(v, min(e[i].val, flow));
            flow -= dl, e[i].val -= dl, e[i ^ 1].val += dl;
        }
    }
    return p - flow;
}
int dinic() {
    int res = 0;
    while(bfs()) res += dfs(s, inf);
    return res;
}
vector< pair<int, int> > ve[N];
map<int, int> mpp;
int main() {
    scanf("%d%d", &n, &m), tot = n;
    s = ++tot, t = ++tot;
    L(i, 1, n) {
        scanf("%d", &a[i]);
        L(j, 2, sqrt(a[i])) if(a[i] % j == 0) {
            int now = 0;
            while(a[i] % j == 0) a[i] /= j, now++;
            ve[i].push_back(mp(j, ++tot));
            if(i % 2 == 0) add(i, tot, now);
            else add(tot, i, now);
        }
        if(a[i] != 1) {
            ve[i].push_back(mp(a[i], ++tot));
            if(i % 2 == 0) add(i, tot, 1);
            else add(tot, i, 1);
        }
        if(i % 2 == 0) add(s, i, 30);
        else add(i, t, 30);
    }
    while(m--) {
        int u, v; scanf("%d%d", &u, &v);
        if(u % 2 == 1) swap(u, v);
        for(pair<int, int> x : ve[u]) mpp[x.first] = x.second;
        for(pair<int, int> x : ve[v]) if(mpp.count(x.first)) add(mpp[x.first], x.second, 30);
        mpp.clear();
    }
    printf("%d\n", dinic());
    return 0;
}