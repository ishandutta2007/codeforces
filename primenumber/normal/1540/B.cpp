#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
/*
 * harudake::modint
 *
 * Copyright (c) 2021 prime number
 *
 * This software is released under the MIT license.
 * see https://opensource.org/licenses/MIT
 *
 */
namespace harudake {

template <typename base_t, base_t MOD>
class static_modint;

using modint_1000000007 = static_modint<uint64_t, 1'000'000'007>;
using modint_998244353 = static_modint<uint64_t, 998'244'353>;

template <typename base_t, base_t MOD>
static_modint<base_t, MOD> add(const static_modint<base_t, MOD> lhs, const static_modint<base_t, MOD> rhs) {
  base_t tmp = lhs.val + rhs.val;
  if (tmp >= MOD) tmp -= MOD;
  return static_modint<base_t, MOD>::make_raw(tmp);
}

template <typename base_t, base_t MOD>
static_modint<base_t, MOD> sub(const static_modint<base_t, MOD> lhs, const static_modint<base_t, MOD> rhs) {
  base_t tmp = lhs.val + MOD - rhs.val;
  if (tmp >= MOD) tmp -= MOD;
  return static_modint<base_t, MOD>::make_raw(tmp);
}

template <typename base_t, base_t MOD>
static_modint<base_t, MOD> mul(const static_modint<base_t, MOD> lhs, const static_modint<base_t, MOD> rhs) {
  base_t tmp = lhs.val * rhs.val;
  tmp %= MOD;
  return static_modint<base_t, MOD>::make_raw(tmp);
}

// data types must be signed integer
inline int64_t inv (const int64_t a, const int64_t p) {
  return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
};

template <typename base_t, base_t MOD>
static_modint<base_t, MOD> div(const static_modint<base_t, MOD> lhs, const static_modint<base_t, MOD> rhs) {
  base_t tmp = lhs.val * inv(rhs.val, MOD);
  tmp %= MOD;
  return static_modint<base_t, MOD>::make_raw(tmp);
}

template <typename base_t, base_t MOD>
static_modint<base_t, MOD> pow(const static_modint<base_t, MOD> base, const uint64_t index) {
  if (index == 0) return static_modint<base_t, MOD> { 1 };
  if (index % 2 == 1) {
    return pow(base, index - 1) * base;
  } else {
    auto half = pow(base, index / 2);
    return half * half;
  }
}

template <typename base_t, base_t MOD>
class static_modint {
  using modint = static_modint;
 public:
  static constexpr base_t mod = MOD;
  static_modint() : val(0) {}
  static_modint(const base_t x) : val(x % MOD) {}
  static_modint(const modint&) = default;
  modint& operator=(const modint&) = default;
  modint& operator=(const base_t x) {
    val = x % MOD;
    return *this;
  }
  modint operator-() const { return val == 0 ? 0 : MOD - val; }
  explicit operator base_t() const { return val; }
  base_t get() const { return val; }
  constexpr base_t get_mod() const { return mod; }
  static modint make_raw(const base_t raw) {
    modint res;
    res.val = raw;
    return res;
  }
 private:
  friend modint add<base_t, MOD>(const modint, const modint);
  friend modint sub<base_t, MOD>(const modint, const modint);
  friend modint mul<base_t, MOD>(const modint, const modint);
  friend modint div<base_t, MOD>(const modint, const modint);
  base_t val;
};

template <typename base_t, base_t MOD>
static_modint<base_t, MOD> operator+(const static_modint<base_t, MOD> lhs, const static_modint<base_t, MOD> rhs) {
  return add(lhs, rhs);
}
template <typename base_t, base_t MOD>
static_modint<base_t, MOD> operator-(const static_modint<base_t, MOD> lhs, const static_modint<base_t, MOD> rhs) {
  return sub(lhs, rhs);
}
template <typename base_t, base_t MOD>
static_modint<base_t, MOD> operator*(const static_modint<base_t, MOD> lhs, const static_modint<base_t, MOD> rhs) {
  return mul(lhs, rhs);
}
template <typename base_t, base_t MOD>
static_modint<base_t, MOD> operator/(const static_modint<base_t, MOD> lhs, const static_modint<base_t, MOD> rhs) {
  return div(lhs, rhs);
}
template <typename base_t, base_t MOD>
static_modint<base_t, MOD> operator^(const static_modint<base_t, MOD> lhs, const uint64_t rhs) {
  return pow(lhs, rhs);
}

template <typename base_t, base_t MOD>
static_modint<base_t, MOD>& operator+=(static_modint<base_t, MOD>& lhs, const static_modint<base_t, MOD> rhs) {
  return lhs = lhs + rhs;
}
template <typename base_t, base_t MOD>
static_modint<base_t, MOD>& operator-=(static_modint<base_t, MOD>& lhs, const static_modint<base_t, MOD> rhs) {
  return lhs = lhs - rhs;
}
template <typename base_t, base_t MOD>
static_modint<base_t, MOD>& operator*=(static_modint<base_t, MOD>& lhs, const static_modint<base_t, MOD> rhs) {
  return lhs = lhs * rhs;
}
template <typename base_t, base_t MOD>
static_modint<base_t, MOD>& operator/=(static_modint<base_t, MOD>& lhs, const static_modint<base_t, MOD> rhs) {
  return lhs = lhs / rhs;
}
template <typename base_t, base_t MOD>
static_modint<base_t, MOD>& operator^=(static_modint<base_t, MOD>& lhs, const uint64_t rhs) {
  return lhs = lhs ^ rhs;
}

} // namespace harudake

using namespace harudake;
using modint = modint_1000000007;

vector<modint> fact(500), ifact(500), p2(500);
vector dp(500, vector<modint>(500));

modint comb(i64 n, i64 k) {
  return fact[n] * ifact[k] * ifact[n-k];
}

modint pow2(i64 n) {
  return p2[n];
}

pair<modint, vector<vi32>> dfs(const vector<vi32>& g, i32 i, i32 p = -1) {
  vector<vi32> depths(1);
  depths[0].push_back(i);
  modint ans = 0;
  for (auto&& to : g[i]) {
    if (to == p) continue;
    auto [chans, chd] = dfs(g, to, i);
    ans += chans;
    i64 n = size(depths);
    i64 m = size(chd);
    rep(j,n)rep(k,m) {
      i32 kk = k + 1;
      for(auto&& x : depths[j]) {
        for (auto&& y : chd[k]) {
          dump<<"@"<<x<<" "<<y<<" "<<j<<" "<<kk<<endl;
          if (x > y) {
            ans += dp[j][kk];
          } else {
            ans += dp[kk][j];
          }
        }
      }
    }
    if (m >= n) {
      depths.resize(m+1);
    }
    rep(k,m) {
      for (auto&& x : chd[k]) {
        depths[k+1].push_back(x);
      }
    }
  }
  return make_pair(ans, depths);
}

int main() {
  fact[0] = 1;
  rep(i,499) fact[i+1] = fact[i] * modint(i+1);
  ifact.back() = modint(1) / fact.back();
  rep(ri,499) {
    i32 i = 499 - ri;
    ifact[i-1] = ifact[i] * modint(i);
  }
  dump<<ifact[0].get()<<endl;
  p2[0] = 1;
  rep(i,499) {
    p2[i+1] = p2[i] * modint(2);
  }
  rep(i,500) {
    dp[0][i] = modint(1);
  }
  rep2(i,1,500) {
    dp[i][0] = modint(0);
    rep2(j,1,500) {
      dp[i][j] = (dp[i][j-1] + dp[i-1][j]) / modint(2);
    }
  }
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n;
  cin>>n;
  vector<vi32> g(n);
  rep(i,n-1) {
    i32 x,y;
    cin>>x>>y;
    --x;--y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  modint ans = 0;
  rep(root,n) {
    auto [cnt, v] = dfs(g, root);
    for (auto&& elems: v) {
      for(auto&& e : elems) {
        dump<<e<<" ";
      }
      dump<<endl;
    }
    dump<<root<<": "<<cnt.get()<<endl;
    ans += cnt;
  }
  ans /= modint(n);
  cout<<ans.get()<<endl;
  return 0;
}