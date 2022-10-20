#include <bits/stdc++.h>

using namespace std;

const int N = 200010, MOD = 1000000007;

int n, q;
int a[N];
vector <pair<int, int> > pos[N];
long long res[N];
long long x[N];
int pre[1000010], b[1000010];
long long inv[1000010], inv2[1000010];

struct BIT {
  long long t[N];

  void init() {
    for (int i = 1; i <= n; i++) {
      t[i] = 1;
    }
  }

  void add(int x, int val) {
    while (x <= n) {
      t[x] = t[x] * val % MOD;
      x += (x & -x);
    }
  }

  long long get(int x) {
    long long res = 1;
    while (x) {
      res = res * t[x] % MOD;
      x -= (x & -x);
    }
    return res;
  }
} t1;

long long power(long long u, int v) {
  long long res = 1;
  while (v) {
    if (v & 1) {
      res = res * u % MOD;
    }
    u = u * u % MOD;
    v >>= 1;
  }
  return res;
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  t1.init();
  x[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    x[i] = x[i - 1] * a[i] % MOD;
  }
  for (int i = 2; i <= 1000000; i++) {
    if (b[i]) {
      continue;
    }
    inv[i] = power(i, MOD - 2);
    inv2[i] = power(i - 1, MOD - 2);
    for (int j = i; j <= 1000000; j += i) {
      b[j] = i;
    }
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    pos[r].push_back(make_pair(l, i));
  }
  for (int i = 1; i <= n; i++) {
    int u = a[i];
    vector <int> prime;
    while (u > 1) {
      int v = b[u];
      prime.push_back(v);
      while (u % v == 0) {
        u /= v;
      }
    }
    for (int foo : prime) {
      t1.add(pre[foo] + 1, foo - 1);
      t1.add(pre[foo] + 1, inv[foo]);
      t1.add(i + 1, inv2[foo]);
      t1.add(i + 1, foo);
      pre[foo] = i;
    }
    for (auto bp : pos[i]) {
      int l = bp.first;
      int id = bp.second;
      long long bar = x[i] * power(x[l - 1], MOD - 2) % MOD;
      bar = bar * t1.get(l) % MOD;
      res[id] = bar;
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", (int)res[i]);
  }
  return 0;
}