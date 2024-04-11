#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
string s[N];

string dir = "UDLR";
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<int>> label;

struct Forest {
  vector<int> edges[N];
  pair<int, int> order[N];
  int indeg[N];

  void addEdge(int u, int v) {
    edges[v].push_back(u);
    ++indeg[u];
  }

  void dfsEuler(int u, int &o) {
    order[u].first = o;
    for (int v: edges[u]) {
      dfsEuler(v, o);
    }
    order[u].second = o++;
  }

  void eulerTour() {
    int o = 0;
    int _n = (n * m) / 2;
    for (int i = 0; i < _n; ++i) {
      if (indeg[i] == 0) {
        dfsEuler(i, o);
      }
    }
  }
} forest[2];

struct SegTree {
  int cnt[N << 2];
  int sum[N << 2];

  void update(int node, int l, int r, int ll, int rr, int val) {
    if (l > rr || r < ll) return;
    if (l >= ll && r <= rr) {
      cnt[node] += val;
      sum[node] = (cnt[node] > 0 ? r - l + 1 : (l == r ? 0 : sum[node*2 + 1] + sum[node*2 + 2]));

      // cerr << l << " " << r << " " << val << " " << sum[node] << endl;
      return;
    }

    int mid = (l + r) >> 1;

    update(node*2 + 1, l, mid, ll, rr, val);
    update(node*2 + 2, mid+1, r, ll, rr, val);
    sum[node] = (cnt[node] > 0 ? r - l + 1 : sum[node*2 + 1] + sum[node*2 + 2]);
  }

  int query() {
    return sum[0];
  }

  void update(int ll, int rr, int val) {
    // cerr << "U: " << ll << " " << rr << " " << val << endl;
    update(0, 0, n*m/2 - 1, ll, rr, val);
  }
} tree;

long long dfs(int u) {
  pair<int, int> range = forest[1].order[u];
  tree.update(range.first, range.second, 1);

  long long ret = tree.query();
  // cerr << u << " " << ret << endl;
  for (int v: forest[0].edges[u]) {
    ret += dfs(v);
  }
  tree.update(range.first, range.second, -1);

  return ret;
}

void labelDomino() {
  int cur = 0;
  label = vector<vector<int>>(n, vector<int>(m, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (label[i][j] != -1) continue;
      for (int k = 0; k < 4; ++k) {
        if (s[i][j] == dir[k]) {
          label[i][j] = label[i + dx[k]][j + dy[k]] = cur++;
          break;
        }
      }
    }
  }
}

int solve() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  labelDomino();

  // for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cerr << label[i][j]; cerr << endl; }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < 4; ++k) {
        if (s[i][j] != dir[k]) continue;
        int ni = i + dx[k] * 2, nj = j + dy[k] * 2;
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

        // cerr << i << " " << j << " " << ni << " " << nj << endl;
        forest[i+j&1].addEdge(label[i][j], label[ni][nj]);
      }
    }
  }

  forest[1].eulerTour();

  // for (int i = 0; i < n*m / 2; ++i) cerr << forest[1].order[i].first << " " << forest[1].order[i].second << endl;

  long long ans = 0;
  for (int i = 0; i < (n * m) / 2; ++i) {
    if (forest[0].indeg[i] == 0) {
      ans += dfs(i);
    }
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}