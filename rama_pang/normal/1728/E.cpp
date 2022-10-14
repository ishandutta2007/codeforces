#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

bool find_any_solution(long long a, long long b, long long c, long long &x0,
                       long long &y0, long long &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g) {
    return false;
  }

  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

void Main() {
  long long n;
  cin >> n;
  long long SUM = 0;
  vector<long long> a(n), b(n);
  vector<long long> c(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    c[i] = a[i] - b[i];
    SUM += b[i];
  }
  sort(begin(c), end(c));
  reverse(begin(c), end(c));
  c.insert(begin(c), 0);
  for (long long i = 1; i < (c.size()); i++) {
    c[i] += c[i - 1];
  }
  long long q;
  cin >> q;
  map<pair<long long, long long>, long long> memo;
  while (q--) {
    long long x, y, x0, y0, g;
    cin >> x >> y;
    if (!find_any_solution(x, y, n, x0, y0, g)) {
      cout << "-1\n";
      continue;
    }
    long long jumpx = y / g;
    long long jumpy = x / g;

    long long MIN = -1e9, MAX = 1e9;
    {
      long long lo = -1e9, hi = 1e9;
      while (lo < hi) {
        long long md = (lo + hi) >> 1;
        if (x0 + md * jumpx < 0) {
          lo = md + 1;
        } else {
          hi = md;
        }
      }
      MIN = max(MIN, lo);
    }
    {
      long long lo = -1e9, hi = 1e9;
      while (lo < hi) {
        long long md = (lo + hi + 1) >> 1;
        if (x0 + md * jumpx <= n) {
          lo = md;
        } else {
          hi = md - 1;
        }
      }
      MAX = min(MAX, lo);
    }
    {
      long long lo = -1e9, hi = 1e9;
      while (lo < hi) {
        long long md = (lo + hi) >> 1;
        if (y0 - md * jumpy > n) {
          lo = md + 1;
        } else {
          hi = md;
        }
      }
      MIN = max(MIN, lo);
    }
    {
      long long lo = -1e9, hi = 1e9;
      while (lo < hi) {
        long long md = (lo + hi + 1) >> 1;
        if (y0 - md * jumpy >= 0) {
          lo = md;
        } else {
          hi = md - 1;
        }
      }
      MAX = min(MAX, lo);
    }
    if (MIN > MAX) {
      cout << "-1\n";
      continue;
    }
    // max(x0): c[x0 + k * jumpx] for k in [MIN, MAX]
    x0 += MIN * jumpx;
    MAX -= MIN;
    x0 *= x;
    jumpx *= x;
    // cout << x0 << ' ' << jumpx << ' ' << MAX << '\n';
    // continue;
    assert(x0 < jumpx);
    assert(0 <= x0 && x0 <= n);
    assert(0 <= x0 + MAX * jumpx && x0 + MAX * jumpx <= n);
    assert(x0 + (MAX + 1) * jumpx > n);
    if (memo.count({x0, jumpx})) {
      cout << memo[{x0, jumpx}] << '\n';
      continue;
    }
    long long ret = -1e18;
    for (long long k = x0; k <= n; k += jumpx) {
      ret = max(ret, c[k]);
    }
    memo[{x0, jumpx}] = ret + SUM;
    cout << ret + SUM << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  long long T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
}