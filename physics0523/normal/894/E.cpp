#include<bits/stdc++.h>

#include <algorithm>

#include <algorithm>
#include <utility>
#include <vector>

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

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

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

using namespace std;
using namespace atcoder;

long long llsankaku(long long x){return ((1+x)*x)/2;}

long long f(long long x){
  long long st=0,fi=x+5;
  while(st<=fi){
    long long te=(st+fi)/2;
    if(llsankaku(te)<=x){st=te+1;}
    else{fi=te-1;}
  }
  long long n=fi;
  long long res=(n+1)*x;
  res-=(n*(n+1)*(n+2))/6;
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  vector<int> u(m),v(m),w(m);
  scc_graph g(n);

  for(int i=0;i<m;i++){
    cin >> u[i] >> v[i] >> w[i];
    u[i]--;v[i]--;
    g.add_edge(u[i],v[i]);
  }

  int id=0;
  vector<int> vid(n);
  auto scc=g.scc();
  for(auto &nx : scc){
    for(auto &ny : nx){vid[ny]=id;}
    id++;
  }

  vector<long long> inside(n,0);
  vector<long long> dp(n,-4e18);
  vector<vector<pair<int,int>>> dpg(n);
  for(int i=0;i<m;i++){
    long long uu=vid[u[i]];
    long long vv=vid[v[i]];
    if(uu==vv){
      inside[uu]+=f(w[i]);
    }
    else{
      dpg[uu].push_back({vv,w[i]});
    }
  }

  long long s;
  cin >> s;
  s--;
  dp[vid[s]]=0;

  for(int i=0;i<n;i++){
    dp[i]+=inside[i];
    for(auto &nx : dpg[i]){
      dp[nx.first]=max(dp[nx.first],dp[i]+nx.second);
    }
  }

  long long res=0;
  for(auto &nx : dp){res=max(res,nx);}
  cout << res << '\n';
  return 0;
}