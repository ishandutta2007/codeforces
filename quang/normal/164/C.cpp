#include <bits/stdc++.h>

using namespace std;

const int N = 1010, V = 100010;

int n, k;
int s[N], t[N], c[N], pos[N];
int val[N * 2], cnt;

template <class F, typename enable_if<is_integral<F>::value>::type* = nullptr>
class MinCostFlowPotential {
  inline static const F INF = numeric_limits<F>::max();

 public:
  MinCostFlowPotential(int n, int source, int sink)
      : n_(n),
        source_(source),
        sink_(sink),
        adj_(n, vector<int>()),
        d_(n, -1),
        prev_(n, -1),
        pot_(n, 0),
        used_(n, 0) {}

  void set_source(int u) {
    assert(u >= 0 && u < n_);
    source_ = u;
  }

  void set_sink(int u) {
    assert(u >= 0 && u < n_);
    sink_ = u;
  }

  int source() { return source_; }
  int sink() { return sink_; }
  F flow(int u) { return f_[u]; }

  int AddEdge(int u, int v, F _c, F _cost) {
    adj_[u].push_back(to_.size());
    to_.push_back(v);
    f_.push_back(0);
    c_.push_back(_c);
    cost_.push_back(_cost);
    adj_[v].push_back(to_.size());
    to_.push_back(u);
    f_.push_back(0);
    c_.push_back(0);
    cost_.push_back(-_cost);
    return static_cast<int>(to_.size()) - 2;
  }

  pair<F, F> MaxFlow() {
    F res = 0;
    F minCost = 0;
    while (Dijkstra()) {
      int x = sink_;
      F now = INF;
      while (x != source_) {
        int id = prev_[x];
        now = min(now, c_[id] - f_[id]);
        x = to_[id ^ 1];
      }
      x = sink_;
      while (x != source_) {
        int id = prev_[x];
        minCost += cost_[id] * now;
        f_[id] += now;
        f_[id ^ 1] -= now;
        x = to_[id ^ 1];
      }
      res += now;
    }
    return {res, minCost};
  }

  void Init() {
    fill(pot_.begin(), pot_.end(), INF);
    pot_[source_] = 0;
    bool changed = 1;
    while (changed) {  // be careful for NEG cycle
      changed = 0;
      for (int i = 0; i < n_; i++) {
        if (pot_[i] < INF) {
          for (int id : adj_[i]) {
            int v = to_[id];
            if (pot_[v] > pot_[i] + cost_[id] && f_[id] < c_[id]) {
              pot_[v] = pot_[i] + cost_[id];
              changed = 1;
            }
          }
        }
      }
    }
  }

 private:
  bool Dijkstra() {
    fill(prev_.begin(), prev_.end(), -1);
    fill(d_.begin(), d_.end(), INF);
    fill(used_.begin(), used_.end(), 0);
    d_[source_] = 0;
    set<pair<F, int>> ss;
    ss.insert({0, source_});
    while (!ss.empty()) {
      int u = ss.begin()->second;
      ss.erase(ss.begin());
      if (used_[u]) continue;
      used_[u] = 1;
      for (int id : adj_[u]) {
        int v = to_[id];
        F now = d_[u] + pot_[u] - pot_[v] + cost_[id];
        if (!used_[v] && d_[v] > now && f_[id] < c_[id]) {
          d_[v] = now;
          prev_[v] = id;
          ss.insert({d_[v], v});
        }
      }
    }
    for (int i = 0; i < n_; i++) pot_[i] += d_[i];
    return prev_[sink_] != -1;
  }

  int n_, source_, sink_;
  vector<vector<int>> adj_;
  vector<int> to_;
  vector<F> f_, c_;
  vector<F> cost_;

  vector<F> pot_;
  vector<F> d_;
  vector<int> prev_;
  vector<bool> used_;
};


int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", s + i, t + i, c + i);
    val[++cnt] = s[i];
    val[++cnt] = s[i] + t[i] - 1;
  }
  sort(val + 1, val + cnt + 1);
  cnt = unique(val + 1, val + cnt + 1) - val - 1;
  MinCostFlowPotential<int> f(cnt + 2, 0, cnt + 1);
  for (int i = 0; i <= cnt; i++) {
    f.AddEdge(i, i + 1, k, 0);
  }
  for (int i = 1; i <= n; i++) {
    t[i] = lower_bound(val + 1, val + cnt + 1, s[i] + t[i]) - val;
    s[i] = lower_bound(val + 1, val + cnt + 1, s[i]) - val;
    pos[i] = f.AddEdge(s[i], t[i], 1, -c[i]);
  }
  f.Init();
  f.MaxFlow();
  for (int i = 1; i <= n; i++) {
    if (f.flow(pos[i])) {
      printf("1 ");
    } else {
      printf("0 ");
    }
  }
  printf("\n");
  return 0;
}