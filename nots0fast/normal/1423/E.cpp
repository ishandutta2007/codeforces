#pragma GCC optimize("O3,fast-math")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using ordered_set = __gnu_pbds::tree<T,
      __gnu_pbds::null_type,
      less<T>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
using ld = double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

namespace ubc {
  using pol = vector<pt>;

  ld cp(const pt& a, const pt& b) {
    return imag(conj(a) * b);
  }

  ld dp(const pt& a, const pt& b) {
    return real(conj(a) * b);
  }

  ld lsp_dist(const pt &a, const pt &b, const pt &p) {
    return dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0 ?
      abs(cp(b - a, p - a) / abs(b - a)) : min(abs(a - p), abs(b - p)); }

  // Does NOT include points on the ends of the segment.
  inline bool on_segment(const pt &a, const pt &b, const pt &p) {
    return abs(cp(b-a, p-a)) / abs(a-b) < EPS &&
      dp(b-a, p-a)>0 && dp(a-b, p-b)>0; }

  // Checks if p lies on the boundary of a polygon v.
  inline bool on_boundary(const pol &v, const pt &p) {
    bool res = 0; for(int i=v.size()-1, j=0; j<v.size(); i=j++) {
      res |= on_segment(v[i], v[j], p) || abs(p-v[i]) < EPS; }
    return res; }

  // orientation does not matter !!!
  bool pt_in_polygon(const pt &p, const pol &v, bool strict=false) {
    if (on_boundary(v,p)) return !strict;
    ld res = 0; for(int i = v.size() - 1, j = 0; j < v.size(); i = j++) {
      res += atan2(cp(v[i] - p, v[j] - p), dp(v[i] - p, v[j] - p)); }
    return abs(res) > 1; } // will be either 2*PI or 0
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  double _;
  int n;
  scanf("%lf%lf%d", &_, &_, &n);
  vector<vector<pt>> ps;
  vector<ld> area;
  for(int i=0; i<n; i++) {
    int m;
    scanf("%d", &m);
    vector<pt> v;
    for(int j=0; j<m; j++) {
      double a, b;
      scanf("%lf%lf", &a, &b);
      v.emplace_back(a, b);
    }
    ld res = 0;
    for(int j=m-1, k=0; k<m; j=k++) {
      res += ubc::cp(v[j], v[k]);
    }
    area.push_back(abs(res) / 2);
    ps.emplace_back(move(v));
  }

  int T;
  scanf("%d", &T);
  while(T--) {
    double x, y, r;
    scanf("%lf%lf%lf", &x, &y, &r);
    pt c(x, y);
    ld res = 0;
    vector<int> out;
    for(int t=0; t<n; t++) {
      const vector<pt>& v = ps[t];
      int m = size(v);
      bool ok = !ubc::pt_in_polygon(c, v);
      for(int i=m-1, j=0; j<m && ok; i=j++) {
        ok &= (ubc::lsp_dist(v[i], v[j], c) > r);
      }
      if(!ok) {
        res += area[t];
        out.push_back(t);
      }
    }
    cout << res << " " << out.size();
    for (int i : out) {
      cout << " " << i;
    }
    cout << nl;
  }

  return 0;
}