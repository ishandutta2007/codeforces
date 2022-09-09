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

//#define USE_ASM_MULTIPLICATION

template<int prime, int phi>
struct mod_int {
	static int const modulo = prime;
	static int const phi_modulo = phi;

	unsigned int by_modulo(unsigned long long num) const {
		#ifdef USE_ASM_MULTIPLICATION
			unsigned long long x = num;
			unsigned int xh = x >> 32, xl = x, q, r;
			#ifdef __GNUC__
				asm(
					"divl %4; \n\t"
					: "=a" (q), "=d" (r)
					: "d" (xh), "a" (xl), "r" (modulo)
				);
			#else
				__asm {
					mov edx, dword ptr[xh];
					mov eax, dword ptr[xl];
					div dword ptr[mod];
					mov dword ptr[q], eax;
					mov dword ptr[r], edx;
				};
			#endif
			return r;
		#else
			return num % modulo;
		#endif
	}


	mod_int(int _value) : value(_value), inv_(-1) {
		if (value < 0 || value >= modulo) {
			value %= modulo;
			if (value < 0) {
				value += modulo;
			}
		}
	}

	mod_int(long long _value) : value(_value % prime), inv_(-1) {
		if (value < 0) {
			value += modulo;
		}
	}

	mod_int() : value(0), inv_(-1) {}

	mod_int<prime, phi>& operator+=(mod_int<prime, phi> const& a) {
		value += a.value;
		if (value >= prime) {
			value -= prime;
		}
		inv_ = -1;
		return *this;
	}

	mod_int<prime, phi>& operator-=(mod_int<prime, phi> const& a) {
		value -= a.value;
		if (value < 0) {
			value += prime;
		}
		inv_ = -1;
		return *this;
	}

	mod_int<prime, phi>& operator*=(mod_int<prime, phi> const& a) {
		value = by_modulo((long long) value * a.value);
		if (inv_ != -1 && a.inv_ != -1) {
			inv_ = by_modulo((long long) inv_ * a.inv_);
		} else {
			inv_ = -1;
		}
		return *this;
	}

	mod_int<prime, phi> &operator/=(mod_int<prime, phi> a) {
		assert(a.value != 0);
		value = by_modulo((long long) value * a.inv().value);
		if (inv_ != -1) {
			inv_ = by_modulo((long long) inv_ * a.value);
		}
		return *this;
	}

	mod_int<prime, phi> inv() const {
		assert(value != 0);
		if (inv_ == -1 && value != 0) {
			inv_ = pow(phi - 1).value;
		}
		return inv_;
	}

	mod_int<prime, phi> pow(int p) const {
		int res = 1;
		int a = value;
		while (p) {
			if (p & 1) {
				res = by_modulo((long long) res * a);
			}
			a = by_modulo((long long) a * a);
			p >>= 1;
		}
		return res;
	}

	mod_int<prime, phi> pow(long long p) const {
		if (phi + 1 == prime && p > phi_modulo) {
			p %= phi_modulo;
		}
		int res = 1;
		int a = value;
		while (p) {
			if (p & 1) {
				res = by_modulo((long long) res * a);
			}
			a = by_modulo((long long) a * a);
			p >>= 1;
		}
		return res;
	}

	explicit operator int() const {
		return value;
	}

	int value;
	mutable int inv_;
};

template<int p, int q> mod_int<p, q> operator+(mod_int<p, q> a, auto const& b) { return a += b; }
template<int p, int q> mod_int<p, q> operator-(mod_int<p, q> a, auto const& b) { return a -= b; }
template<int p, int q> mod_int<p, q> operator*(mod_int<p, q> a, auto const& b) { return a *= b; }
template<int p, int q> mod_int<p, q> operator/(mod_int<p, q> a, auto const& b) { return a /= b; }
template<int p, int q> bool operator==(mod_int<p, q> const& a, auto const& b) { return a.value == b.value; };
template<int p, int q> bool operator!=(mod_int<p, q> const& a, auto const& b) { return a.value != b.value; };
template<int p, int q> ostream &operator<<(ostream &os, mod_int<p, q> const& m) { return os << m.value; }
template<int p, int q> istream &operator>>(istream &is, mod_int<p, q>& m) { 
	long long tmp;
	is >> tmp;
	m = mod_int<p, q>(tmp);
	return is; 
}

const int MOD = 998244353;
typedef mod_int<MOD, MOD - 1> mint;


vector<mint> rsq;
vector<pair<mint, mint>> there;
int bpv;

int push_down(int v, int len) {
	if (there[v].ss != mint(1)) {
		there[v * 2].ss *= there[v].ss;
		there[v * 2].ff *= there[v].ss;
		rsq[v * 2] *= there[v].ss;
		there[v * 2 + 1].ss *= there[v].ss;
		there[v * 2 + 1].ff *= there[v].ss;
		rsq[v * 2 + 1] *= there[v].ss;
		there[v].ss = 1;
	}
	if (there[v].ff != mint(0)) {
		there[v * 2].ff += there[v].ff;
		rsq[v * 2] += there[v].ff * len;
		there[v * 2 + 1].ff += there[v].ff;
		rsq[v * 2 + 1] += there[v].ff * len;
		there[v].ff = 0;
	}
	return 0;
}

int segtree_add(int v, int vl, int vr, int l, int r, int val) {
	if (vr <= l || r <= vl) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		there[v].ff += val;
		rsq[v] += mint(val) * (vr - vl);
		return 0;
	}
	push_down(v, (vr - vl) / 2);
	int vm = (vl + vr) / 2;
	segtree_add(v * 2, vl, vm, l, r, val);
	segtree_add(v * 2 + 1, vm, vr, l, r, val);
	rsq[v] = rsq[v * 2] + rsq[v * 2 + 1];
	return 0;
}

int segtree_mul2(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		there[v].ss *= 2;
		rsq[v] *= 2;
		there[v].ff *= 2;
		return 0;
	}
	push_down(v, (vr - vl) / 2);
	int vm = (vl + vr) / 2;
	segtree_mul2(v * 2, vl, vm, l, r);
	segtree_mul2(v * 2 + 1, vm, vr, l, r);
	rsq[v] = rsq[v * 2] + rsq[v * 2 + 1];
	return 0;
}

mint segtree_get(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return 0;
	}
	if (l <= vl && vr <= r) {
		return rsq[v];
	}
	push_down(v, (vr - vl) / 2);
	int vm = (vl + vr) / 2;
	return segtree_get(v * 2, vl, vm, l, r) + segtree_get(v * 2 + 1, vm, vr, l, r);
}

void solve() {
	int n, q;
	cin >> n >> q;
	map<int, set<pii>> have;
	bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	rsq.resize(bpv * 2);
	there.resize(bpv * 2, {0, 1});
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			auto& cur = have[x];
			--l;
			int lg = l, rg = r;
			while (true) {
				auto it = cur.lower_bound({r, -1});
				if (it != cur.end() && it->ff == r) {
					rg = it->ss;
					cur.erase(it);
					continue;
				}

				if (it == cur.begin()) {
					break;
				}

				--it;
				if (it->ss <= l) {
					if (it->ss == l) {
						lg = it->ff;
						cur.erase(it);
					}
					break;
				}

				if (it->ss > r) {
					rg = it->ss;
				}

				if (it->ff < l) {
					lg = it->ff;
				}

				//cerr << it->ff << " " << it->ss << endl;
				segtree_mul2(1, 0, bpv, max(l, it->ff), min(r, it->ss));
				segtree_add(1, 0, bpv, max(l, it->ff), min(r, it->ss), -1);

				cur.erase(it);
			}
			segtree_add(1, 0, bpv, l, r, 1);
			cur.insert({lg, rg});
		} else {
			int l, r;
			cin >> l >> r;
			--l;
			cout << segtree_get(1, 0, bpv, l, r) << "\n";
		}
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