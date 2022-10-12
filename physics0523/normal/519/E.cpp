#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;
using Graph=vector<vector<int>>;

// Based on:
// https://algo-logic.info/lca/
struct LCA {
    vector<vector<int>> parent;
    vector<int> dist;
    LCA(const Graph &G, int root = 0) { init(G, root); }

    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e != p) dfs(G, e, v, d + 1);
        }
    }
    pair<int,int> query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);
        int rd=(dist[u]+dist[v]);

        int K = parent.size();
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        if (u == v) return {u,rd-2*dist[u]};
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return {parent[0][u],rd-2*dist[parent[0][u]]};
    }
};

map<pi,int> mp;
int rep(int v,int pv,Graph &g,int n){
  int sig=0;
  for(auto &nx : g[v]){
    if(nx==pv){continue;}
    int c=rep(nx,v,g,n);
    mp[{nx,v}]=c;
    mp[{v,nx}]=n-c;
    //cout << nx << ',' << v << '\n';
    sig+=c;
  }
  return sig+1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  Graph g(n);
  for(int i=1;i<n;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  rep(0,-1,g,n);
  LCA lca(g);
  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--;v--;
    if(u==v){cout << n << '\n';continue;}

    pi l=lca.query(u,v);
    if(l.second%2){cout << "0\n";continue;}
    int lv=(l.second/2);

    pi uq=lca.query(u,l.first);
    pi vq=lca.query(v,l.first);
    if(uq.second>vq.second){
      swap(u,v);
      swap(uq,vq);
    }

    int res=n;
    if(uq.second==vq.second){
      int lift=lv-1;
      for(int tg=20;tg>=0;tg--){
        if(lift&(1<<tg)){
          u=lca.parent[tg][u];
          v=lca.parent[tg][v];
        }
      }
      res-=mp[{u,l.first}];
      res-=mp[{v,l.first}];
    }
    else{
      int lift=lv-1;
      for(int tg=20;tg>=0;tg--){
        if(lift&(1<<tg)){
          v=lca.parent[tg][v];
        }
      }
      int v1=v;
      v=lca.parent[0][v];
      int c=v;
      v=lca.parent[0][v];
      int v2=v;
      // cout << v1 << ' ' << c << ' ' << v2 << '\n';
      // cout << mp[{v1,c}] << '\n';
      // cout << mp[{v2,c}] << '\n';
      res-=mp[{v1,c}];
      res-=mp[{v2,c}];
    }

    cout << res << '\n';
  }
  return 0;
}