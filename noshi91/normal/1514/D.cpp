/*

:
https://codeforces.com/contest/1514/submission/113590797


*/

/*
!
Be accepted!

)*
  +.
+ *)
 . .*) .*)
          (. (.'* 
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <queue>
#include <regex>
#include <functional>
#include <complex>
#include <list>
#include <cassert>
#include <iomanip>
#include <set>
#include <stack>
#include <bitset>
#include <array>
#include <chrono>

//#pragma GCC target("arch=skylake-avx512")
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse4")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define repeat(i, n, m) for(int i = n; i < (m); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printim(a) printf(a ? "possible\n" : "imposible\n")
#define printdb(a) printf("%.50lf\n", a)
#define printLdb(a) printf("%.50Lf\n", a)
#define printdbd(a) printf("%.16lf\n", a)
#define prints(s) printf("%s\n", s.c_str())
#define all(x) (x).begin(), (x).end()
#define deg_to_rad(deg) (((deg)/360.0L)*2.0L*PI)
#define rad_to_deg(rad) (((rad)/2.0L/PI)*360.0L)
#define Please return
#define AC 0
#define manhattan_dist(a, b, c, d) (abs(a - c) + abs(b - d))

using ll = long long;
using ull = unsigned long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1e9 + 7;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-6;
const long double PI = acosl(-1.0L);

using namespace std;

void scans(string& str) {
    char c;
    str = "";
    scanf("%c", &c);
    if (c == '\n')scanf("%c", &c);
    while (c != '\n' && c != -1 && c != ' ') {
        str += c;
        scanf("%c", &c);
    }
}

void scanc(char& str) {
    char c;
    scanf("%c", &c);
    if (c == -1)return;
    while (c == '\n') {
        scanf("%c", &c);
    }
    str = c;
}

double acot(double x) {
    return PI / 2 - atan(x);
}

ll LSB(ll n) { return (n & (-n)); }

template<typename T>
inline T chmin(T& a, const T& b) {
    if (a > b)a = b;
    return a;
}

template<typename T>
inline T chmax(T& a, const T& b) {
    if (a < b)a = b;
    return a;
}

//cpp_int
#if __has_include(<boost/multiprecision/cpp_int.hpp>)
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;
#else
using cpp_int = ll;
#endif

//atcoder library
#if __has_include(<atcoder/all>)
#include <atcoder/all>
//using namespace atcoder;
#endif

/*
    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_int_distribution dist(1, 100);
*/


/*----------------------------------------------------------------------------------*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <vector>
#include <utility>

class range_mode_query {
  using u32 = std::uint32_t;

  class b_node {
  public:
    u32 value;
    u32 rank;

    b_node(const u32 value_, const u32 rank_) : value(value_), rank(rank_) {}
  };

  class s_node {
  public:
    u32 mode;
    u32 freq;

    s_node(const u32 mode_, const u32 freq_) : mode(mode_), freq(freq_) {}
  };

  u32 t;
  std::vector<b_node> b;
  std::vector<std::vector<u32>> q;
  std::vector<std::vector<s_node>> s;

public:
  range_mode_query() : range_mode_query(std::vector<int>()) {}
  range_mode_query(const std::vector<int> &a) : range_mode_query(a, a.size()) {}
  range_mode_query(const std::vector<int> &a, const int q_estimate)
      : t(), b(), q(), s() {
    const u32 n = a.size();
    if (n == 0) {
      return;
    }
    if (q_estimate <= 0) {
      t = n + 1;
    } else {
      t = std::round(0.46 * double(n) / std::sqrt(q_estimate));
    }
    if (t == 0) {
      t = 1;
    }
    b.assign(n, b_node(0, 0));
    q.assign(n, {});
    for (u32 i = 0; i != n; i += 1) {
      const u32 e = a[i];
      assert(e < n);
      b[i] = b_node(e, q[e].size());
      q[e].push_back(i);
    }
    s.assign(n / t + 1, std::vector<s_node>(n / t + 1, s_node(0, 0)));
    std::vector<u32> freq(n);
    for (u32 f = 0; f * t <= n; f += 1) {
      std::fill(freq.begin(), freq.end(), 0);
      s_node cur(0, 0);
      for (u32 l = f + 1; l * t <= n; l += 1) {
        for (u32 i = (l - 1) * t; i != l * t; i += 1) {
          const u32 e = a[i];
          freq[e] += 1;
          if (freq[e] > cur.freq) {
            cur = s_node(e, freq[e]);
          }
        }
        s[f][l] = cur;
      }
    }
  }

  std::pair<int, int> query(const int first_, const int last_) const {
    const u32 first = first_;
    const u32 last = last_;
    assert(first < last && last <= b.size());
    const u32 bf = (first + t - 1) / t;
    const u32 bl = last / t;
    s_node cur(0, 0);
    if (bf >= bl) {
      for (u32 i = first; i != last; i += 1) {
        const b_node &e = b[i];
        const std::vector<u32> &v = q[e.value];
        u32 idx;
        while ((idx = e.rank + cur.freq) < v.size() && v[idx] < last) {
          cur = s_node(e.value, cur.freq + 1);
        }
      }
    } else {
      cur = s[bf][bl];
      for (u32 i = first; i != bf * t; i += 1) {
        const b_node &e = b[i];
        const std::vector<u32> &v = q[e.value];
        u32 idx;
        while ((idx = e.rank + cur.freq) < v.size() && v[idx] < last) {
          cur = s_node(e.value, cur.freq + 1);
        }
      }
      for (u32 i = bl * t; i != last; i += 1) {
        const b_node &e = b[i];
        const std::vector<u32> &v = q[e.value];
        u32 idx;
        while ((idx = e.rank - cur.freq) < v.size() && v[idx] >= first) {
          cur = s_node(e.value, cur.freq + 1);
        }
      }
    }
    return {cur.mode, cur.freq};
  }
};

int main() {

    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d%d", &n, &q);
        vector<int> a(n);
        rep(i, n) {
            scanf("%d", &a[i]);
            --a[i];
        }
        range_mode_query rmq(a, q);
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            int num = rmq.query(l, r).second;
            printf("%d\n", max(1, num - (r - l - num)));
        }
    }

    Please AC;
}
//