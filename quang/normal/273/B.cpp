#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N], cnt, cnt2;
long long f[N * 2];
int d[N * 2];
vector <int> c;

int get(int u) {
  int x = 0;
  int u2 = u;
  while (u2 % 2 == 0) {
    x++;
    u2 >>= 1;
  }
  d[u] = d[u - 1] + x;
  return u2;
}

int qpow(long long u, int v) {
  long long res = 1;
  while (v) {
    if (v & 1) {
      res = res * u % m;
    }
    u = u * u % m;
    v >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c.push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    c.push_back(b[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      cnt++;
    }
  }
  cin >> m;
  sort(c.begin(), c.end());
  f[0] = 1;
  for (int i = 1; i <= n * 2; i++) {
    f[i] = f[i - 1] * get(i) % m;
  }
  long long res = 1;
  int x = c[0], cur = 0;
  for (int i = 0; i < c.size(); i++) {
    if (c[i] != x) {
      res = res * f[cur] % m;
      cnt2 += d[cur];
      cur = 1;
    } else {
      cur++;
    }
    x = c[i];
  }
  res = res * f[cur] % m;
  cnt2 += d[cur];
  cnt = cnt2 - cnt;
  res = res * qpow(2, cnt) % m;
  cout << res << endl;
  return 0;
}