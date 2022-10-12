#include<bits/stdc++.h>

using namespace std;

namespace atcoder {
  namespace internal {

  template <class E> struct csr {
      std::vector<int> start;
      std::vector<E> elist;
      csr(int n, const std::vector<std::pair<int, E>>& edges)
          : start(n + 1), elist(edges.size()) {
          for (auto e : edges) {
              start[e.first + 1]++;
          }
          for (int i = 1; i <= n; i++) {
              start[i] += start[i - 1];
          }
          auto counter = start;
          for (auto e : edges) {
              elist[counter[e.first]++] = e.second;
          }
      }
  };

  // Reference:
  // R. Tarjan,
  // Depth-First Search and Linear Graph Algorithms
  struct scc_graph {
    public:
      scc_graph(int n) : _n(n) {}

      int num_vertices() { return _n; }

      void add_edge(int from, int to) { edges.push_back({from, {to}}); }

      // @return pair of (# of scc, scc id)
      std::pair<int, std::vector<int>> scc_ids() {
          auto g = csr<edge>(_n, edges);
          int now_ord = 0, group_num = 0;
          std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
          visited.reserve(_n);
          auto dfs = [&](auto self, int v) -> void {
              low[v] = ord[v] = now_ord++;
              visited.push_back(v);
              for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                  auto to = g.elist[i].to;
                  if (ord[to] == -1) {
                      self(self, to);
                      low[v] = std::min(low[v], low[to]);
                  } else {
                      low[v] = std::min(low[v], ord[to]);
                  }
              }
              if (low[v] == ord[v]) {
                  while (true) {
                      int u = visited.back();
                      visited.pop_back();
                      ord[u] = _n;
                      ids[u] = group_num;
                      if (u == v) break;
                  }
                  group_num++;
              }
          };
          for (int i = 0; i < _n; i++) {
              if (ord[i] == -1) dfs(dfs, i);
          }
          for (auto& x : ids) {
              x = group_num - 1 - x;
          }
          return {group_num, ids};
      }

      std::vector<std::vector<int>> scc() {
          auto ids = scc_ids();
          int group_num = ids.first;
          std::vector<int> counts(group_num);
          for (auto x : ids.second) counts[x]++;
          std::vector<std::vector<int>> groups(ids.first);
          for (int i = 0; i < group_num; i++) {
              groups[i].reserve(counts[i]);
          }
          for (int i = 0; i < _n; i++) {
              groups[ids.second[i]].push_back(i);
          }
          return groups;
      }

    private:
      int _n;
      struct edge {
          int to;
      };
      std::vector<std::pair<int, edge>> edges;
  };

  }  // namespace internal

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

using namespace atcoder;

long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}

using pi=pair<int,int>;
using Graph=vector<vector<pi>>;

vector<int> sid;
void dfs(int v,int pv,long long cl,vector<long long> &d,vector<long long> &res,vector<bool> &vf,Graph &g){
  vf[v]=true;
  d[v]=cl;
  //cerr << v << ' ' << pv << ' ' << cl << '\n';
  for(auto &nx : g[v]){
    int nv=nx.first;
    long long el=nx.second;
    if(vf[nv]){
      long long len=cl+el-d[nv];
      len=max(len,-len);
      if(len!=0){
        if(res[sid[v]]==-1){res[sid[v]]=len;}
        else{res[sid[v]]=llgcd(res[sid[v]],len);}
      }
    }
    else{dfs(nv,v,cl+el,d,res,vf,g);}
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,m;
  cin >> n >> m;
  vector<int> u(m),v(m),w(m);
  scc_graph scc_g(n);
  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;v[i]--;
    scc_g.add_edge(u[i],v[i]);
  }
  auto scc = scc_g.scc();
  sid.resize(n);
  int id=0;
  for(auto &nx : scc){
    for(auto &ny : nx){
      sid[ny]=id;
    }
    id++;
  }
  Graph g(n);
  for(int i=0;i<m;i++){
    if(sid[u[i]]==sid[v[i]]){
      g[u[i]].push_back({v[i],w[i]});
    }
  }
  vector<long long> res(n,-1);
  vector<long long> d(n,0);
  vector<bool> fl(n,false);
  for(int i=0;i<n;i++){
    if(!fl[i]){dfs(i,-1,0,d,res,fl,g);}
  }
  int q;
  cin >> q;
  while(q>0){
    q--;
    int qv;
    long long qs,qt;
    cin >> qv >> qs >> qt;
    qv--;
    if(qs==0){cout << "YES\n";continue;}
    if(res[sid[qv]]==-1){cout << "NO\n";continue;}
    long long kz=llgcd(qt,res[sid[qv]]);
    if((qt-qs)%kz==0){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}