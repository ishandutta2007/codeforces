#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int P = 998244353, R = 3;

int mpow(int x, int k, int p = P) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % p;
    x = x * (ll)x % p;
    k >>= 1;
  }
  return ret;
}

int norm(int x) { return x >= P ? x - P : x; }

struct NumberTheory {

  typedef pair<int, int> _P2_Field;

  mt19937 rng;

  NumberTheory() : rng(chrono::steady_clock::now().time_since_epoch().count()) {}

  void _exGcd(int a, int b, int& x, int& y) {
    if (!b) {
      x = 1;
      y = 0;
      return;
    }
    _exGcd(b, a % b, y, x);
    y -= a / b * x;
  }

  int inv(int a, int p = P) {
    int x, y;
    _exGcd(a, p, x, y);
    if (x < 0)
      x += p;
    return x;
  }

  template <class Integer>
  bool quadRes(Integer a, Integer b) {
    if (a <= 1)
      return true;
    while (a % 4 == 0)
      a /= 4;
    if (a % 2 == 0)
      return (b % 8 == 1 || b % 8 == 7) == quadRes(a / 2, b);
    return ((a - 1) % 4 == 0 || (b - 1) % 4 == 0) == quadRes(b % a, a);
  }

  // assume p in prime, x in quadratic residue
  int sqrt(int x, int p = P) {
    if (p == 2 || x <= 1)
      return x;
    int w, v, k = (p + 1) / 2;
    do {
      w = rng() % p;
    } while (quadRes(v = int((w * (ll)w - x + p) % p), p));
    _P2_Field res(1, 0), a(w, 1);
    while (k) {
      if (k & 1)
        res = _P2_Field((res.first * (ll)a.first + res.second * (ll)a.second % p * v) % p, (res.first * (ll)a.second + res.second * (ll)a.first) % p);
      if (k >>= 1)
        a = _P2_Field((a.first * (ll)a.first + a.second * (ll)a.second % p * v) % p, (a.first * (ll)a.second << 1) % p);
    }
    return min(res.first, p - res.first);
  }

} nt;

template <class T, class Comp>
struct AdditionChain {
  int k;
  vector<T> prepare;
  T t, unit;
  Comp comp;

  AdditionChain(const T& t, const Comp& comp, int k, const T& unit = 1) : comp(comp), t(t), unit(unit), k(k), prepare(1U << k) {
    prepare[0] = unit;
    for (int i = 1; i < 1 << k; ++i)
      prepare[i] = comp(prepare[i - 1], t);
  }

  static AdditionChain fourRussians(const T &t, const Comp &comp, int lgn, const T &unit = 1) {
    lgn = max(lgn, 1);
    int k = 1, lglgn = 1;
    while (2 << lglgn <= lgn)
      ++lglgn;
    int w = lglgn / lgn;
    while (1 << k < w)
      ++k;
    return AdditionChain(t, comp, k, unit);
  }

  T pow(int n) const {
    if (n < 1 << k)
      return prepare[n];
    int r = n & ((1 << k) - 1);
    T step = pow(n >> k);
    for (int rep = 0; rep < k; ++rep)
      step = comp(step, step);
    return comp(step, prepare[r]);
  }
};

struct Simple {
  int n;
  vector<int> fac, ifac, inv;

  void build(int n) {
    this->n = n;
    fac.resize(n + 1);
    ifac.resize(n + 1);
    inv.resize(n + 1);
    fac[0] = 1;
    for (int x = 1; x <= n; ++x)
      fac[x] = fac[x - 1] * (ll)x % P;
    inv[1] = 1;
    for (int x = 2; x <= n; ++x)
      inv[x] = -(P / x) * (ll)inv[P % x] % P + P;
    ifac[0] = 1;
    for (int x = 1; x <= n; ++x)
      ifac[x] = ifac[x - 1] * (ll)inv[x] % P;
  }

  Simple() {
    build(1);
  }

  void check(int k) {
    int nn = n;
    if (k > nn) {
      while (k > nn)
        nn <<= 1;
      build(nn);
    }
  }

  int gfac(int k) {
    check(k);
    return fac[k];
  }

  int gifac(int k) {
    check(k);
    return ifac[k];
  }

  int ginv(int k) {
    check(k);
    return inv[k];
  }

  int binom(int n, int m) {
    if (m < 0 || m > n)
      return 0;
    return gfac(n) * (ll)gifac(m) % P * gifac(n - m) % P;
  }
} simp;

const int N = 200010;

int n, k;
int h[N], prod[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> h[i];
  int same = 0;
  for (int i = 0; i < n; ++i)
    if (h[i] == h[(i + 1) % n])
      ++same;
  prod[0] = 1;
  for (int i = 1; i <= n - same; ++i)
    prod[i] = prod[i - 1] * (P + k - 2LL) % P;
  int cur = 0, sum = 0, ans = 0;
  for (int i = 1; i <= n - same; ++i) {
    sum = (sum * 2LL + P - simp.binom(i - 1, cur - 1)) % P;
    if (cur * 2 < i) {
      sum = (sum + simp.binom(i, cur)) % P;
      ++cur;
    }
    //cerr << i << ": " << cur << " " << sum << '\n';
    ans = (ans + sum * (ll)prod[n - same - i] % P * simp.binom(n - same, i)) % P;
  }
  ans = ans * (ll)mpow(k, same) % P;
  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}