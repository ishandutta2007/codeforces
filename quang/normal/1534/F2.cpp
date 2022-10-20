#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};

// 1-indexed
// O(N + M)
struct SCC {
  int n;
  vector<vector<int>> adj;

  vector<int> belong;
  vector<int> low;
  vector<int> num;
  int cnt_tarjan;
  vector<int> st_tarjan;

  int num_SCC;
  vector<vector<int>> nodes_in_SCC;
  vector<vector<int>> SCC_adj;

  SCC(int n) : n(n), adj(n + 1, vector<int>()) {}

  // make sure that adj's size is n + 1
  SCC(int n, vector<vector<int>> adj) : n(n), adj(adj) {}

  SCC(int n, vector<int> *adj_) : n(n) {
    adj.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) adj[i] = adj_[i];
  }

  void AddEdge(int u, int v) { adj[u].push_back(v); }

  void Dfs(int u) {
    low[u] = num[u] = ++cnt_tarjan;
    st_tarjan.push_back(u);
    for (int v : adj[u]) {
      if (belong[v]) continue;  // v has already been in a SCC
      if (num[v])
        low[u] = min(low[u], num[v]);
      else {
        Dfs(v);
        low[u] = min(low[u], low[v]);
      }
    }
    if (low[u] == num[u]) {
      num_SCC++;
      nodes_in_SCC.push_back(vector<int>());
      while (1) {
        int v = st_tarjan.back();
        st_tarjan.pop_back();
        belong[v] = num_SCC;
        nodes_in_SCC[num_SCC].push_back(v);
        if (u == v) break;
      }
    }
  }

  // we can loop through all SCCs on DAG's reverse order
  void Solve(bool build_scc_graph = false, bool compress = true) {
    belong.assign(n + 1, 0);
    low.assign(n + 1, 0);
    num.assign(n + 1, 0);
    cnt_tarjan = 0;
    st_tarjan.clear();
    num_SCC = 0;
    nodes_in_SCC.resize(1);  // SCC is 1-indexed

    for (int i = 1; i <= n; i++) {
      if (!num[i]) Dfs(i);
    }

    if (build_scc_graph) BuildSCCGraph(compress);
  }

  // build SCC adjacent vector
  // if compress is set SCC_adj remove all redundant elements
  void BuildSCCGraph(bool compress = true) {
    SCC_adj.resize(num_SCC + 1);
    for (int i = 1; i <= n; i++) {
      for (auto j : adj[i]) {
        SCC_adj[belong[i]].push_back(belong[j]);
      }
    }
    if (compress) {
      for (int i = 1; i <= num_SCC; i++) {
        sort(SCC_adj[i].begin(), SCC_adj[i].end());
        SCC_adj[i].resize(unique(SCC_adj[i].begin(), SCC_adj[i].end()) -
                          SCC_adj[i].begin());
      }
    }
  }
};

const int N = 400010;

int n, m;
string s[N];
int a[N];

bool IsInside(int u, int v) { return u > 0 && u <= n && v > 0 && v <= m; }

int Encode(int u, int v) { return (u - 1) * m + v; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '#' + s[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }

  SCC scc(n * m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#') {
        for (int dir = 0; dir < 4; dir++) {
          int ii = i + X[dir];
          int jj = j + Y[dir];
          if (IsInside(ii, jj)) {
            scc.AddEdge(Encode(i, j), Encode(ii, jj));
          }
        }
      } else {
        int ii = i + 1;
        int jj = j;
        if (IsInside(ii, jj)) {
          scc.AddEdge(Encode(i, j), Encode(ii, jj));
        }
      }
    }
  }
  scc.Solve(true);

  vector<pair<int, int>> ranges(scc.num_SCC + 1, {INF, -INF});
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pair<int, int> &now = ranges[scc.belong[Encode(i, j)]];
      now.first = min(now.first, j);
      now.second = max(now.second, j);
    }
  }
  for (int i = scc.num_SCC; i; i--) {
    for (int j : scc.SCC_adj[i]) {
      ranges[j].first = min(ranges[j].first, ranges[i].first);
      ranges[j].second = max(ranges[j].second, ranges[i].second);
    }
  }
  vector<pair<int, int>> ls_ranges;
  for (int j = 1; j <= m; j++) {
    if (!a[j]) continue;
    int cnt = 0;
    for (int i = n; i; i--) {
      if (s[i][j] == '#') cnt++;
      if (cnt == a[j]) {
        ls_ranges.push_back(ranges[scc.belong[Encode(i, j)]]);
        break;
      }
    }
  }
  sort(ls_ranges.begin(), ls_ranges.end());
  int res = 0;
  int last = 0;
  for (auto range : ls_ranges) {
    if (range.first > last) {
      res++;
      last = range.second;
    } else last = min(last, range.second);
  }
  cout << res << '\n';
  return 0;
}