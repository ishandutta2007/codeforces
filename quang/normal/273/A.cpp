#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
long long t[N];

void add(int u, long long v) {
  while (u <= n) {
    t[u] = max(t[u], v);
    u += (u & -u);
  }
}

long long get(int u) {
  long long res = 0;
  while (u) {
    res = max(res, t[u]);
    u -= (u & -u);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    add(i, u);
  }
  int m;
  cin >> m;
  while (m--) {
    int w, h;
    cin >> w >> h;
    long long x = get(w);
    printf("%I64d\n", x);
    add(1, x + h);
  }
  return 0;
}