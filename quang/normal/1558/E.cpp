#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// 1-indexed
class DSU {
 public:
  DSU(int n, const vector<int> &a) : num_comp_(n), root_(n + 1, 0) {
    ls_.resize(n + 1);
    a_.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      ls_[i].push_back(i);
      a_[i] = a[i];
    }
  }

  int num_comp() { return num_comp_; }
  long long a(int u) { return a_[u]; }
  vector<int> &ls(int u) {
    return ls_[u];
  }

  int GetRoot(int u) { return root_[u] ? root_[u] = GetRoot(root_[u]) : u; }

  bool Unite(int u, int v) {
    u = GetRoot(u);
    v = GetRoot(v);
    if (u == v) return 0;
    a_[v] += a_[u];

    if (ls_[v].size() < ls_[u].size()) {
      swap(ls_[u], ls_[v]);
    }
    ls_[v].insert(ls_[v].end(), ls_[u].begin(), ls_[u].end());
    ls_[u].clear();

    root_[u] = v;
    num_comp_--;
    return 1;
  }

 private:
  int num_comp_;  // number of connected components
  vector<long long> a_;
  vector<int> root_;
  vector<vector<int>> ls_;
};


void Solve(int test) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    cin >> b[i];
  }
  vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  auto Check = [&](int init_value) -> bool {
    b[1] = init_value;
    DSU dsu(n, b);
    while (dsu.num_comp() > 1) {
      queue<int> q;
      vector<int> d(n + 1, -1);
      vector<int> last_edge(n + 1, -1);
      vector<int> last_ver(n + 1, -1);
      vector<long long> cur(n + 1, 0);
      auto root = dsu.GetRoot(1);
      cur[root] = dsu.a(root);
      d[root] = 0;
      q.push(root);
      bool found_loop = false;
      pair<int, int> loop;
      while (!q.empty() && !found_loop) {
        int u = q.front();
        q.pop();
        for (int node_u : dsu.ls(u)) {
          for (auto [node_v, edge_id] : adj[node_u]) {
            auto v = dsu.GetRoot(node_v);
            if (u == v) continue;
            if (last_edge[u] == edge_id) continue;
            if (cur[u] <= a[node_v]) continue;
            if (d[v] == -1) {
              d[v] = d[u] + 1;
              last_edge[v] = edge_id;
              last_ver[v] = u;
              cur[v] = cur[u] + dsu.a(v);
              q.push(v);
            } else {
              found_loop = true;
              loop = {u, v};
              break;
            }
          }
          if (found_loop) {
            break;
          }
        }
      }

      if (!found_loop) {
        break;
      }
      auto [u, v] = loop;

      auto Go = [&](int u) {
        while (u != -1) {
          dsu.Unite(u, root);
          u = last_ver[u];
        }
      };
      Go(u);
      Go(v);
    }
    return dsu.num_comp() == 1;
  };

  int low = 0, high = *max_element(a.begin(), a.end()) + 1;
  while (high - low > 1) {
    int mid = low + high >> 1;
    if (Check(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << high << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}