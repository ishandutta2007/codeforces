#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000007)

int inv(int v) {
	return v <= 1 ? v : MOD - (long long)inv(MOD % v) * (MOD / v) % MOD;
}

struct mint {
	int v;
	mint() = default;
	mint(long long v) : v((v% MOD + MOD) % MOD) {}

	mint& operator+=(mint a) {
		v = (v + a.v) % MOD;
		return *this;
	}

	mint& operator-=(mint a) {
		v = (v - a.v + MOD) % MOD;
		return *this;
	}

	mint& operator*=(mint a) {
		v = ((long long)v * a.v) % MOD;
		return *this;
	}

	mint& operator/=(mint a) {
		v = ((long long)v * inv(a.v)) % MOD;
		return *this;
	}

	friend mint operator+(mint a, mint b) {
		return mint(a.v + b.v);
	}

	friend mint operator-(mint a, mint b) {
		return mint(a.v - b.v);
	}

	friend mint operator*(mint a, mint b) {
		return mint((long long)a.v * b.v);
	}

	friend mint operator/(mint a, mint b) {
		return mint((long long)a.v * inv(b.v));
	}
};

mint pow(mint base, long long exponent) {
	if (exponent <= 0) {
		return 1;
	}
	mint ret = 1;
	while (exponent) {
		if (exponent & 1) {
			ret *= base;
		}
		exponent >>= 1;
		base = base * base;
	}
	return ret;
}


int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		vector<int> w(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		vector<vector<mint>> a(n, vector<mint>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j]= mint(w[i]) / mint(w[i] + w[j]);
			}
		}
		vector<vector<mint>> g(1 << n, vector<mint>(n));
		for (int mask = 0; mask < (1 << n); ++mask) {
			for (int i = 0; i < n; ++i) {
				g[mask][i] = 1;
				for (int j = 0; j < n; ++j) {
					if (mask & (1 << j)) {
						g[mask][i] *= a[i][j];
					}
				}
			}
		}
		vector<mint> f(1 << n);
		for (int mask = 1; mask < (1 << n); ++mask) {
			f[mask] = 1;
			for (int sub_mask = mask; sub_mask > 0; sub_mask = ((sub_mask - 1) & mask)) {
				if (sub_mask < mask) {
					mint val = f[sub_mask];
					int other_mask = mask - sub_mask;
					for (int i = 0; i < n; ++i) {
						if (sub_mask & (1 << i)) {
							val *= g[other_mask][i];
						}
					}
					f[mask] -= val;
				}
			}
		}
		mint result = 0;
		for (int mask = 1; mask < (1 << n); ++mask) {
			int count = 0;
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					++count;
				}
			}
			mint val = f[mask] * mint(count);
			int other_mask = (1 << n) - 1 - mask;
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					val *= g[other_mask][i];
				}
			}
			result += val;
		}
		printf("%d\n", result.v);
	}
	return 0;
}