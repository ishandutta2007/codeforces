


 #include <stdio.h>
 #include <bits/stdc++.h>






using namespace std;




template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}







using li = long long int;
using lu = long long unsigned;
using ld = long double;


using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

struct empty_t {};



namespace tuple_access {

  struct xx_t {} xx;
  struct yy_t {} yy;
  struct zz_t {} zz;
  struct ww_t {} ww;

  template<class T>
  typename tuple_element<0,T>::type& operator^(T& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type const& operator^(T const& v, xx_t) { return get<0>(v); }
  template<class T>
  typename tuple_element<0,T>::type&& operator^(T&& v, xx_t) { return get<0>(v); }

  template<class T>
  typename tuple_element<1,T>::type& operator^(T& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type const& operator^(T const& v, yy_t) { return get<1>(v); }
  template<class T>
  typename tuple_element<1,T>::type&& operator^(T&& v, yy_t) { return get<1>(v); }

  template<class T>
  typename tuple_element<2,T>::type& operator^(T& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type const& operator^(T const& v, zz_t) { return get<2>(v); }
  template<class T>
  typename tuple_element<2,T>::type&& operator^(T&& v, zz_t) { return get<2>(v); }

  template<class T>
  typename tuple_element<3,T>::type& operator^(T& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type const& operator^(T const& v, ww_t) { return get<3>(v); }
  template<class T>
  typename tuple_element<3,T>::type&& operator^(T&& v, ww_t) { return get<3>(v); }
}
using namespace tuple_access;


int ilog2(int x){ return 31 - __builtin_clz(x); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); return x; }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); return x; }


template<typename T>
T isqrt(T const&x){
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(sqrtl(x));
  while(ret>0 && ret*ret>x) --ret;
  while(x-ret*ret>2*ret) ++ret;
  return ret;
}

template<typename T>
T icbrt(T const&x) {
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(cbrt(x));
  while(ret>0 && ret*ret*ret>x) --ret;
  while(x-ret*ret*ret>3*ret*(ret+1)) ++ret;
  return ret;
}






const int BIGINT_BASE_DIGITS = 9;
const int BIGINT_BASE = 1000000000;

struct Z {
  int sign;
  vector<int> a;



  Z() : sign(1) {}


  Z(long long v) {
    *this = v;
  }
  Z& operator = (long long v) {
    sign = 1;
    if (v < 0) {
      sign = -1;
      v = -v;
    }
    a.clear();
    for (; v > 0; v = v / BIGINT_BASE)
      a.push_back(v % BIGINT_BASE);
    return *this;
  }


  Z(const string& s) {
    read(s);
  }


  void read(const string& s) {
    sign = 1;
    a.clear();
    int pos = 0;
    while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
      if (s[pos] == '-')
        sign = -sign;
      ++pos;
    }
    for (int i = s.size() - 1; i >= pos; i -= BIGINT_BASE_DIGITS) {
      int x = 0;
      for (int j = max(pos, i - BIGINT_BASE_DIGITS + 1); j <= i; j++)
        x = x * 10 + s[j] - '0';
      a.push_back(x);
    }
    trim();
  }
  friend istream& operator>>(istream &stream, Z &v) {
    string s;
    stream >> s;
    v.read(s);
    return stream;
  }

  friend ostream& operator<<(ostream &stream, const Z &v) {
    if (v.sign == -1 && !v.isZero())
      stream << '-';
    stream << (v.a.empty() ? 0 : v.a.back());
    for (int i = (int) v.a.size() - 2; i >= 0; --i)
      stream << setw(BIGINT_BASE_DIGITS) << setfill('0') << v.a[i];
    return stream;
  }


  bool operator<(const Z &v) const {
    if (sign != v.sign)
      return sign < v.sign;
    if (a.size() != v.a.size())
      return a.size() * sign < v.a.size() * v.sign;
    for (int i = ((int) a.size()) - 1; i >= 0; i--)
      if (a[i] != v.a[i])
        return a[i] * sign < v.a[i] * sign;
    return false;
  }

  bool operator>(const Z &v) const {
    return v < *this;
  }
  bool operator<=(const Z &v) const {
    return !(v < *this);
  }
  bool operator>=(const Z &v) const {
    return !(*this < v);
  }
  bool operator==(const Z &v) const {
    return !(*this < v) && !(v < *this);
  }
  bool operator!=(const Z &v) const {
    return *this < v || v < *this;
  }





  friend int __compare_abs(const Z& x, const Z& y) {
    if (x.a.size() != y.a.size()) {
      return x.a.size() < y.a.size() ? -1 : 1;
    }

    for (int i = ((int) x.a.size()) - 1; i >= 0; --i) {
      if (x.a[i] != y.a[i]) {
        return x.a[i] < y.a[i] ? -1 : 1;
      }
    }
    return 0;
  }


  Z operator-() const {
    Z res = *this;
    if (isZero()) return res;

    res.sign = -sign;
    return res;
  }


  void __internal_add(const Z& v) {
    if (a.size() < v.a.size()) {
      a.resize(v.a.size(), 0);
    }
    for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
      if (i == (int) a.size()) a.push_back(0);

      a[i] += carry + (i < (int) v.a.size() ? v.a[i] : 0);
      carry = a[i] >= BIGINT_BASE;
      if (carry) a[i] -= BIGINT_BASE;
    }
  }


  void __internal_sub(const Z& v) {
    for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
      a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
      carry = a[i] < 0;
      if (carry) a[i] += BIGINT_BASE;
    }
    this->trim();
  }

  Z operator += (const Z& v) {
    if (sign == v.sign) {
      __internal_add(v);
    } else {
      if (__compare_abs(*this, v) >= 0) {
        __internal_sub(v);
      } else {
        Z vv = v;
        swap(*this, vv);
        __internal_sub(vv);
      }
    }
    return *this;
  }

  Z operator -= (const Z& v) {
    if (sign == v.sign) {
      if (__compare_abs(*this, v) >= 0) {
        __internal_sub(v);
      } else {
        Z vv = v;
        swap(*this, vv);
        __internal_sub(vv);
        this->sign = -this->sign;
      }
    } else {
      __internal_add(v);
    }
    return *this;
  }



  template< typename L, typename R >
  typename std::enable_if<
    std::is_convertible<L, Z>::value &&
    std::is_convertible<R, Z>::value &&
    std::is_lvalue_reference<R&&>::value,
    Z>::type friend operator + (L&& l, R&& r) {
    Z result(std::forward<L>(l));
    result += r;
    return result;
  }
  template< typename L, typename R >
  typename std::enable_if<
    std::is_convertible<L, Z>::value &&
    std::is_convertible<R, Z>::value &&
    std::is_rvalue_reference<R&&>::value,
    Z>::type friend operator + (L&& l, R&& r) {
    Z result(std::move(r));
    result += l;
    return result;
  }

  template< typename L, typename R >
  typename std::enable_if<
    std::is_convertible<L, Z>::value &&
    std::is_convertible<R, Z>::value,
    Z>::type friend operator - (L&& l, R&& r) {
    Z result(std::forward<L>(l));
    result -= r;
    return result;
  }


  friend pair<Z, Z> divmod(const Z& a1, const Z& b1) {
    assert(b1 > 0);

    long long norm = BIGINT_BASE / (b1.a.back() + 1);
    Z a = a1.abs() * norm;
    Z b = b1.abs() * norm;
    Z q = 0, r = 0;
    q.a.resize(a.a.size());

    for (int i = a.a.size() - 1; i >= 0; i--) {
      r *= BIGINT_BASE;
      r += a.a[i];
      long long s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
      long long s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
      long long d = ((long long) BIGINT_BASE * s1 + s2) / b.a.back();
      r -= b * d;
      while (r < 0) {
        r += b, --d;
      }
      q.a[i] = d;
    }

    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;
    q.trim();
    r.trim();
    auto res = make_pair(q, r / norm);
    if (res.second < 0) res.second += b1;
    return res;
  }
  Z operator/(const Z &v) const {
    return divmod(*this, v).first;
  }

  Z operator%(const Z &v) const {
    return divmod(*this, v).second;
  }

  void operator/=(int v) {
    assert(v > 0);
    if (llabs(v) >= BIGINT_BASE) {
      *this /= Z(v);
      return ;
    }
    if (v < 0)
      sign = -sign, v = -v;
    for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
      long long cur = a[i] + rem * (long long) BIGINT_BASE;
      a[i] = (int) (cur / v);
      rem = (int) (cur % v);
    }
    trim();
  }

  Z operator/(int v) const {
    assert(v > 0);

    if (llabs(v) >= BIGINT_BASE) {
      return *this / Z(v);
    }
    Z res = *this;
    res /= v;
    return res;
  }
  void operator/=(const Z &v) {
    *this = *this / v;
  }

  long long operator%(long long v) const {
    assert(v > 0);
    assert(v < BIGINT_BASE);
    int m = 0;
    for (int i = a.size() - 1; i >= 0; --i)
      m = (a[i] + m * (long long) BIGINT_BASE) % v;
    return m * sign;
  }

  void operator*=(int v) {
    if (llabs(v) >= BIGINT_BASE) {
      *this *= Z(v);
      return ;
    }
    if (v < 0)
      sign = -sign, v = -v;
    for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
      if (i == (int) a.size())
        a.push_back(0);
      long long cur = a[i] * (long long) v + carry;
      carry = (int) (cur / BIGINT_BASE);
      a[i] = (int) (cur % BIGINT_BASE);
    }
    trim();
  }

  Z operator*(int v) const {
    if (llabs(v) >= BIGINT_BASE) {
      return *this * Z(v);
    }
    Z res = *this;
    res *= v;
    return res;
  }


  static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
    vector<long long> p(max(old_digits, new_digits) + 1);
    p[0] = 1;
    for (int i = 1; i < (int) p.size(); i++)
      p[i] = p[i - 1] * 10;
    vector<int> res;
    long long cur = 0;
    int cur_digits = 0;
    for (int i = 0; i < (int) a.size(); i++) {
      cur += a[i] * p[cur_digits];
      cur_digits += old_digits;
      while (cur_digits >= new_digits) {
        res.push_back((long long)(cur % p[new_digits]));
        cur /= p[new_digits];
        cur_digits -= new_digits;
      }
    }
    res.push_back((int) cur);
    while (!res.empty() && !res.back())
      res.pop_back();
    return res;
  }

  void fft(vector<complex<double> > & a, bool invert) const {
    int n = (int) a.size();

    for (int i = 1, j = 0; i < n; ++i) {
      int bit = n >> 1;
      for (; j >= bit; bit >>= 1)
        j -= bit;
      j += bit;
      if (i < j)
        swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
      double ang = 2 * 3.14159265358979323846 / len * (invert ? -1 : 1);
      complex<double> wlen(cos(ang), sin(ang));
      for (int i = 0; i < n; i += len) {
        complex<double> w(1);
        for (int j = 0; j < len / 2; ++j) {
          complex<double> u = a[i + j];
          complex<double> v = a[i + j + len / 2] * w;
          a[i + j] = u + v;
          a[i + j + len / 2] = u - v;
          w *= wlen;
        }
      }
    }
    if (invert)
      for (int i = 0; i < n; ++i)
        a[i] /= n;
  }

  void multiply_fft(const vector<int> &a, const vector<int> &b, vector<int> &res) const {
    vector<complex<double> > fa(a.begin(), a.end());
    vector<complex<double> > fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) max(a.size(), b.size()))
      n <<= 1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i)
      fa[i] *= fb[i];
    fft(fa, true);

    res.resize(n);
    long long carry = 0;
    for (int i = 0; i < n; ++i) {
      long long t = (long long) (fa[i].real() + 0.5) + carry;
      carry = t / 1000;
      res[i] = t % 1000;
    }
  }

  Z mul_simple(const Z &v) const {
    Z res;
    res.sign = sign * v.sign;
    res.a.resize(a.size() + v.a.size());
    for (int i = 0; i < (int) a.size(); ++i)
      if (a[i])
        for (int j = 0, carry = 0; j < (int) v.a.size() || carry; ++j) {
          long long cur = res.a[i + j] + (long long) a[i] * (j < (int) v.a.size() ? v.a[j] : 0) + carry;
          carry = (int) (cur / BIGINT_BASE);
          res.a[i + j] = (int) (cur % BIGINT_BASE);
        }
    res.trim();
    return res;
  }

  typedef vector<long long> vll;

  static vll karatsubaMultiply(const vll &a, const vll &b) {
    int n = a.size();
    vll res(n + n);
    if (n <= 32) {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          res[i + j] += a[i] * b[j];
      return res;
    }

    int k = n >> 1;
    vll a1(a.begin(), a.begin() + k);
    vll a2(a.begin() + k, a.end());
    vll b1(b.begin(), b.begin() + k);
    vll b2(b.begin() + k, b.end());

    vll a1b1 = karatsubaMultiply(a1, b1);
    vll a2b2 = karatsubaMultiply(a2, b2);

    for (int i = 0; i < k; i++)
      a2[i] += a1[i];
    for (int i = 0; i < k; i++)
      b2[i] += b1[i];

    vll r = karatsubaMultiply(a2, b2);
    for (int i = 0; i < (int) a1b1.size(); i++)
      r[i] -= a1b1[i];
    for (int i = 0; i < (int) a2b2.size(); i++)
      r[i] -= a2b2[i];

    for (int i = 0; i < (int) r.size(); i++)
      res[i + k] += r[i];
    for (int i = 0; i < (int) a1b1.size(); i++)
      res[i] += a1b1[i];
    for (int i = 0; i < (int) a2b2.size(); i++)
      res[i + n] += a2b2[i];
    return res;
  }

  Z mul_karatsuba(const Z &v) const {
    vector<int> a6 = convert_base(this->a, BIGINT_BASE_DIGITS, 6);
    vector<int> b6 = convert_base(v.a, BIGINT_BASE_DIGITS, 6);
    vll a(a6.begin(), a6.end());
    vll b(b6.begin(), b6.end());
    while (a.size() < b.size())
      a.push_back(0);
    while (b.size() < a.size())
      b.push_back(0);
    while (a.size() & (a.size() - 1))
      a.push_back(0), b.push_back(0);
    vll c = karatsubaMultiply(a, b);
    Z res;
    res.sign = sign * v.sign;
    long long carry = 0;
    for (int i = 0; i < (int) c.size(); i++) {
      long long cur = c[i] + carry;
      res.a.push_back((int) (cur % 1000000));
      carry = cur / 1000000;
    }
    res.a = convert_base(res.a, 6, BIGINT_BASE_DIGITS);
    res.trim();
    return res;
  }

  void operator*=(const Z &v) {
    *this = *this * v;
  }
  Z operator*(const Z &v) const {
    if (a.size() * v.a.size() <= 1000111) return mul_simple(v);
    if (a.size() > 500111 || v.a.size() > 500111) return mul_fft(v);
    return mul_karatsuba(v);
  }

  Z mul_fft(const Z& v) const {
    Z res;
    res.sign = sign * v.sign;
    multiply_fft(convert_base(a, BIGINT_BASE_DIGITS, 3), convert_base(v.a, BIGINT_BASE_DIGITS, 3), res.a);
    res.a = convert_base(res.a, 3, BIGINT_BASE_DIGITS);
    res.trim();
    return res;
  }


  Z abs() const {
    Z res = *this;
    res.sign *= res.sign;
    return res;
  }
  void trim() {
    while (!a.empty() && !a.back())
      a.pop_back();
    if (a.empty())
      sign = 1;
  }

  bool isZero() const {
    return a.empty() || (a.size() == 1 && !a[0]);
  }

  friend Z gcd(const Z &a, const Z &b) {
    return b.isZero() ? a : gcd(b, a % b);
  }
  friend Z lcm(const Z &a, const Z &b) {
    return a / gcd(a, b) * b;
  }

  friend Z sqrt(const Z &a1) {
    Z a = a1;
    while (a.a.empty() || a.a.size() % 2 == 1)
      a.a.push_back(0);

    int n = a.a.size();

    int firstDigit = (int) sqrt((double) a.a[n - 1] * BIGINT_BASE + a.a[n - 2]);
    int norm = BIGINT_BASE / (firstDigit + 1);
    a *= norm;
    a *= norm;
    while (a.a.empty() || a.a.size() % 2 == 1)
      a.a.push_back(0);

    Z r = (long long) a.a[n - 1] * BIGINT_BASE + a.a[n - 2];
    firstDigit = (int) sqrt((double) a.a[n - 1] * BIGINT_BASE + a.a[n - 2]);
    int q = firstDigit;
    Z res;

    for(int j = n / 2 - 1; j >= 0; j--) {
      for(; ; --q) {
        Z r1 = (r - (res * 2 * Z(BIGINT_BASE) + q) * q) * Z(BIGINT_BASE) * Z(BIGINT_BASE) + (j > 0 ? (long long) a.a[2 * j - 1] * BIGINT_BASE + a.a[2 * j - 2] : 0);
        if (r1 >= 0) {
          r = r1;
          break;
        }
      }
      res *= BIGINT_BASE;
      res += q;

      if (j > 0) {
        int d1 = res.a.size() + 2 < r.a.size() ? r.a[res.a.size() + 2] : 0;
        int d2 = res.a.size() + 1 < r.a.size() ? r.a[res.a.size() + 1] : 0;
        int d3 = res.a.size() < r.a.size() ? r.a[res.a.size()] : 0;
        q = ((long long) d1 * BIGINT_BASE * BIGINT_BASE + (long long) d2 * BIGINT_BASE + d3) / (firstDigit * 2);
      }
    }

    res.trim();
    return res / norm;
  }
};

Z pow(Z a, li b) {
  Z r = 1;
  while(b){
    if(b&1) r = r*a;
    a = a * a;
    b /= 2;
  }
  return r;
}

void solve(li n) {
  n -= 1;
  li m = n/3;
  li m0 = m;
  li p = 1;
  li i = 0;
  while(m-p >= 0) {
    m -= p;
    i += 1;
    p *= 4;
  }
  li x = (1ll<<(2*i)) + m;
  li y = 0;
  li q = 1;
  while(m) {
    if(m%4 == 0) y += 0 * q;
    if(m%4 == 1) y += 2 * q;
    if(m%4 == 2) y += 3 * q;
    if(m%4 == 3) y += 1 * q;
    m /= 4;
    q *= 4;
  }
  if(n == 3*m0) cout << x << '\n';
  if(n == 3*m0+1) cout << (1ll<<(2*i+1))+y << '\n';
  if(n == 3*m0+2) cout << ((x)^((1ll<<(2*i+1))+y)) << '\n';
}

int main(){
  ios::sync_with_stdio(false); cin.tie(0);

  int t; cin>>t;
  for(li i = 0; i < (li)(t); ++i) {
    li n; cin>>n; solve(n);
  }
  cout << flush;
  return 0;
}