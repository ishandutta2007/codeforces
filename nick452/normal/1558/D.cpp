#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int M = (1 << 20);
vector<int> c(M * 4);

void init(int id, int s, int t) {
	c[id] = t - s + 1;
	if (s == t) {
		return;
	}
	int m = (s + t) / 2;
	init(id * 2 + 1, s, m);
	init(id * 2 + 2, m + 1, t);
}

void up(int id, int s, int t, int p, int d) {
	c[id] += d;
	if (s == t) {
		return;
	}
	int m = (s + t) / 2;
	if (p <= m) {
		up(id * 2 + 1, s, m, p, d);
	} else {
		up(id * 2 + 2, m + 1, t, p, d);
	}
}
void up(int p, int d) {
	up(0, 0, M - 1, p, d);
}

int gt(int id, int s, int t, int p) {
	if (s == t) {
		return s;
	}
	int m = (s + t) / 2;
	if (c[id * 2 + 1] > p) {
		return gt(id * 2 + 1, s, m, p);
	} else {
		return gt(id * 2 + 2, m + 1, t, p - c[id * 2 + 1]);
	}
}

int gt(int p) {
	return gt(0, 0, M - 1, p);
}

#define MOD (998244353)

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

mint permutation[M];
mint permutation_inv[M];

mint choose(int n, int m) {
	if (m < 0) {
		return 0;
	}
	if (m > n) {
		return 0;
	}
	return permutation[n] * permutation_inv[m] * permutation_inv[n - m];
}

void init_perm()
{
	permutation[0] = 1;
	permutation_inv[0] = 1;
	for (int n = 1; n < M; ++n) {
		permutation[n] = permutation[n - 1] * n;
		permutation_inv[n] = permutation_inv[n - 1] / n;
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	init_perm();
	int n_cases;
	cin >> n_cases;
	init(0, 0, M - 1);
	for (int case_id = 0; case_id < n_cases; ++case_id) {
		int n, m;
		cin >> n >> m;
		vector<int> x(m), y(m);
		for (int i = 0; i < m; ++i) {
			cin >> x[i] >> y[i];
			--x[i];
			--y[i];
		}
		unordered_set<int> mark;
		vector<int> removed;
		for (int i = m - 1; i >= 0; --i) {
			int p = gt(y[i]);
			removed.push_back(p);
			up(p, -1);
			int q = gt(y[i]);
			mark.insert(q);
		}
		for (int p : removed) {
			up(p, 1);
		}
		m = mark.size();
		mint result = 0;
		for (int i = 0; i <= m; ++i) {
			mint t = choose(m, i) * choose(n + (n - i) - 1, (n - i));
			if (i & 1) {
				result -= t;
			} else {
				result += t;
			}
		}
		printf("%d\n", result.v);
	}
	return 0;
}