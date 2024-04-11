#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 1000000007;

inline int add(int u, int v) {
  return u + v >= MOD ? u + v - MOD : u + v;
}

inline int mul(int u, int v) {
  return (long long) u * v % MOD;
}

inline int power(int u, int v) {
  int res = 1;
  while (v) {
    if (v & 1) {
      res = mul(res, u);
    }
    u = mul(u, u);
    v >>= 1;
  }
  return res;
}

char s[N];
int numQuery;
int fac[N], invFac[N];
int f[N];

struct Query {
  int len, n, id;
  Query(int len = 0, int n = 0, int id = 0) {
    this->len = len;
    this->n = n;
    this->id = id;
  }
} q[N];

int res[N], p[N];

bool cmp(const Query &u, const Query &v) {
  return u.len < v.len;
}

inline int c(int n, int k) {
  return mul(mul(fac[n], invFac[n - k]), invFac[k]);
}

int main() {
  int m;
  scanf("%d", &m);
  int len;
  scanf("%s", s);
  len = strlen(s);
  for (int i = 1; i <= m; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%s", s);
      len = strlen(s);
    } else {
      int n;
      scanf("%d", &n);
      numQuery++;
      q[numQuery] = Query(len, n, numQuery);
    }
  }
  sort(q + 1, q + numQuery + 1, cmp);
  fac[0] = invFac[0] = p[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = mul(fac[i - 1], i);
    invFac[i] = power(fac[i], MOD - 2);
    p[i] = mul(p[i - 1], 25);
  }
  for (int i = 1; i <= numQuery; i++) {
    int last = i;
    while (last < numQuery && q[last + 1].len == q[i].len) {
      last++;
    }
    memset(f, 0, sizeof f);
    f[q[i].len] = 1;
    for (int j = q[i].len + 1; j < N; j++) {
      f[j] = add(mul(f[j - 1], 26), mul(p[j - q[i].len], c(j - 1, q[i].len - 1)));
    }
    for (int j = i; j <= last; j++) {
      res[q[j].id] = f[q[j].n];
    }
    i = last;
  }
  for (int i = 1; i <= numQuery; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}