#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// change null_type to int if we want to use map instead
// find_by_order(k) returns an iterator to the k-th element (0-indexed)
// order_of_key(k) returns numbers of item being strictly smaller than k
template <typename T = int>
using OrderedSet =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <int MOD>
class Modular {
  static_assert(MOD >= 0, "MOD can't be negative!");
  static_assert(MOD * 2 > 0, "MOD is too large for int");

 public:
  explicit Modular(long long v = 0) : v_((v %= MOD) < 0 ? v + MOD : v) {}

  Modular Inv() const { return Modular(Inverse(v_, MOD)); }
  Modular Power(long long v) const {
    Modular res(1), u(*this);
    for (; v; v >>= 1, u *= u)
      if (v & 1) res *= u;
    return res;
  }

  explicit operator int() const { return v_; }
  explicit operator bool() const { return static_cast<bool>(v_); }
  Modular& operator++() { return *this += Modular(1); }
  Modular& operator--() { return *this -= Modular(1); }
  Modular operator++(int) {
    Modular result(*this);
    *this += Modular(1);
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= Modular(1);
    return result;
  }
  Modular operator-() const { return Modular(-v_); }
  Modular operator+() const { return Modular(*this); }
  Modular& operator+=(const Modular& other) {
    if ((v_ += other.v_) >= MOD) v_ -= MOD;
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((v_ -= other.v_) < 0) v_ += MOD;
    return *this;
  }
  Modular& operator*=(const Modular& other) {
    v_ = 1ll * v_ * other.v_ % MOD;
    return *this;
  }
  Modular& operator/=(const Modular& other) { return *this *= other.Inv(); }

  friend bool operator==(const Modular& lhs, const Modular& rhs) {
    return lhs.v_ == rhs.v_;
  }
  friend bool operator!=(const Modular& lhs, const Modular& rhs) {
    return !(lhs == rhs);
  }
  friend Modular operator+(const Modular& lhs, const Modular& rhs) {
    return Modular(lhs) += rhs;
  }
  friend Modular operator-(const Modular& lhs, const Modular& rhs) {
    return Modular(lhs) -= rhs;
  }
  friend Modular operator*(const Modular& lhs, const Modular& rhs) {
    return Modular(lhs) *= rhs;
  }
  friend Modular operator/(const Modular& lhs, const Modular& rhs) {
    return Modular(lhs) /= rhs;
  }
  friend std::istream& operator>>(std::istream& in, Modular& number) {
    long long v;
    in >> v;
    number = Modular(v);
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const Modular& number) {
    return out << int(number);
  }
  friend string to_string(const Modular& number) {
    return to_string(int(number));
  }

 private:
  // return u : a * u == 1 (mod m)
  // NOTE: CAN'T assume that 0 <= u < m
  static int Inverse(int a, int m) {
    assert(a && "Divide by zero");
    auto u = 0, v = 1;
    while (a) {
      auto t = m / a;
      m -= t * a;
      swap(a, m);
      u -= t * v;
      swap(u, v);
    }
    assert(m == 1 && "Can't find inversion");
    return u;
  }

  int v_;
};
constexpr int MOD = 998244353;
using Mint = Modular<MOD>;

const int N = 400010;

Mint fact[N], inv_fact[N];

Mint Binom(int n, int k) {
  if (k > n || k < 0) return Mint(0);
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

void Solve(int test) {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> x(m);
  for (auto &[u, v] : x) {
    cin >> u >> v;
  }

  vector<int> pos(x.size());

  OrderedSet<int> available;
  for (int i = m - 1; i >= 0; i--) {
    int low = 0, high = n + 1;
    while (high - low > 1) {
      int mid = low + high >> 1;
      int smaller = available.order_of_key(mid + 1);
      int num = mid - smaller;
      if (num < x[i].second) low = mid;
      else high = mid;
    }
    pos[i] = high;
    available.insert(high);
  }

  debug(pos);

  vector<pair<int, int>> ls;
  for (int i = 0; i < m; i++) {
    ls.push_back({pos[i], x[i].first});
  }

  sort(ls.begin(), ls.end());
  debug(ls);
  int num_zeroes = n - 1;
  for (int i = 0; i < ls.size(); i++) {
    if (i + 1 == ls.size()) {
      num_zeroes -= (ls[i].first < n);
    } else {
      if (ls[i].first + 1 == ls[i + 1].first) {
        num_zeroes -= ls[i].second > ls[i + 1].second;
      } else {
        num_zeroes--;
      }
    }
  }

  cout << Binom(n + num_zeroes, n) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  fact[0] = Mint(1);
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * Mint(i);
  }

  inv_fact[N - 1] = fact[N - 1].Inv();
  for (int i = N - 2; i >= 0; i--) {
    inv_fact[i] = inv_fact[i + 1] * Mint(i + 1);
  }

  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}