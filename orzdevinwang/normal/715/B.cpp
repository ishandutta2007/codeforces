#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++)
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--)
#define ll long long
#define db double
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int M = 2e5 + 7;
const int inf = 1e9 + 1e8;
int n, m, s, t, chk[N], u[N], v[N], las[N], lasd[N];
int head[N], edge_id = 1;
struct node {
    int chk, to, val, bh, next;
} e[M << 1];
void add_edge(int u, int v, int val) {
    ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val, head[u] = edge_id;
}
priority_queue< pair<ll, int> > q;
ll ans[N], anss[N], L, val[N], pp;
bool vis[N];
void ADijkstra() {
    memset(ans, 0x3f, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    ans[s] = 0, q.push(mkp(0, s));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(ans[u] + e[i].val < ans[v]) {
                ans[v] = ans[u] + e[i].val, las[v] = i, lasd[v] = u;
                q.push(mkp(-ans[v], v));
            }
        }
    }
}
void BDijkstra() {
    memset(anss, 0x3f, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    anss[s] = 0, q.push(mkp(0, s));
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(chk[e[i].bh] && anss[u] + e[i].val < ans[v] + pp) e[i].val = e[i ^ 1].val = val[e[i].bh] = pp + ans[v] - anss[u];
            if(anss[u] + e[i].val < anss[v]) {
                anss[v] = anss[u] + e[i].val;
                q.push(mkp(-anss[v], v));
            }
        }
    }
}
int main() {
    scanf("%d%d%lld%d%d", &n, &m, &L, &s, &t), ++s, ++t;
    L(i, 1, m) {
        scanf("%d%d%lld", &u[i], &v[i], &val[i]), u[i]++, v[i]++;
        if(val[i] == 0) val[i] = 1, chk[i] = 1;
        add_edge(u[i], v[i], val[i]), e[edge_id].bh = i, add_edge(v[i], u[i], val[i]), e[edge_id].bh = i;
    }
    ADijkstra();
    if(ans[t] > L) return puts("NO"), 0; // ansa[t] >= L
    pp = L - ans[t];
    BDijkstra();
    if(anss[t] != L) return puts("NO"), 0;
    puts("YES");
    L(i, 1, m) printf("%d %d %lld\n", u[i] - 1, v[i] - 1, val[i]);
    return 0;
}