#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, k;
long long h;
long long a[N];
int c[N], del[N], dead[N];
vector <long long> methods;
priority_queue <pair<int, int> > p;
long long dp[N], used[N];

void refresh() {
  for (int i = 0; i < k; i++) {
    dp[i] = h + 1;
    used[i] = 0;
  }
  dp[1] = 1;
  priority_queue <pair<long long, int> > q;
  q.push(make_pair(-1, 1));
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (used[u]) {
      continue;
    }
    used[u] = 1;
    for (long long i : methods) {
      if (dp[(u + i) % k] > dp[u] + i) {
        dp[(u + i) % k] = dp[u] + i;
        q.push(make_pair(-dp[(u + i) % k], (u + i) % k));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (del[i]) {
      continue;
    }
    if (dp[a[i] % k] <= a[i]) {
      p.push(make_pair(c[i], -i));
      del[i] = 1;
    }
  }
}

void update(int u, int v) {
  c[u] -= v;
  if (del[u] && !dead[u]) {
    p.push(make_pair(c[u], -u));
  }
}

int getans() {
  while (!p.empty()) {
    int val = p.top().first;
    int u = -p.top().second;
    p.pop();
    if (dead[u]) {
      continue;
    }
    if (c[u] != val) {
      continue;
    }
    dead[u] = 1;
    return val;
  }
  return 0;
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%I64d %d %d %d", &h, &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d %d", a + i, c + i);
  }
  methods.push_back(0);
  refresh();
  while (m--) {
    int op, y;
    long long x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%I64d", &x);
      methods.push_back(x);
      refresh();
    }
    if (op == 2) {
      scanf("%I64d %d", &x, &y);
      update(x, y);
    }
    if (op == 3) {
      printf("%d\n", getans());
    }
  }
  return 0;
}