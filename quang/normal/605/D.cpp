#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N], c[N], d[N];
int val[N], used[N], di[N], st[N], pre[N], top;
vector <int> pos[N];

struct range {
  vector <pair <int, int> > a;
  int cur;

  range() {
    cur = 0;
  }

  int get(int x) {
    while (cur < a.size() && used[a[cur].second]) {
      cur++;
    }
    if (cur >= a.size()) {
      return 0;
    }
    return (a[cur].first <= x ? a[cur].second : 0);
  }
} t[N * 4];

void build(int node, int l, int r) {
  if (l == r) {
    t[node].a.resize(pos[l].size());
    for (int i = 0; i < pos[l].size(); i++) {
      t[node].a[i] = make_pair(a[pos[l][i]], pos[l][i]);
    }
    sort(t[node].a.begin(), t[node].a.end());
    return;
  }
  int m = (l + r) >> 1;
  build(node + node, l, m);
  build(node + node + 1, m + 1, r);
  t[node].a.resize(t[node + node].a.size() + t[node + node + 1].a.size());
  merge(t[node + node].a.begin(), t[node + node].a.end(), t[node + node + 1].a.begin(), t[node + node + 1].a.end(), t[node].a.begin());
}

void go(int node, int l, int r, int x, int y, int id) {
  if (l > y || r < x) {
    return;
  }
  if (x <= l && r <= y) {
    while (1) {
      int u = t[node].get(c[id]);
      if (u == 0) {
        break;
      }
      st[top++] = u;
      used[u] = 1;
      di[u] = di[id] + 1;
      pre[u] = id;
    }
    return;
  }
  int m = (l + r) >> 1;
  go(node + node, l, m, x, y, id);
  go(node + node + 1, m + 1, r, x, y, id);
}

int main() {
  //freopen("input.txt", "r" ,stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
    val[i] = b[i];
  }
  sort(val + 1, val + n + 1);
  m = unique(val + 1, val + n + 1) - val - 1;
  for (int i = 1; i <= n; i++) {
    int x = lower_bound(val + 1, val + m + 1, b[i]) - val;
    pos[x].push_back(i);
  }
  build(1, 1, m);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 && b[i] == 0) {
      st[top++] = i;
      used[i] = 1;
      di[i] = 1;
    } else {
      di[i] = 1e9;
    }
  }
  for (int i = 0; i < top; i++) {
    int u = st[i];
    int x = upper_bound(val + 1, val + m + 1, d[u]) - val - 1;
    if (x == 0) {
      continue;
    }
    go(1, 1, m, 1, x, u);
  }
  if (di[n] >= 1e9) {
    cout << -1;
    return 0;
  }
  printf("%d\n", di[n]);
  vector <int> ans;
  while (n) {
    ans.push_back(n);
    n = pre[n];
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    printf("%d ", ans[i]);
  }
  return 0;
}