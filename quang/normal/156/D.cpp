#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, k;
vector <int> a[N];
int used[N], cnt;
int st[N], top;

long long qpow(long long u, long long v) {
  long long res = 1;
  while (v) {
    if (v & 1) {
      res = res * u % k;
    }
    u = u * u % k;
    v >>= 1;
  }
  return res;
}

int go(int x) {
  st[0] = x;
  used[x] = 1;
  top = 1;
  for (int i = 0; i < top; i++) {
    int u = st[i];
    for (int v : a[u]) {
      if (used[v]) {
        continue;
      }
      used[v] = 1;
      st[top++] = v;
    }
  }
  return top;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  long long res = 1;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      res = res * go(i) % k;
      cnt++;
    }
  }
  if (cnt == 1) {
    printf("%d", 1 % k);
    return 0;
  }
  res = res * qpow(n, cnt - 2) % k;
  cout << res << endl;
  return 0;
}