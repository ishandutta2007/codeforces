#include <bits/stdc++.h>
#define int long long
using namespace std;

template <class Flow, class Cost> struct NetworkSimplex {
  struct Edge {
    int from, to;
    Cost cost;
    Flow cap, flow = 0;
  };

  int n;
  vector<int32_t> pei, depth;
  vector<Cost> dual;
  vector<Edge> E;
  vector<set<int32_t>> tree;

  NetworkSimplex(int _n)
      : n(_n), pei(n + 1, -1), depth(n + 1, 0), dual(n + 1, 0), tree(n + 1) {}

  int addEdge(int from, int to, Flow cap, Cost cost) {
    E.push_back({from, to, cost, cap});
    E.push_back({to, from, -cost, Flow(0)});
    return E.size() - 2;
  }

  void dfs(int node) {
    for (auto ei : tree[node]) {
      if (ei == pei[node])
        continue;
      int vec = E[ei].to;
      dual[vec] = dual[node] + E[ei].cost;
      pei[vec] = (ei ^ 1);
      depth[vec] = 1 + depth[node];
      dfs(vec);
    }
  }

  template <typename F> void walk(int ei, F &&f) {
    f(ei);
    int from = E[ei].from, to = E[ei].to;
    while (from != to) {
      if (depth[from] > depth[to])
        f(pei[from] ^ 1), from = E[pei[from]].to;
      else
        f(pei[to]), to = E[pei[to]].to;
    }
  }

  Cost compute() {
    for (int i = 0; i < n; ++i) {
      int ei = addEdge(n, i, 0, 0);
      tree[n].insert(ei);
      tree[i].insert(ei ^ 1);
    }
    Cost answer = 0, cost;
    Flow flow;
    int ein, eout, ptr = 0;
    const int B = n / 3 + 1;
    for (int z = 0; z < (int)E.size() / B + 1; ++z) {
      if (!z)
        dfs(n);
      pair<Cost, int> pin(0, -1);
      for (int t = 0; t < B; ++t, (++ptr) %= E.size()) {
        auto &e = E[ptr];
        if (e.flow < e.cap)
          pin = min(pin, make_pair(dual[e.from] + e.cost - dual[e.to], ptr));
      }
      tie(cost, ein) = pin;
      if (cost == 0)
        continue;
      pair<int, int> pout = {E[ein].cap - E[ein].flow, ein};
      walk(ein, [&](int ei) {
        pout = min(pout, make_pair(E[ei].cap - E[ei].flow, ei));
      });
      tie(flow, eout) = pout;
      walk(ein, [&](int ei) { E[ei].flow += flow, E[ei ^ 1].flow -= flow; });
      tree[E[ein].from].insert(ein);
      tree[E[ein].to].insert(ein ^ 1);
      tree[E[eout].from].erase(eout);
      tree[E[eout].to].erase(eout ^ 1);
      answer += Cost(flow) * cost;
      z = -1;
    }
    return answer;
  }
};

struct Edge {
  int from, to, cap, weight;
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbSommets, nbAretes;
  cin >> nbSommets >> nbAretes;

  vector<Edge> edges(nbAretes);
  vector<int> posEdge(nbSommets);
  vector<int> bal(nbSommets);
  for (auto &[from, to, cap, cost] : edges) {
    cin >> from >> to >> cap >> cost;
    --from, --to;
    if (cap % 2) {
      bal[from]--;
      bal[to]++;
    }
  }

  if (bal[0] % 2) {
    bal[0]++;
    bal[nbSommets - 1]--;
  }
  for (int i = 0; i < nbSommets; ++i) {
    if (bal[i] % 2) {
      cout << "Impossible\n";
      return 0;
    }
    bal[i] /= 2;
  }

  int s = nbSommets;
  NetworkSimplex<int, int> network(nbSommets + 1);
  int sumEdge = 1;
  vector<int> idEdge;
  for (auto [from, to, cap, cost] : edges) {
    sumEdge += abs(cost);
    idEdge.push_back(network.addEdge(from, to, cap / 2, cost));
  }
  network.addEdge(nbSommets - 1, 0, (int)1e18, 0);
  vector<int> toCheck;
  for (int i = 0; i < nbSommets; ++i) {
    if (bal[i] > 0)
      toCheck.push_back(network.addEdge(s, i, bal[i], -sumEdge));
    else
      toCheck.push_back(network.addEdge(i, s, -bal[i], -sumEdge));
  }

  network.compute();
  for (int i = 0; i < (int)toCheck.size(); ++i) {
    auto ed = network.E[toCheck[i]];
    if (ed.flow < ed.cap) {
      cout << "Impossible\n";
      return 0;
    }
  }
  cout << "Possible\n";
  for (int i = 0; i < nbAretes; ++i) {
    auto ed = network.E[idEdge[i]];
    cout << 2 * ed.flow + edges[i].cap % 2 << ' ';
  }
  cout << endl;
}