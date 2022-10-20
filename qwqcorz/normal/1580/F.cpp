#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;

template<unsigned P>
class modint {
  static_assert(1 <= P, "P must be a positive integer");

  using mint = modint<P>;

protected:
  unsigned v;

public:
  constexpr modint() : v() {}

  template<typename T,
           typename std::enable_if<std::is_integral<T>::value &&
                                       std::is_signed<T>::value,
                                   bool>::type = true>
  constexpr modint(T t_v) : v() {
    long long tmp = t_v % static_cast<long long>(P);
    if (tmp < 0) {
      tmp += P;
    }
    v = tmp;
  }

  template<typename T,
           typename std::enable_if<std::is_integral<T>::value &&
                                       std::is_unsigned<T>::value,
                                   bool>::type = true>
  constexpr modint(T t_v) : v() {
    v = t_v % P;
  }

  constexpr unsigned val() const {
    return v;
  }

  static constexpr unsigned mod() {
    return P;
  }

  static constexpr mint raw(unsigned v) {
    mint res;
    res.v = v;
    return res;
  }

  constexpr mint &operator+=(const mint &rhs) {
    v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
    return *this;
  }

  constexpr mint &operator++() {
    v + 1 < P ? ++v : v = 0;
    return *this;
  }

  constexpr mint operator++(int) {
    mint tmp = *this;
    v + 1 < P ? ++v : v = 0;
    return tmp;
  }

  constexpr mint &operator-=(const mint &rhs) {
    v < rhs.v ? v += P - rhs.v : v -= rhs.v;
    return *this;
  }

  constexpr mint &operator--() {
    v ? --v : v = P - 1;
    return *this;
  }
  
  constexpr mint operator--(int) {
    mint tmp = *this;
    v ? --v : v = P - 1;
    return tmp;
  }

  constexpr mint operator-() const {
    mint res;
    res.v = v ? P - v : 0;
    return res;
  }

  constexpr mint &operator*=(const mint &rhs) {
    v = static_cast<unsigned long long>(v) * rhs.v % P;
    return *this;
  }

  constexpr mint pow(unsigned long long b) const {
    mint a(*this), s(1);
    for (; b; b >>= 1) {
      if (b & 1) {
        s *= a;
      }
      a *= a;
    }
    return s;
  }

  constexpr mint inv() const {
    return pow(P - 2);
  }

  constexpr friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }

  constexpr friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }

  constexpr friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }

  constexpr friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs.v == rhs.v;
  }

  constexpr friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs.v != rhs.v;
  }

  friend std::istream &operator>>(std::istream &in, mint &x) {
    return in >> x.v;
  }

  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.v;
  }
};

constexpr unsigned pow_mod_constexpr(unsigned a, unsigned b, unsigned P) {
  unsigned s = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      s = static_cast<unsigned long long>(s) * a % P;
    }
    a = static_cast<unsigned long long>(a) * a % P;
  }
  return s;
}

constexpr unsigned primitive_root(unsigned n) {
  if (n == 998244353) {
    return 3;
  }
  unsigned x = n - 1;
  unsigned cnt = 0;
  unsigned div[20] = {};
  for (unsigned i = 2; i <= x / i; ++i) {
    if (x % i == 0) {
      div[cnt++] = i;
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    div[cnt++] = x;
  }
  unsigned g = 1;
  while (1) {
    bool ok = true;
    for (unsigned i = 0; i < cnt; ++i) {
      if (pow_mod_constexpr(g, (n - 1) / div[i], n) == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      return g;
    }
    ++g;
  }
  return 0;
}

template<unsigned P, unsigned L>
class modpoly {
  using mint = modint<P>;
  using poly = modpoly<P, L>;

public:
  typedef std::size_t size_type;

  static constexpr unsigned root = primitive_root(P);

protected:
  struct initializer {
    static constexpr size_type N = static_cast<size_type>(1) << L;

    mint omega[N], inv[N + 1];

    initializer() {
      for (size_type m = 1; m < N; m <<= 1) {
        mint w = mint(root).pow((P - 1) / (m << 1));
        omega[m] = 1;
        for (size_type i = 1; i < m; ++i) {
          omega[m + i] = omega[m + i - 1] * w;
        }
      }

      inv[1] = 1;
      for (size_type i = 2; i <= N; ++i) {
        inv[i] = -mint(static_cast<unsigned>(P / i)) * inv[P % i];
      }
    }

    std::vector<size_type> rev;

    void build_rev(size_type n) {
      if (n == rev.size()) {
        return;
      }
      size_type k = 0;
      while ((static_cast<size_type>(1) << k) < n) {
        ++k;
      }
      rev.resize(n);
      rev[0] = 0;
      for (size_type i = 1; i < n; ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
      }
    }
  };
  
  static initializer init;

  static constexpr unsigned DFT_mod_cnt = 
    std::min(std::numeric_limits<unsigned long long>::max()
      / (static_cast<unsigned long long>(P) * P) - 1, 
    static_cast<unsigned long long>(L));
  static constexpr size_type EXP_BLOCKS = 16;
  static constexpr size_type npos = -1;

  std::vector<mint> f;

  static constexpr size_type enlarge_to_pow2(size_type n) {
    size_type res = 1;
    while (res < n) {
      res <<= 1;
    }
    return res;
  }

public:
  modpoly() {}

  modpoly(size_type n) : f(n) {}

  modpoly(size_type n, const mint &v) : f(n, v) {}

  modpoly(const std::vector<mint> &t_f) : f(t_f) {}

  modpoly(std::vector<mint> &&t_f) : f(std::move(t_f)) {}

  modpoly(const mint &v) : f(1, v) {}

  modpoly(std::initializer_list<mint> l) : f(l) {}

  template<typename Iter,
           typename = typename std::enable_if<std::is_convertible<
               typename std::iterator_traits<Iter>::iterator_category,
               std::input_iterator_tag>::value>::type>
  modpoly(Iter first, Iter last) : f(first, last) {}

  const std::vector<mint> &vec() const {
    return f;
  }

  std::vector<mint> &vec() {
    return f;
  }

  std::vector<mint> rvec() {
    return std::move(f);
  }

  bool empty() const {
    return f.empty();
  }

  size_type size() const {
    return f.size();
  }

  typename std::vector<mint>::reference operator[](size_type x) {
    return f[x];
  }

  typename std::vector<mint>::const_reference operator[](size_type x) const {
    return f[x];
  }

  void resize(size_type t_n) {
    f.resize(t_n);
  }

  bool operator<(const poly &rhs) const {
    return f.size() < rhs.f.size();
  }

  bool operator>(const poly &rhs) const {
    return f.size() > rhs.f.size();
  }

  bool operator==(const poly &rhs) const {
    return f == rhs.f;
  }

  void DFT(size_type n) {
    init.build_rev(n);
    f.resize(n);
    static unsigned long long F[initializer::N];
    for (size_type i = 0; i < n; ++i) {
      F[init.rev[i]] = f[i].val();
    }
    for (size_type m = 1; m < n; m <<= 1) {
      if (m & (static_cast<size_type>(1) << DFT_mod_cnt)) {
        for (size_type i = 0; i < n; ++i) {
          F[i] %= P;
        }
      }
      for (size_type p = 0; p < n; p += m << 1) {
        mint *W = init.omega + m;
        unsigned long long *F0 = F + p, *F1 = F + p + m;
        for (size_type i = 0; i < m; ++i, ++W, ++F0, ++F1) {
          unsigned t = (*F1) * W->val() % P;
          *F1 = *F0 + P - t, *F0 += t;
        }
      }
    }
    for (size_type i = 0; i < n; ++i) {
      f[i] = F[i];
    }
  }

  void IDFT(size_type n) {
    DFT(n);
    std::reverse(f.begin() + 1, f.end());
    mint t = init.inv[n];
    for (size_type i = 0; i < n; ++i) {
      f[i] *= t;
    }
  }

  void mul_in(poly &b, size_type t_n = npos) {
    poly &a = *this;
    if (a.empty() || b.empty() || !t_n) {
      f.clear();
      return;
    }
    t_n = std::min(t_n, a.size() + b.size() - 1);
    if (a.size() <= 32 || b.size() <= 32) {
      std::vector<mint> res(a.size() + b.size() - 1);
      for (size_type i = 0; i < a.size(); ++i) {
        for (size_type j = 0; j < b.size(); ++j) {
          res[i + j] += a.f[i] * b.f[j];
        }
      }
      res.resize(t_n);
      f.swap(res);
      return;
    }
    size_type n = enlarge_to_pow2(t_n);
    a.DFT(n), b.DFT(n);
    for (size_type i = 0; i < n; ++i) {
      a[i] *= b[i];
    }
    a.IDFT(n);
    a.vec().resize(t_n);
  }

  friend poly mul(poly a, poly b, size_type t_n = npos) {
    a.mul_in(b, t_n);
    return a;
  }

  poly &operator+=(const poly &rhs) {
    if (rhs.size() > f.size()) {
      f.resize(rhs.size());
    }
    for (size_type i = 0; i < rhs.size(); ++i) {
      f[i] += rhs[i];
    }
    return *this;
  }

  poly &operator-=(const poly &rhs) {
    if (rhs.size() > f.size()) {
      f.resize(rhs.size());
    }
    for (size_type i = 0; i < rhs.size(); ++i) {
      f[i] -= rhs[i];
    }
    return *this;
  }

  poly &operator*=(const poly &rhs) {
    poly tmp(rhs);
    mul_in(tmp);
    return *this;
  }

  poly &operator*=(const mint &rhs) {
    for (size_type i = 0; i < f.size(); ++i) {
      f[i] *= rhs;
    }
    return *this;
  }

  friend poly operator+(const poly &lhs, const poly &rhs) {
    return poly(lhs) += rhs;
  }

  friend poly operator-(const poly &lhs, const poly &rhs) {
    return poly(lhs) -= rhs;
  }

  friend poly operator*(const poly &lhs, const poly &rhs) {
    return mul(lhs, rhs);
  }

  friend poly operator*(const poly &lhs, const mint &rhs) {
    return poly(lhs) *= rhs;
  }

  poly inv(size_type t_n = npos) const {
    if (t_n == npos) {
      t_n = f.size();
    }
    size_type n = enlarge_to_pow2(t_n);
    poly a(*this), res(1);
    a.resize(n);
    res[0] = a[0].inv();
    for (size_type m = 2; m <= n; m <<= 1) {
      size_type l = m << 1;
      poly tmp(a.f.begin(), a.f.begin() + m);
      tmp.DFT(l);
      res.DFT(l);
      for (size_type i = 0; i < l; ++i) {
        res[i] += res[i] - tmp[i] * res[i] * res[i];
      }
      res.IDFT(l);
      res.resize(m);
    }
    res.resize(t_n);
    return res;
  }

  static void exp_solve(poly &g, const poly &f, size_type l, size_type r) {
    if (r - l <= 64) {
      for (size_type i = l == 0 ? 1 : l; i < r; ++i) {
        for (size_type j = l; j < i; ++j) {
          g[i] += g[j] * f[i - j];
        }
        g[i] *= init.inv[i];
      }
      return;
    }
    size_type len = (r - l) / EXP_BLOCKS;
    init.build_rev(len << 1);
    poly ta[EXP_BLOCKS], tb[EXP_BLOCKS];
    for (size_type i = 1; i < EXP_BLOCKS; ++i) {
      ta[i] = poly(f.f.begin() + (i - 1) * len, f.f.begin() + (i + 1) * len);
      ta[i].DFT(len << 1);
    }
    for (size_type i = 0; i < EXP_BLOCKS; ++i) {
      tb[i].resize(len << 1);
    }
    for (size_type i = 0; i < EXP_BLOCKS; ++i) {
      size_type nl = l + i * len, nr = nl + len;
      if (i) {
        tb[i].IDFT(len << 1);
        for (size_type j = nl; j < nr; ++j) {
          g[j] += tb[i][j - nl + len];
        }
      }
      exp_solve(g, f, nl, nr);
      if (i + 1 < EXP_BLOCKS) {
        tb[i] = poly(g.f.begin() + nl, g.f.begin() + nr);
        init.build_rev(len << 1);
        tb[i].DFT(len << 1);
        for (size_type j = i + 1; j < EXP_BLOCKS; ++j) {
          for (size_type k = 0; k < (len << 1); ++k) {
            tb[j][k] += tb[i][k] * ta[j - i][k];
          }
        }
      }
    }
  }

  poly exp(size_type t_n = npos) const {
    if (t_n == npos) {
      t_n = f.size();
    }
    poly f(*this);
    for (size_type i = 0; i < f.size(); ++i) {
      f[i] *= i;
    }
    size_type n = enlarge_to_pow2(t_n);
    f.resize(n);
    poly g(n);
    g[0] = 1;
    exp_solve(g, f, 0, n);
    g.resize(t_n);
    return g;
  }

  std::vector<mint> eval(std::vector<mint> x) {
    std::vector<poly> tree(enlarge_to_pow2(x.size()) << 1);

    auto work = [&](auto &self, size_type u, size_type l, size_type r) -> void {
      if (l + 1 == r) {
        tree[u] = poly(std::vector<mint>{1, -x[l]});
        return;
      }
      size_type mid = (l + r) >> 1;
      self(self, u << 1, l, mid);
      self(self, u << 1 | 1, mid, r);
      size_type len = enlarge_to_pow2(r - l + 1);
      tree[u << 1].DFT(len);
      tree[u << 1 | 1].DFT(len);
      tree[u].resize(len);
      for (size_type i = 0; i < len; ++i) {
        tree[u][i] = tree[u << 1][i] * tree[u << 1 | 1][i];
      }
      tree[u].IDFT(len);
    };

    auto mulT = [&](poly a, const poly &b, size_type n) {
      size_type len = a.size();
      for (size_type i = 0; i < len; ++i) {
        a[i] *= b[i];
      }
      a.DFT(len);
      a.resize(n);
      return a;
    };

    std::vector<mint> res(x.size());

    auto solve = [&](auto &self, poly f, size_type u, size_type l,
                     size_type r) -> void {
      if (l + 1 == r) {
        res[l] = f[0];
        return;
      }
      size_type mid = (l + r) >> 1;
      size_type len = enlarge_to_pow2(r - l + 1);
      f.IDFT(len);
      self(self, mulT(f, tree[u << 1 | 1], mid - l), u << 1, l, mid);
      self(self, mulT(f, tree[u << 1], r - mid), u << 1 | 1, mid, r);
    };

    poly f(*this);
    work(work, 1, 0, x.size());
    tree[1] = tree[1].inv(f.size());
    size_type len = enlarge_to_pow2(f.size() + x.size());
    tree[1].DFT(len);
    f.IDFT(len);
    solve(solve, mulT(f, tree[1], x.size()), 1, 0, x.size());
    return res;
  }
};

template<unsigned P, unsigned L>
typename modpoly<P, L>::initializer modpoly<P, L>::init;

using poly = modpoly<mod, 20>;
using mint = modint<mod>;

pair<mint,poly>solve(int n,int m) {
	if (m==0) {
		poly F(n+1); F[0]=1;
		return make_pair(mint(0),F);
	}
	auto [res,F]=solve(n,m/2);
	poly A(n+1),B(n+1);
	for (int i=0;i<=n;i++) {
		(i%2?A:B)[i]=F[i];
	}
	A[1]=m-m/2;
	auto T=(poly({1})-A).inv();
	res=(n%2==0?res*2:0)+T[n];
	for (int i=2;i<=n;i++) {
		res+=T[n-i]*A[i]*(i-1);
	}
	F=A+B*B*T;
	F.resize(n+1);
	return make_pair(res,F);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	auto [ans,F]=solve(n,m);
	cout<<ans<<"\n";
	
	return 0;
}