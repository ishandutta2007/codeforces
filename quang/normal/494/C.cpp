#include <bits/stdc++.h>

using namespace std;

const int N = 100010, Q = 5010;

int n, q;
int a[N];
double dp[Q][Q];
vector <int> c[Q];
int d[Q];

struct rmq {
  int rmq[20][N];

  void init() {
    for (int i = 1; i <= n; i++) {
      rmq[0][i] = a[i];
    }
    for (int i = 1; i < 20; i++) {
      for (int j = 1; j <= n - (1 << i) + 1; j++) {
        rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  int get(int l, int r) {
    int x = log2(r - l + 1);
    return max(rmq[x][l], rmq[x][r - (1 << x) + 1]);
  }
} m;

struct data {
  int l, r;
  double p;
  data(){};
  data(int l, int r, double p) {
    this->l = l;
    this->r = r;
    this->p = p;
  }
};

data b[Q];

bool cmp(data u, data v) {
  if (u.l != v.l) {
    return u.l < v.l;
  }
  return u.r > v.r;
}

void dfs(int u, int p) {
  if (c[u].size() == 0) {
    dp[u][0] = 1.0 - b[u].p;
    for (int i = 1; i <= q; i++) {
      dp[u][i] = 1.0;
    }
    return;
  }
  for (int i = 0; i < c[u].size(); i++) {
    dfs(c[u][i], u);
  }
  for (int i = 0; i <= q; i++) {
    double x, y;
    x = y = 1;
    for (int j = 0; j < c[u].size(); j++) {
      int v = c[u][j];
      int foo = d[u] - d[v] + i - 1;
      if (i) {
        if (foo >= 0 && foo <= q) {
          x *= dp[v][foo];
        } else {
          if (foo < 0) {
            x = 0;
          }
        }
      } else {
        x = 0;
      }
      foo++;
      if (foo >= 0 && foo <= q) {
        y *= dp[v][foo];
      } else {
        if (foo < 0) {
          y = 0;
        }
      }
    }
    dp[u][i] = x * b[u].p + y * (1.0 - b[u].p);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  m.init();
  for (int i = 1; i <= q; i++) {
    cin >> b[i].l >> b[i].r >> b[i].p;
  }
  sort(b + 1, b + q + 1, cmp);
  for (int i = 1; i <= q; i++) {
    d[i] = m.get(b[i].l, b[i].r);
  }
  b[0] = data(1, n, 0);
  d[0] = m.get(1, n);
  vector <int> f;
  f.push_back(0);
  for (int i = 1; i <= q; i++) {
    while (b[i].l > b[f.back()].r) {
      f.pop_back();
    }
    c[f.back()].push_back(i);
    f.push_back(i);
  }
  dfs(0, -1);
  double res = dp[0][0] * d[0];
  for (int i = 1; i <= q; i++) {
    res += (dp[0][i] - dp[0][i - 1]) * (1.0 * d[0] + i);
  }
  printf("%0.10f", res);
  return 0;
}