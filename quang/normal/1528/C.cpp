#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

struct ST {
  int val[N << 2];
  int max_val[N << 2];

  void init(int node, int l, int r) {
    val[node] = max_val[node] = 0;
    if (l < r) {
      int m = l + r >> 1;
      init(node << 1, l, m);
      init(node << 1 | 1, m + 1, r);      
    }
  }

  void update(int node, int l, int r, int x, int y, int v) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
      val[node] = v;
      max_val[node] = v;
      return;
    }
    int m = l + r >> 1;
    update(node << 1, l, m, x, y, v);
    update(node << 1 | 1, m + 1, r, x, y, v);
    max_val[node] = max(max_val[node << 1], max_val[node << 1 | 1]);
  }

  int get_pos(int node, int l, int r, int x) {
    if (x > r || x < l) return 0;
    int res = val[node];
    if (l < r) {
      int m = l + r >> 1;
      res = max(res, get_pos(node << 1, l, m, x));
      res = max(res, get_pos(node << 1 | 1, m + 1, r, x));
    }
    return res;
  }

  int get_range(int node, int l, int r, int x, int y) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) return max_val[node];
    int m = l + r >> 1;
    int p1 = get_range(node << 1, l, m, x, y);
    int p2 = get_range(node << 1 | 1, m + 1, r, x, y);
    return max(p1, p2);
  }
} st;

int n;
vector<int> a[N], b[N];
int in[N], out[N], cnt;
int res = 0;

void dfs(int u) {
  in[u] = ++cnt;
  for (auto v : b[u]) {
    dfs(v);
  }
  out[u] = cnt;
}

void solve(int u, int cur) {
  int p = st.get_pos(1, 1, n, in[u]);
  int max_range = 0;
  if (p) {
    st.update(1, 1, n, in[p], out[p], 0);
    st.update(1, 1, n, in[u], out[u], u);
  } else {
    max_range = st.get_range(1, 1, n, in[u], out[u]);
    if (!max_range) {
      st.update(1, 1, n, in[u], out[u], u);
      cur++;
    }
  }

  res = max(res, cur);
  for (auto v : a[u]) {
    solve(v, cur);
  }

  if (p) {
    st.update(1, 1, n, in[u], out[u], 0);
    st.update(1, 1, n, in[p], out[p], p);
  } else {
    if (!max_range) {
      st.update(1, 1, n, in[u], out[u], 0);
      cur--;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      a[i].clear();
      b[i].clear();
    }
    for (int i = 2; i <= n; i++) {
      int u;
      cin >> u;
      a[u].push_back(i);
    }
    for (int i = 2; i <= n; i++) {
      int u;
      cin >> u;
      b[u].push_back(i);
    }
    cnt = 0;
    res = 0;
    dfs(1);
    st.init(1, 1, n);
    solve(1, 0);
    cout << res << '\n';
  }
  return 0;
}