#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const long long INF = (1ll << 40);

int n, m, k;
vector <int> a[2][2][N];

long long get1(const vector <int> &u, int delta, int p) {
  if (u.empty()) {
    return INF;
  }
  int res = 0;
  if (delta >= 0) {
    res = u[0];
  } else {
    int foo = (-delta - 1) / m + 1;
    int pos = lower_bound(u.begin(), u.end(), foo) - u.begin();
    if (pos >= (int)u.size()) {
      return INF;
    }
    res = u[pos];
  }
  if (((1ll * res * m + delta) / n) % 2 == p) {
    return res;
  }
  return INF;
}

long long get(int p1, int p2, int x, int y) {
  int foo = ((x - y) % n + n) % n;
  long long res = get1(a[p2][0][foo], y - x, p1);
  res = min(res, get1(a[p2][1][foo], y - x, p1));
  return (res >= INF ? INF : res * m + y);
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    long long foo = 1ll * i * m;
    long long u = foo % n;
    long long v = foo / n;
    a[i % 2][v % 2][u].push_back(i);
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x == y) {
      printf("%d\n", x);
      continue;
    }
    long long res = INF;
    res = min(res, get(0, 0, x, y));
    res = min(res, get(0, 1, x, m - y));
    res = min(res, get(1, 0, n - x, y));
    res = min(res, get(1, 1, n - x, m - y));
    printf("%I64d\n", (res >= INF ? -1 : res));
  }
	return 0;
}