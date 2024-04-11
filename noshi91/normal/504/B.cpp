/*
https://codeforces.com/group/YtWezOhH3S/contest/504/submission/58854101
*/

#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL << 60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b - 1); i >= (a); --i)
#define REP(i, n) FOR(i, 0, (n))
#define RREP(i, n) RFOR(i, 0, (n))
#define ITR(itr, mp) for (auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr, mp) for (auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i, a, b) ((a) <= (i) && (i) < (b))
#define debug(x) cout << #x << " = " << (x) << endl;
#define SP << " " <<
typedef pair<int, int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int dummy_count = 0;

template <typename T> struct SegmentTree {
  using F = function<T(T, T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f, T ti) : f(f), ti(ti) {}
  void init(int n_) {
    n = 1;
    while (n < n_)
      n <<= 1;
    dat.assign(n << 1, ti);
  }
  void build(const vector<T> &v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++)
      dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }
  void update(int k, T x) {
    dat[k += n] = x;
    while (k >>= 1)
      dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }
  void add(int k, T x) {
    dat[k += n] += x;
    while (k >>= 1)
      dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }
  T query(int a, int b) {
    T vl = ti, vr = ti;
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        vl = f(vl, dat[l++]);
      if (r & 1)
        vr = f(dat[--r], vr);
    }
    return f(vl, vr);
  }
  /*
  template <typename C>
  int find(int a, int b, C &check, T x, int k = 1, int l = 0, int r = -1) {
    if (r < 0)
      r = n;
    if (!check(f(x, dat[k])) || r <= a || b <= l)
      return -1;
    if (r - l == 1)
      return l;
    int xl = find(a, b, check, x, (k << 1), l, (l + r) / 2);
    if (xl >= 0)
      return xl;
    x = f(x, dat[(k << 1)]);
    return find(a, b, check, x, (k << 1) | 1, (l + r) / 2, r);
  }
  template <typename C> int find(int a, int b, C &check) {
    T x = ti;
    return find(a, b, check, x);
  }
  */
  template <typename C> int find(int a, int b, C &check) {
    ++dummy_count;

    // assume a == 0 && b == n
    T x = ti;
    int i = 1;
    while (i < n)
      if (!check(f(x, dat[i *= 2])))
        x = f(x, dat[i++]);
    return i - n;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i, n) cin >> a[i];

  vector<int> b(n);
  REP(i, n) cin >> b[i];

  auto f = [](int a, int b) { return a + b; };
  SegmentTree<int> seg(f, 0), seg2(f, 0);
  seg.build(vector<int>(n, 1));
  seg2.build(vector<int>(n, 1));

  vec fact1(n + 1), fact2(n + 1);
  REP(i, n) {
    fact1[i + 1] = seg.query(0, a[i]);
    seg.add(a[i], -1);

    fact2[i + 1] = seg2.query(0, b[i]);
    seg2.add(b[i], -1);
  }

  vec c(n + 1, 0);
  int m = 1;
  RREP(i, n) {
    c[i] += (fact1[i + 1] + fact2[i + 1] + c[i + 1]) / m;
    c[i + 1] = (fact1[i + 1] + fact2[i + 1] + c[i + 1]) % m;
    m++;
  }

  vec ans(n);
  seg.build(vec(n, 1));
  FOR(i, 1, n + 1) {
    auto check = [&](int x) { return x >= c[i] + 1; };
    int id = seg.find(0, n, check);
    id = seg.find(0, n, check);
    ans[i - 1] = id;
    seg.add(id, -1);
  }

  REP(i, n) cout << ans[i] << " ";
  cout << endl;

  if (dummy_count > 100000000) {
    cout << "hello";
  }

  return 0;
}