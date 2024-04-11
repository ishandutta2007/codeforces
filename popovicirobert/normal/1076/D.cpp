#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = 1e18;
const int MAXN = (int) 3e5;

struct Edge {
    int nod, w;
    int pos;
};

vector < Edge > g[MAXN + 1], dag[MAXN + 1];

priority_queue < pair <ll, int> > pq;
ll dist[MAXN + 1];
bool vis[MAXN + 1];
int n;

inline void dijkstra(int nod) {
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    pq.push({0, nod});
    while(!pq.empty()) {
        nod = pq.top().second;
        ll dst = -pq.top().first;
        pq.pop();
        if(vis[nod]) {
            continue;
        }
        vis[nod] = 1;
        for(auto it : g[nod]) {
            if(dist[it.nod] > dst + it.w) {
                dist[it.nod] = dst + it.w;
                pq.push({-dist[it.nod], it.nod});
            }
        }
    }
}

vector <int> sol;

void dfs(int nod, int &k) {
    vis[nod] = 1;
    for(auto it : dag[nod]) {
        if(!vis[it.nod] && k > 0) {
            k--;
            sol.push_back(it.pos);
            dfs(it.nod, k);
        }
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int m, k, i;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w, i});
        g[y].push_back({x, w, i});
    }
    dijkstra(1);
    for(i = 1; i <= n; i++) {
        for(auto it : g[i]) {
            if(dist[it.nod] == dist[i] + it.w) {
                dag[i].push_back({it.nod, 0, it.pos});
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    dfs(1, k);
    cout << sol.size() << "\n";
    for(auto it : sol) {
        cout << it << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}