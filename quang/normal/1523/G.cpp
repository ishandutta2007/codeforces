#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1e9;

int n, m;
pair<int, int> offers[N];
vector<int> size_list[N];
int res[N];

struct Node1D {
  int val;
  Node1D *l_child, *r_child;
  
  Node1D() {
    val = INF;
    l_child = r_child = nullptr;
  }

  void Add(int l, int r, int x, int id) {
    if (l > x || r < x) return;
    val = min(val, id);
    if (l == r) return;
    int m = l + r >> 1;
    if (x <= m) {
      if (!l_child) l_child = new Node1D;
      l_child->Add(l, m, x, id);
    } else {
      if (!r_child) r_child = new Node1D;
      r_child->Add(m + 1, r, x, id);
    }
  }

  int Get(int l, int r, int x, int y) {
    if (x > r || y < l) return INF;
    if (x <= l && r <= y) return val;
    int m = l + r >> 1;
    int res = INF;
    if (l_child) res = min(res, l_child->Get(l, m, x, y));
    if (r_child) res = min(res, r_child->Get(m + 1, r, x, y));
    return res;
  }
};


struct Node2D {
  Node1D *val;
  Node2D *l_child, *r_child;

  Node2D() {
    val = new Node1D;
    l_child = r_child = nullptr;
  }

  void Add(int l, int r, int x, int y, int id) {
    if (x > r || x < l) return;
    val->Add(1, n, y, id);
    if (l == r) return;
    int m = l + r >> 1;
    if (x <= m) {
      if (!l_child) l_child = new Node2D;
      l_child->Add(l, m, x, y, id);
    } else {
      if (!r_child) r_child = new Node2D;
      r_child->Add(m + 1, r, x, y, id);
    }
  }

  int Get(int l, int r, int x, int xx, int y, int yy) {
    if (x > r || xx < l) return INF;
    if (x <= l && r <= xx) return val->Get(1, n, y, yy);
    int m = l + r >> 1;
    int res = INF;
    if (l_child) res = min(res, l_child->Get(l, m, x, xx, y, yy));
    if (r_child) res = min(res, r_child->Get(m + 1, r, x, xx, y, yy));
    return res;
  }
};

int Solve(int l, int r, Node2D *root) {
  if (l > r) return 0;
  int id = root->Get(1, n, l, r, l, r);
  if (id == INF) return 0;
  int res = offers[id].second - offers[id].first + 1;
  res += Solve(l, offers[id].first - 1, root);
  res += Solve(offers[id].second + 1, r, root);
  return res;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> offers[i].first >> offers[i].second;
    size_list[offers[i].second - offers[i].first + 1].push_back(i);
  }
  Node2D *root = new Node2D;
  for (int sz = n; sz; sz--) {
    for (auto id : size_list[sz]) {
      auto [x, y] = offers[id];
      root->Add(1, n, x, y, id);
    }
    res[sz] = Solve(1, n, root);
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}