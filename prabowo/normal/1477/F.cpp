#include <bits/stdc++.h>
using namespace std;

using poly = vector<int>;
using poly2d = vector<poly>;

const int N = 55;
const int L = 2005;
const int MOD = 998244353;

int n, K;
int l[N];

int fact[L*N];
int ifact[L*N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

poly multiply(const poly &p, const poly &q) {
  poly ret(p.size() + q.size() - 1);
  for (int i = 0; i < p.size(); ++i) for (int j = 0; j < q.size(); ++j) {
    ret[i + j] = (1LL * p[i] * q[j] + ret[i + j]) % MOD;
  }
  return ret;
}

void iadd(poly &p, const poly &q) {
  if (p.size() < q.size()) p.resize(q.size());
  for (int i = 0; i < q.size(); ++i) p[i] = (p[i] + q[i]) % MOD;
}

poly2d multiply(const poly2d &p, const poly2d &q) {  
  poly2d ret(p.size() + q.size() - 1);
  for (int i = 0; i < p.size(); ++i) for (int j = 0; j < q.size(); ++j) {
    iadd(ret[i + j], multiply(p[i], q[j]));
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &K);
  int sumL = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &l[i]);
    sumL += l[i];
  }

  fact[0] = 1;
  for (int i = 1; i <= sumL; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[sumL] = power(fact[sumL], MOD - 2);
  for (int i = sumL - 1; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;

  int isumL = power(sumL, MOD - 2);

  priority_queue<pair<int, poly2d>, vector<pair<int, poly2d>>, greater<pair<int, poly2d>>> pq;
  for (int j = 0; j < n; ++j) {
    int x = l[j] / K - (l[j] % K == 0);
    poly2d Q(x + 1);
    Q[0] = {1};
    for (int k = 1; k <= x; ++k) {
      int c = 1LL * (l[j] - k*K) * isumL % MOD;
      int ck = power(c, k - 1);
      Q[k] = {static_cast<int>(1LL * ck * c % MOD * ifact[k] % MOD), static_cast<int>(1LL * ck * ifact[k - 1] % MOD)};
      if (k & 1) {
        Q[k][0] = MOD - Q[k][0]; Q[k][1] = MOD - Q[k][1];
      }
    }

    pq.emplace(x*2 + 1, Q);
  }

  while (pq.size() > 1) {
    poly2d p, q;
    int sz1, sz2;
    tie(sz1, p) = pq.top(); pq.pop();
    tie(sz2, q) = pq.top(); pq.pop();

    poly2d r = multiply(p, q);
    int sz = 0; for (int i = 0; i < r.size(); ++i) sz += r[i].size();
    pq.emplace(sz, r);
  }

  poly2d P = pq.top().second; // P[k][j] = coeff. of x^(k-j) * exp(1 - K/sumL * kx)

  int ans = 0;
  for (int k = 1; k < P.size(); ++k) {
    int c = power(1LL * K * k * isumL % MOD, MOD - 2);
    int den = power(c, k - P[k].size() + 2);
    for (int j = (int) P[k].size() - 1; j >= 0; --j) {
      ans = (1LL * den % MOD * fact[k - j] % MOD * P[k][j] + ans) % MOD;
      den = 1LL * den * c % MOD;
    }
  }
  ans = (MOD - ans) % MOD;

  printf("%d\n", ans);
  return 0;
}