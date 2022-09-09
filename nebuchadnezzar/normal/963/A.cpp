#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

template<int prime, int phi>
struct mod_int {
  static int const modulo = prime;
  static int const phi_modulo = phi;

  mod_int(int value)
    : value(value)
    , inv_(-1)
  {
    assert(value >= 0 && value < prime);
  }

  mod_int(long long value)
    : value((value % prime + prime) % prime)
    , inv_(-1)
  {}

  mod_int()
    : value(0)
    , inv_(-1)
  {}

  mod_int<prime, phi> &operator+=(mod_int<prime, phi> const &a) {
    value += a.value;
    if (value >= prime) {
      value -= prime;
    }
    inv_ = -1;
    return *this;
  }

  mod_int<prime, phi> &operator-=(mod_int<prime, phi> const &a) {
    value -= a.value;
    if (value < 0) {
      value += prime;
    }
    inv_ = -1;
    return *this;
  }

  mod_int<prime, phi> &operator*=(mod_int<prime, phi> const &a) {
    value = (long long) value * a.value % prime;
    if (inv_ != -1 && a.inv_ != -1) {
      inv_ = (long long) inv_ * a.inv_ % prime;
    } else {
      inv_ = -1;
    }
    return *this;
  }

  mod_int<prime, phi> &operator/=(mod_int<prime, phi> a) {
    assert(a.value != 0);
    value = (long long) value * a.inv().value % prime;
    if (inv_ != -1) {
      inv_ = (long long) inv_ * a.value % prime;
    }
    return *this;
  }

  mod_int<prime, phi> inv() const {
    if (inv_ == -1 && value != 0) {
      inv_ = pow(phi - 1).value;
    }
    return inv_;
  }

  mod_int<prime, phi> pow(long long ind) const {
    int res = 1;
    int a = value;
    for (; ind > 0; ind >>= 1) {
      if (ind & 1) {
        res = (long long) res * a % prime;
      }
      a = (long long) a * a % prime;
    }
    return mod_int<prime, phi>(res);
  }

  explicit operator int() const {
    return value;
  }

  int value;
  mutable int inv_;
};

template<int p, int q> mod_int<p, q> operator+(mod_int<p, q> a, mod_int<p, q> const &b) { return a += b; }
template<int p, int q> mod_int<p, q> operator-(mod_int<p, q> a, mod_int<p, q> const &b) { return a -= b; }
template<int p, int q> mod_int<p, q> operator*(mod_int<p, q> a, mod_int<p, q> const &b) { return a *= b; }
template<int p, int q> mod_int<p, q> operator/(mod_int<p, q> a, mod_int<p, q> const &b) { return a /= b; }
template<int p, int q> bool operator==(mod_int<p, q> const &a, mod_int<p, q> const &b) { return a.value == b.value; };
template<int p, int q> bool operator!=(mod_int<p, q> const &a, mod_int<p, q> const &b) { return a.value != b.value; };
template<int p, int q> ostream &operator<<(ostream &os, mod_int<p, q> const &m) { return os << m.value; }
template<int p, int q> istream &operator>>(istream &is, mod_int<p, q> &m) { m.inv_ = -1; return is >> m.value; }

const int MOD = 1000000009;
typedef mod_int<1000000009, 1000000009 - 1> mint;


void solve() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string s;
	cin >> s;
	mint p = 0;
	mint pa = mint(a).pow(n);
	mint pb = 1;
	for (int i = 0; i < k; ++i) {
		int cur = 1;
		if (s[i] == '-') {
			cur = -1;
		}
		p += mint((cur + MOD) % MOD) * pa * pb;
		pa /= a;
		pb *= b;
	}

	mint q = mint(a).pow(k).inv() * mint(b).pow(k);
	int num = (n + 1) / k;
	if (int(q) == 1) {
		cout << int(p * mint(num)) << "\n";
	} else {
		mint ans = p * (mint(1) - q.pow(num)) * (mint(1) - q).inv();
		cout << int(ans) << "\n";
	}
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}