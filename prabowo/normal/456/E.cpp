#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

int n, m, q;
int par[N];
int l[N];
bool vis[N];

vector <int> edge[N];

vector <int> vc;
pair <int, int> bfs(int x) {
    queue < pair<int, int> > q;
    q.push(make_pair(x, 0));
    
    vis[x] = 1;
    
    pair <int, int> last;
    while (q.size()) {
        int u = q.front().first;
        int dist = q.front().second;
        
        vc.push_back(u);
        
        last = q.front();
        q.pop();
        
        for (int i=0; i<edge[u].size(); i++) {
            int v = edge[u][i];
            if (vis[v]) continue;
            vis[v] = 1;
            q.push(make_pair(v, dist + 1));
        }
    }
    
    return last;
}

int dsu(int u) {
    if (u == par[u]) return u;
    return par[u] = dsu(par[u]);
}

int main() {
    scanf ("%d %d %d", &n, &m, &q);    
    
    for (int i=0; i<n; i++) par[i] = i;
    
    int u, v;
    for (int i=0; i<m; i++) {
        scanf ("%d %d", &u, &v);
        u--, v--;
        
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    for (int i=0; i<n; i++) {
        if (vis[i]) continue;
        
        int tmp = bfs(i).first;
        while (vc.size()) vis[vc.back()] = 0, vc.pop_back();
        
        l[i] = bfs(tmp).second;
        while (vc.size()) {
            par[dsu(vc.back())] = dsu(i);
            vc.pop_back();
        }
    }   
    
    while (q--) {
        int t;
        scanf ("%d", &t);
        
        if (t == 2) {
            scanf ("%d %d", &u, &v);
            u--, v--;
            
            if (dsu(u) == dsu(v)) continue;
            
            int newL = (l[dsu(u)] + 1 >> 1) + (l[dsu(v)] + 1 >> 1) + 1;
            l[dsu(u)] = max(newL, max(l[dsu(u)], l[dsu(v)]));
            par[dsu(v)] = dsu(u);
        } else {
            scanf ("%d", &u);
            printf ("%d\n", l[dsu(u-1)]);
        }
    }
    return 0;
}