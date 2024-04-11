#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n;
int a[N], gtmax = 0;
int b[N], res = 0;

void DFS(int u, int v) {
  if (u >= (1 << n)) {
    gtmax = max(gtmax, v);
    b[u] = a[u];
    return;
  }
  DFS(u * 2, v + a[u * 2]);
  DFS(u * 2 + 1, v + a[u * 2 + 1]);
  b[u] = max(b[u * 2], b[u * 2 + 1]) + a[u];
}

void DFS2(int u, int v) {
  if (u >= (1 << n)) {
    return;
  }
  res += gtmax - b[u * 2] - v;
  DFS2(u * 2, gtmax - b[u * 2] - v + v + a[u * 2]);
  res += gtmax - b[u * 2 + 1] - v;
  DFS2(u * 2 + 1, gtmax - b[u * 2 + 1] - v + v + a[u * 2 + 1]);
}

int main() {
  //freopen("B.inp", "r", stdin);
  cin >> n;
  for (int i = 2; i <= (1 << (n + 1)) - 1; i++) {
    cin >> a[i];
  }
  DFS(1, 0);
  DFS2(1, 0);
  cout << res;
  return 0;
}