#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}


inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
  return (int) ((long long) a * b % md);
#endif
  unsigned long long x = (long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (md)
  );
  return m;
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

namespace ntt {
  int base = 1;
  vector<int> roots = {0, 1};
  vector<int> rev = {0, 1};
  int max_base = -1;
  int root = -1;

  void init() {
    int tmp = md - 1;
    max_base = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      max_base++;
    }
    root = 2;
    while (true) {
      if (power(root, 1 << max_base) == 1) {
        if (power(root, 1 << (max_base - 1)) != 1) {
          break;
        }
      }
      root++;
    }
  }

  void ensure_base(int nbase) {
    if (max_base == -1) {
      init();
    }
    if (nbase <= base) {
      return;
    }
    assert(nbase <= max_base);
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      int z = power(root, 1 << (max_base - 1 - base));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = mul(roots[i], z);
      }
      base++;
    }
  }

  void fft(vector<int> &a) {
    int n = (int) a.size();
    assert((n & (n - 1)) == 0);
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
      if (i < (rev[i] >> shift)) {
        swap(a[i], a[rev[i] >> shift]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          int x = a[i + j];
          int y = mul(a[i + j + k], roots[j + k]);
          a[i + j] = x + y - md;
          if (a[i + j] < 0) a[i + j] += md;
          a[i + j + k] = x - y + md;
          if (a[i + j + k] >= md) a[i + j + k] -= md;
        }
      }
    }
  }

  vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
    int need = (int) (a.size() + b.size() - 1);
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    if (eq) b = a; else fft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; i++) {
      a[i] = mul(mul(a[i], b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    while (!a.empty() && a.back() == 0) {
        a.pop_back();
    }
    return a;
  }

  vector<int> square(vector<int> a) {
    return multiply(a, a, 1);
  }
};

const int N = 1e5 + 1;

vector <vector <int> > polys[N];
int l[N], r[N];
int who[N];
int sz[N];

vector <int> slozh(const vector <int> &a, const vector <int> &b)
{
    int n = (int) a.size(), m = (int) b.size();
    vector <int> c(max(n, m));
    for (int i = 0; i < n; i++) add(c[i], a[i]);
    for (int i = 0; i < m; i++) add(c[i], b[i]);
    return c;
}

pair <vector <int>, vector <int> > eval(const vector <vector <int> > &a)
{
    if (a.size() == 1)
    {
        auto ret = a[0];
        ret[0]++;
        return {ret, a[0]};
    }
    else
    {
        int m = (int) a.size() / 2;
        vector <vector <int> > l, r;
        for (int i = 0; i < m; i++)
        {
            l.push_back(a[i]);
        }
        for (int i = m; i < (int) a.size(); i++)
        {
            r.push_back(a[i]);
        }
        auto lf = eval(l), rf = eval(r);
        add(lf.first[0], -1);
        auto P = slozh(ntt::multiply(lf.first, rf.second), rf.first);
        auto Q = ntt::multiply(lf.second, rf.second);
        return {P, Q};
    }
}

vector <int> g[N];

void dfs(int v, int pr)
{
    vector <int> go;
    int deg = 0;
    for (int to : g[v])
    {
        if (to != pr)
        {
            go.push_back(to);
            deg++;
        }
    }
    if (deg == 0)
    {
        polys[v].push_back({0, 1});
        sz[v] = 1;
        who[v] = v;
    }
    else
    {
        if (deg == 2)
        {
            l[v] = go[0];
            r[v] = go[1];
            dfs(l[v], v);
            dfs(r[v], v);
            sz[v] = sz[l[v]] + sz[r[v]] + 1;
            if (sz[l[v]] < sz[r[v]])
            {
                swap(l[v], r[v]);
            }
            auto go = eval(polys[who[r[v]]]).first;
            go.insert(go.begin(), 0);
            polys[who[l[v]]].push_back(go);
            who[v] = who[l[v]];
        }
        else
        {
            int son = go[0];
            dfs(son, v);
            sz[v] = sz[son] + 1;
            who[v] = who[son];
            polys[who[v]].push_back({0, 1});
        }
    }
}

vector <int> binom(ll n, int k)
{
    if (n == 0)
    {
        vector <int> ret(k + 1);
        ret[0] = 1;
        return ret;
    }
    else if (n % 2 == 0)
    {
        auto a = binom(n / 2, k);
        a = ntt::square(a);
        a.resize(k + 1);
        return a;
    }
    else
    {
        auto a = binom(n - 1, k);
        for (int i = k; i >= 0; i--)
        {
            if (i != 0)
            {
                add(a[i], a[i - 1]);
            }
        }
        return a;
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector <int> fact(n + 1), rev_fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = mul(fact[i - 1], i);
    }
    for (int i = 0; i <= n; i++)
    {
        rev_fact[i] = inv(fact[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    auto solve = eval(polys[who[0]]).first;
    auto big_binoms = binom(x, n);
    for (int i = 0; i <= n; i++)
    {
        big_binoms[i] = mul(big_binoms[i], rev_fact[i]);
    }
    rev_fact.insert(rev_fact.begin(), 0);
    big_binoms = ntt::multiply(big_binoms, rev_fact);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        add(ans, mul(mul(solve[i], big_binoms[i]), fact[i - 1]));
    }
    cout << ans << '\n';
}