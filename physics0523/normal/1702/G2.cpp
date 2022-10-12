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

    // return {LCA,dist(u,v)}
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

using namespace std;

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
  LCA lca(g,0);

  int q;
  cin >> q;
  while(q>0){
    q--;
    int m;
    cin >> m;
    set<int> st;
    for(int i=0;i<m;i++){
      int v;
      cin >> v;
      v--;
      st.insert(v);
    }

    bool ok=true;
    int ph=0;
    int l=-1,r=-1,mid=-1;
    for(auto &nx : st){
      // cout << nx+1 << ' ' << ph << ':' << l+1 << ' ' << r+1 << ' ' << mid+1 << '\n';
      if(ph==0){l=nx;ph=1;continue;}
      else if(ph==1){
        mid=lca.query(l,nx).first;
        if(mid==l){l=nx;ph=2;}
        else if(mid==nx){ph=2;}
        else{r=nx;ph=3;}
      }
      else if(ph==2){
        int lnx=lca.query(l,nx).first;
        int midnx=lca.query(mid,nx).first;
        if(lnx==l){l=nx;continue;}
        else if(midnx==nx){mid=nx;continue;}
        else if(lnx==nx && midnx==mid){continue;}
        else if(lnx!=midnx){ok=false;break;}
        r=nx;mid=lnx;ph=3;
      }
      else if(ph==3){
        int lnx=lca.query(l,nx).first;
        int rnx=lca.query(r,nx).first;
        int midnx=lca.query(mid,nx).first;
        if(lnx==l){l=nx;continue;}
        if(rnx==r){r=nx;continue;}
        if(lnx==nx && midnx==mid){continue;}
        if(rnx==nx && midnx==mid){continue;}
        ok=false;break;
      }
    }
    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}