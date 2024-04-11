#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;
	static_mint(): val() {}
	static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
	static_mint pow(long long n) const { static_mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
	static_mint inv() const { return pow(M - 2); }

	friend static_mint pow(const static_mint &m, long long n) { return m.pow(n); }
	friend static_mint inv(const static_mint &m) { return m.inv(); }

	static_mint operator+() const { static_mint m; m.val = val; return m; }
	static_mint operator-() const { static_mint m; m.val = M - val; return m; }
	static_mint &operator+=(const static_mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
	static_mint &operator-=(const static_mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
	static_mint &operator*=(const static_mint &m) { val = (long long) val * m.val % M; return *this; }
	static_mint &operator/=(const static_mint &m) { val = (long long) val * m.inv().val % M; return *this; }

	friend static_mint operator+ (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) += rhs; }
	friend static_mint operator- (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) -= rhs; }
	friend static_mint operator* (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) *= rhs; }
	friend static_mint operator/ (const static_mint &lhs, const static_mint &rhs) { return static_mint(lhs) /= rhs; }
	friend bool operator==(const static_mint &lhs, const static_mint &rhs) { return lhs.val == rhs.val; }
	friend bool operator!=(const static_mint &lhs, const static_mint &rhs) { return lhs.val != rhs.val; }

	static_mint &operator++() { return *this += 1; }
	static_mint &operator--() { return *this -= 1; }
	static_mint operator++(int) { static_mint result(*this); *this += 1; return result; }
	static_mint operator--(int) { static_mint result(*this); *this -= 1; return result; }

	template <typename T> explicit operator T() const { return T(val); }

	friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, static_mint &m) {
		long long x; is >> x; m = x;
		return is;
	}
};

namespace fwht {
	template <typename T>
	void fwht_xor(std::vector<T> &a) {
		int n = (int) a.size();
		for (int l = 1; l < n; l <<= 1) {
			for (int i = 0; i < n; i += 2 * l) {
				for (int j = 0; j < l; j++) {
					T v = a[i + j + l];
					a[i + j + l] = a[i + j] - v;
					a[i + j] = a[i + j] + v;
				}
			}
		}
	}

	template <typename T>
	std::vector<T> xor_convolution(std::vector<T> a, std::vector<T> b) {
		int n = 1;
		while (n < (int) a.size() && n < (int) b.size()) {
			n <<= 1;
		}
		a.resize(n), b.resize(n);
		fwht_xor(a), fwht_xor(b);
		T inv_n = 1 / T(n);
		for (int i = 0; i < n; i++) {
			a[i] *= b[i] * inv_n;
		}
		fwht_xor(a);
		return a;
	}

	template <typename T>
	void fwht_and(std::vector<T> &a, bool invert = false) {
		int n = (int) a.size();
		for (int l = 1; l < n; l <<= 1) {
			for (int i = 0; i < n; i += 2 * l) {
				for (int j = 0; j < l; j++) {
					if (invert) {
						a[i + j] -= a[i + j + l];
					} else {
						a[i + j] += a[i + j + l];
					}
				}
			}
		}
	}

	template <typename T>
	std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {
		int n = 1;
		while (n < (int) a.size() && n < (int) b.size()) {
			n <<= 1;
		}
		a.resize(n), b.resize(n);
		fwht_and(a), fwht_and(b);
		for (int i = 0; i < n; i++) {
			a[i] *= b[i];
		}
		fwht_and(a, true);
		return a;
	}

	template <typename T>
	std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {
		int n = 1;
		while (n < (int) a.size() && n < (int) b.size()) {
			n <<= 1;
		}
		a.resize(n), b.resize(n);
		for (int i = 0; i < n; i++) {
			int j = ~i & (n - 1);
			if (i < j) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
			}
		}
		fwht_and(a), fwht_and(b);
		for (int i = 0; i < n; i++) {
			a[i] *= b[i];
		}
		fwht_and(a, true);
		for (int i = 0; i < n; i++) {
			int j = ~i & (n - 1);
			if (i < j) {
				swap(a[i], a[j]);
			}
		}
		return a;
	}
}

template <typename T>
std::vector<T> subset_convolution(int n, const std::vector<T> &f, const std::vector<T> &g) {
    std::vector<std::vector<T>> f_hat(n + 1, std::vector<T>(1 << n));
    std::vector<std::vector<T>> g_hat(n + 1, std::vector<T>(1 << n));
    for (int mask = 0; mask < (1 << n); mask++) {
        f_hat[__builtin_popcount(mask)][mask] = f[mask];
        g_hat[__builtin_popcount(mask)][mask] = g[mask];
    }
    for (int k = 0; k <= n; k++) {
        for (int j = 0; j < n; j++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                if (mask >> j & 1) {
                    f_hat[k][mask] += f_hat[k][mask ^ (1 << j)];
                    g_hat[k][mask] += g_hat[k][mask ^ (1 << j)];
                }
            }
        }
    }
    std::vector<std::vector<T>> h(n + 1, std::vector<T>(1 << n));
    for (int k = 0; k <= n; k++) {
        for (int j = 0; j <= k; j++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                h[k][mask] += f_hat[j][mask] * g_hat[k - j][mask];
            }
        }
    }
    for (int k = 0; k <= n; k++) {
        for (int j = 0; j < n; j++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                if (mask >> j & 1) {
                    h[k][mask] -= h[k][mask ^ (1 << j)];
                }
            }
        }
    }
    std::vector<T> result(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        result[mask] = h[__builtin_popcount(mask)][mask];
    }
    return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<1000000007>;
	using fwht::xor_convolution;
	using fwht::and_convolution;

	constexpr int n = 17;

	vector<mint> fib(1 << n); fib[0] = 0, fib[1] = 1;
	for (int i = 2; i < (1 << n); i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	int m;
	cin >> m;

	vector<mint> freq(1 << n);
	for (int i = 0, x; i < m; i++) {
		cin >> x, freq[x] += 1;
	}

	auto a = subset_convolution(n, freq, freq), b = xor_convolution(freq, freq);
	for (int i = 0; i < (1 << n); i++) {
		a[i] *= fib[i];
		b[i] *= fib[i];
		freq[i] *= fib[i];
	}

	a = and_convolution(a, freq);
	a = and_convolution(a, b);

	mint ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[1 << i];
	}
	cout << ans << '\n';
	return 0;
}