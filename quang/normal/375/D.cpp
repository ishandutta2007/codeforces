#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int c[N], res[N];
vector <int> a[N];
vector <pair<int, int> > q[N];

struct node {
  map<int, int> cnt;
  map<int, int> s;

  node() {
    cnt.clear();
    s.clear();
  }
};

void add(node* u, int x, int y) {
  auto p = u->cnt.find(x);
  if (p == u->cnt.end()) {
    u->cnt[x] = y;
    u->s[y]++;
  } else {
    int v = u->cnt[x];
    u->s[v]--;
    u->s[v + y]++;
    u->cnt[x] += y;
  }
}

node* join(node* u, node* v) {
  if (!u) {
    return v;
  }
  if (!v) {
    return v;
  }
  if (u->cnt.size() < v->cnt.size()) {
    swap(u, v);
  }
  for (auto x : v->cnt) {
    add(u, x.first, x.second);
  }
  return u;
}

node* dfs(int u, int p) {
  node* x = 0;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    node* y = dfs(v, u);
    x = join(x, y);
  }
  if (!x) {
    x = new node;
  }
  add(x, c[u], 1);
  for (pair<int, int> v : q[u]) {
    int cur = 0;
    for (auto f : x->s) {
      if (f.first >= v.first) {
        cur += f.second;
      }
    }
    res[v.second] = cur;
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i <= m; i++) {
    int v, k;
    cin >> v >> k;
    q[v].push_back(make_pair(k, i));
  }
  dfs(1, 0);
  for (int i = 1; i <= m; i++) {
    cout << res[i] << endl;
  }
  return 0;
}