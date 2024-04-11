#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int a[N][N];
int b[N][N];
int st[N];

bool check(int u) {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      b[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] >= u) {
        st[++cnt] = j;
      }
    }
    for (int j = 1; j <= cnt; j++) {
      for (int k = 1; k <= cnt; k++) {
        int u = st[j];
        int v = st[k];
        if (u == v) {
          continue;
        }
        if (b[u][v]) {
          return 1;
        }
        b[u][v] = 1;
      }
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int l = -1, r = 1000000001;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (check(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}