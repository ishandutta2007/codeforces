#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

// https://ei1333.github.io/library/graph/flow/ford-fulkerson.hpp
template< typename flow_t >
struct FordFulkerson {
  struct edge {
    int to;
    flow_t cap;
    int rev;
    bool isrev;
    int idx;
  };

  const flow_t INF;
  vector< vector< edge > > graph;
  vector< int > used;
  int timestamp;

  explicit FordFulkerson(int V) : INF(numeric_limits< flow_t >::max()), graph(V), used(V, -1), timestamp(0) {}

  void add_edge(int from, int to, flow_t cap, int idx = -1) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true, idx});
  }

  flow_t find_augment_path(int idx, const int t, flow_t flow) {
    if(idx == t) return flow;
    used[idx] = timestamp;
    for(auto &e : graph[idx]) {
      if(e.cap > 0 && used[e.to] != timestamp) {
        flow_t d = find_augment_path(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(int s, int t) {
    flow_t flow = 0;
    for(flow_t f; (f = find_augment_path(s, t, INF)) > 0; timestamp++) {
      flow += f;
    }
    timestamp++; // delta
    
    return flow;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int pot=5050;
  int n,m;
  cin >> n >> m;
  int v1=n+m+pot,v2=n+m+pot+1;
  FordFulkerson<int> g(n+m+pot+2);

  vector<int> p(n),c(n);
  for(auto &nx : p){cin >> nx;}
  for(auto &nx : c){cin >> nx;nx--;}
  int d;
  cin >> d;
  vector<int> k(d);
  vector<int> bk(n,1);
  for(auto &nx : k){
    cin >> nx;
    nx--;
    bk[nx]=0;
  }

  for(int i=0;i<n;i++){
    if(bk[i]){
      g.add_edge(p[i],pot+i,1);
      g.add_edge(pot+i,n+pot+c[i],1);
    }
  }
  for(int i=0;i<m;i++){g.add_edge(n+pot+i,v2,1);}

  g.add_edge(v1,0,1);
  int cres=0,cf=0;
  vector<int> res(d);
  for(int i=d-1;i>=0;i--){
    while(cres<m){
      cf+=g.max_flow(v1,v2);
      if(cf!=(cres+1)){break;}

      cres++;
      g.add_edge(v1,cres,1);
    }
    res[i]=cres;

    // g.output();
    // cout << '\n';
    // auto edges = g.edges();
    // for(auto &nx : edges){
    //   cout << nx.from << "->" << nx.to << ':' << nx.flow << ',' << nx.cap << '\n';
    // }cout << '\n';

    g.add_edge(p[k[i]],pot+k[i],1);
    g.add_edge(pot+k[i],n+pot+c[k[i]],1);
  }
  for(auto &nx : res){cout << nx << '\n';}
  return 0;
}