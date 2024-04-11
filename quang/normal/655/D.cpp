#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int x[N], y[N];
vector <int> a[N];
int deg[N];
int h[N];
int q[N], top;

void go() {
  top = 0;
  for (int i = 1; i <= n; i++) {
    if (!deg[i]) {
      q[top++] = i;
      h[i] = 0;
    } else {
      h[i] = 0;
    }
  }
  for (int i = 0; i < top; i++) {
    int u = q[i];
    for (int v : a[u]) {
      h[v] = max(h[v], h[u] + 1);
      deg[v]--;
      if (deg[v] == 0) {
        q[top++] = v;
      }
    }
  }
}

bool check(int u) {
  for (int i = 1; i <= n; i++) {
    a[i].clear();
    deg[i] = 0;
  }
  for (int i = 1; i <= u; i++) {
    a[x[i]].push_back(y[i]);
    deg[y[i]]++;
  }
  go();
  int maxval = 0;
  for (int i = 1; i <= n; i++) {
    maxval = max(maxval, h[i]);
  }
  return maxval >= n - 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    x[i] = u;
    y[i] = v;
  }
  int l = 0, r = m + 1;
  while (r - l > 1) {
    int mi = (l + r) >> 1;
    if (check(mi)) {
      r = mi;
    } else {
      l = mi;
    }
  }
  cout << (r == m + 1 ? -1 : r) << endl;
  return 0;
}