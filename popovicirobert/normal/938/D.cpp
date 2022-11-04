#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const int MAXQ = (1 << 20);
const int MAXN = (int) 2e5;

vector < pair <int, ll> > g[MAXN + 1];
ll a[MAXN + 1];
ll sol[MAXN + 1];

bool viz[MAXN + 1];

priority_queue < pair <ll, int> > pq;

void dfs(int nod) {
    viz[nod] = 1;
    pq.push({-a[nod], nod});
    sol[nod] = a[nod];
    for(auto it : g[nod]) {
        if(viz[it.first] == 0)
            dfs(it.first);
    }
}

inline void dijkstra(int nod) {
    dfs(nod);
    while(!pq.empty()) {
        int nod = pq.top().second;
        ll cst = -pq.top().first;
        pq.pop();
        if(cst != sol[nod])
            continue;
        for(auto it : g[nod]) {
            if(sol[it.first] > sol[nod] + 2 * it.second) {
                sol[it.first] = sol[nod] + 2 * it.second;
                pq.push({-sol[it.first], it.first});
            }
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, x, y;
    ll w;
    //ios::sync_with_stdio(false);
    scanf("%d%d" ,&n,&m);
    for(i = 1; i <= m; i++) {
        scanf("%d%d%I64d" ,&x,&y,&w);
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    for(i = 1; i <= n; i++) {
        scanf("%I64d" ,&a[i]);
    }
    for(i = 1; i <= n; i++) {
        if(viz[i] == 0) {
            dijkstra(i);
        }
    }
    for(i = 1; i <= n; i++) {
        printf("%I64d " ,sol[i]);
    }
    //cin.close();
    //cout.close();
    return 0;
}