#include <bits/stdc++.h>

using namespace std;

const int N = 2.1e6 + 50;

// Polynomial <mod, g> Template

const int mod = 998244353;
const int g = 3;

int len, omega[N], omegaInv[N];

template <int mod = ::mod> inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
template <int mod = ::mod> inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
template <int mod = ::mod> inline int mul(int x, int y) { return 1ll * x * y % mod; }

template <int mod = ::mod> inline void pud(int &x, int y) { x = mul<mod>(x, y); }

template <int mod = ::mod>
inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud<mod>(r, x);
		pud<mod>(x, x);
		p >>= 1;
	}
	return r;
}
template <int mod, int g>
struct Poly {
	std::vector<int> v;
	Poly() {}
	Poly(std::vector<int> v) : v(v) {}
	Poly(std::initializer_list<int> v) : v(v) {}
	inline int deg() const { return (int)(v.size()) - 1; }
	inline void redeg(int k) { v.resize(k - 1); }
	inline Poly slice(int k) const {
		if (k < v.size())
			return std::vector<int>(v.begin(), v.begin() + k + 1);
		std::vector<int> a(v);
		a.resize(k + 1);
		return a;
	}
	inline Poly clone() const { return v; }
	inline int& operator[](int k) {
		if (v.size() <= k) v.resize(k + 1);
		return v[k];
	}
	inline int operator[](int k) const {
		return v.size() > k ? v[k] : 0;
	}
	inline int* base() {
		return v.begin().base();
	}
	inline const int* base() const {
		return v.begin().base();
	}
};

template <int mod, int g>
void DFTInit(int n) {
	len = 1;
	while (len <= n) len <<= 1;
	omega[0] = omegaInv[0] = 1;
	const int t = fastpow<mod>(g, (mod - 1) / len);
	for (int i = 1; i < len; ++i)
		omega[i] = omegaInv[len - i] = mul<mod>(t, omega[i - 1]);
	
}

template <int mod>
void DFT(int *A) {
	for (int h = len >> 1; h; h >>= 1)
		for (int t = len / (h << 1), j = 0; j < len; j += (h << 1)) {
			const int *w = omega;
			for (int i = j; i < j + h; ++i) {
				int x = A[i], y = A[i + h];
				A[i] = inc<mod>(x, y);
				A[i + h] = mul<mod>(x - y + mod, *w);
				w += t;
			}
		}
}

template <int mod>
void IDFT(int *A) {
	for (int h = 1; h < len; h <<= 1)
		for (int t = len / (h << 1), j = 0; j < len; j += (h << 1)) {
			const int *w = omegaInv;
			for (int i = j; i < j + h; ++i) {
				int x = A[i], y = mul<mod>(A[i + h], *w);
				A[i] = inc<mod>(x, y);
				A[i + h] = dec<mod>(x, y);
				w += t;
			}
		}
	const int t = mod - (mod - 1) / len;
	for (int i = 0; i < len; ++i)
		pud<mod>(A[i], t);
}

template <int mod, int g>
Poly<mod, g> operator*(const Poly<mod, g> &A, const Poly<mod, g> &B) {
	DFTInit<mod, g>(A.deg() + B.deg());
	int t = A.deg() + B.deg();
	std::vector<int> a(len), b(len);
	memcpy(a.begin().base(), A.base(), A.v.size() * sizeof(int));
	memcpy(b.begin().base(), B.base(), B.v.size() * sizeof(int));
	DFT<mod>(a.begin().base()); DFT<mod>(b.begin().base());
	for (int i = 0; i < len; ++i)
		pud<mod>(a[i], b[i]);
	IDFT<mod>(a.begin().base());
	a.resize(t + 1);
	return a;
}

typedef long long ll;
int n, m;
ll a[N], _a[N], b[N], _b[N];
bool gg[N];

template <int mod, int g> 
void solve_matching(int n, ll *a, int m, ll *b) {
	// for (int i = 0; i < n; ++i)
	// 	printf("a[%d] = %lld\n", i, a[i]);
	// for (int i = 0; i < m; ++i)
	//	printf("b[%d] = %lld\n", i, b[i]);
	Poly<mod, g> F, G;
	for (int i = 0; i < m; ++i) {
		assert(0 <= b[i] && b[i] < mod);
	}
	for (int i = 0; i < n; ++i) {
		F[i] = a[i];
	//	printf("F[%d]=%d\n",i,F[i]);
	}
	for (int i = 0; i < m; ++i) {
		G[i] = b[m - i - 1];
	//	printf("G[%d]=%d\n",i,G[i]);
	}
	auto H = F * G;
	// for(int i=0;i<=H.deg();++i)printf("H[%d]=%d\n",i,H[i]);
	ll xx = 0, yy = 0;
	for (int i = 0; i < m; ++i) {
		xx += b[i] * b[i] - b[i];
		yy += a[i] * a[i] + a[i];
	}
	for (int i = 0; i + m - 1 < n; ++i) {
		if ((xx + yy - 2 * H[i + m - 1]) % mod != 0)
			gg[i] = true;
		yy -= a[i] * a[i] + a[i];
		if (i + m < n)
			yy += a[i + m] * a[i + m] + a[i + m];
	}
};

void solve_s3() {
	solve_matching<998244353, 3>(n - 2, a, m - 2, b);
	solve_matching<1004535809, 3>(n - 2, a, m - 2, b);
}

ll calc(ll l, ll r) {
	if (l > r) return 0;
	return (l + r) * (r - l + 1) / 2;
}

void gogo(ll p, ll d) {
	std::vector<int> ans(n);
	ll x = _a[p] - _b[0];
	auto set = [&](int x) {
		ans[x] ^= 1;
	};
	for (int i = 0; i <= p + 1; ++i)
		if ((p - i + 1) % 2 == 1) {
			x += p - i + 1;
			set(i);
		}
	for (int i = 0; i <= p + 1; ++i)
		if (d != 0 && x >= p - i + 1 + calc(0, d - 2)) {
			x -= p - i + 1;
			--d;
			set(i);
		}
	for (int i = 0; i < m - 2; ++i)
		if (a[p + i] != b[i])
			set(p + i + 2);
	int siz = 0;
	for (int i = 0; i < n; ++i) if (ans[i]) ++siz;
	cout << siz << '\n';
	for (int i = 0; i < n; ++i) if (ans[i]) cout << i + 1 << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; ++i)
			gg[i] = false;
		for (int i = 0; i < n; ++i) {
			std::cin >> _a[i];
			a[i] = _a[i];
		}
		std::cin >> m;
		for (int i = 0; i < m; ++i) {
			std::cin >> _b[i];
			b[i] = _b[i];
		}
		// 1 2 3 4 5 6 7 8
		// delta^2 = 1 0 0 0 0 0 0
		// 1 -2 3 -4 5 -6 7 -8
		// 
		/*for (int _ = 0; _ < 2; ++_) {
			for (int i = 0; i < n; ++i)
				a[i] -= a[i + 1];
		}*/
		for (int _ = 0; _ < 2; ++_) {
			for (int i = 0; i < n - _ - 1; ++i)
				a[i] += a[i + 1];
			for (int i = 0; i < m - _ - 1; ++i)
				b[i] += b[i + 1];
		}
		vector<int> buc;
		for (int i = 0; i < n - 2; ++i) {
			buc.push_back(a[i]);
			buc.push_back(a[i] + 1);
		}
		sort(buc.begin(), buc.end());
		buc.erase(unique(buc.begin(), buc.end()), buc.end());
	
		for (int i = 0; i < n - 2; ++i) {
			a[i] = lower_bound(buc.begin(), buc.end(), a[i]) - buc.begin() + 1;
		}
		for (int i = 0; i < m - 2; ++i) {
			auto it = lower_bound(buc.begin(), buc.end(), b[i]);
			if (*it != b[i]) {
				b[i] = 0;
			}
			else {
				b[i] = it - buc.begin() + 1;
			}
		}
		auto work = [&](ll i) {
			ll w = (i + 2) / 2;
			ll x = _a[i] + w * w;
			ll y = _a[i + 1] - w * (w + 1);
			ll d = (_b[0] + _b[1]) - (x + y);
			//printf("status: %lld %lld\n", _a[i], _a[i + 1]);
			//printf("work i = %d, x = %lld, y = %lld, d = %lld\n", i, x, y, d);
			if (0 <= d && d <= i + 2) {
				ll z1 = calc(i + 1 - d + 1, i + 1);
				ll z2 = calc(0, d - 1);
				if (x - z1 <= _b[0] && _b[0] <= x - z2) {
					gogo(i, d);
					return true;
				}
			}
			return false;
		};
		bool okk = false;
		if (m == 2) {
			for (int i = 0; i + 1 < n; ++i) {
				if (work(i)) {
					okk = true;
					break;
				}
			}
		}
		else {
			solve_s3();
			//for (int i = 0; i + m - 1 < n; ++i)
			//	printf("gg[%d] = %d\n", i, gg[i]);
			for (int i = 0; i + m - 1 < n; ++i)
				if (!gg[i] && work(i)) {
					okk = true;
					break;
				}
		}
		if (!okk) {
			cout << "-1" << '\n';
			continue;
		}
	}
}