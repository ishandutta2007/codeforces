#include <bits/stdc++.h>
using namespace std;

namespace extended_euclidean {
	using big_int = long long;

	template<typename T>
	std::tuple<T, big_int, big_int> ext_euclid(T a, T b) {
		if (b == 0)
			return std::make_tuple(a, 1, 0);
		auto[g, x, y] = ext_euclid(b, a % b);
		return std::make_tuple(g, y, x - y * (a / b));
	}

	template<typename T>
	T gcd(T a, T b) {
		return get<0>(ext_euclid(a, b));
	}

	template<typename T>
	T mod_inverse(T a, T m) {
		auto[g, x, y] = ext_euclid(a, m);
		if (g != 1)
			return -1;
		return ((x %= m) < 0 ? x + m : x);
	}

	big_int crt(big_int a1, big_int n1, big_int a2, big_int n2) {
		auto[g, m1, m2] = ext_euclid(n1, n2);
		if (g != 1)
			return -1;
		big_int x = (a1 * m2 * n2 + a2 * m1 * n1) % (n1 * n2);
		return x < 0 ? x + n1 * n2 : x;
	}

	template <typename T>
	big_int crt(std::vector<T> a, std::vector<T> n) {
		big_int x = crt(a[0], n[0], a[1], n[1]), N = n[0] * n[1];
		for (int i = 2; i < n.size(); i++) {
			x = crt(x, N, a[i], n[i]);
			N *= n[i];
		}
		return x;
	}

	template <typename T>
	std::pair<T, T> solve_linear_congruence(T a, T b, T n) {
		T d = gcd(a, n);
		if (b % d != 0)
			return std::make_pair(-1, -1);
		a /= d, b /= d, n /= d;
		T sol = (big_int) mod_inverse(a, n) * b % n;
		return make_pair(sol, d);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; long long k;
	cin >> n >> m >> k;

	int d = __gcd(n, m);

	vector<vector<int>> a(d, vector<int>(n / d)), b(d, vector<int>(m / d));
	for (int i = 0, x; i < n; i++) {
		cin >> x, --x;
		a[i % d][i / d] = x;
	}

	for (int i = 0, x; i < m; i++) {
		cin >> x, --x;
		b[i % d][i / d] = x;
	}

	if (n > m) {
		swap(n, m);
		a.swap(b);
	}

	const long long total_good_days = (long long)(n / d) * (m / d);
	vector<long long> good_days(d, total_good_days);
	vector<vector<long long>> bad_day(d, vector<long long>(n / d, -1));
	vector<int> pos(2 * m, -1);

	int inv = extended_euclidean::mod_inverse(n / d, m / d);
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < m / d; j++) {
			pos[b[i][j]] = j;
		}
		for (int j = 0; j < n / d; j++) {
			if (pos[a[i][j]] != -1) {
				//x * (n / d) + j = pos[a[i][j]] (mod m / d)
				int bb = (pos[a[i][j]] - j + m / d) % (m / d);
				int x = (long long)inv * bb % (m / d);
				bad_day[i][j] = (long long)x * (n / d) + j;
				good_days[i] -= 1;
			}
		}
		for (int j = 0; j < m / d; j++) {
			pos[b[i][j]] = -1;
		}
	}

	auto f = [&](long long days) -> long long {
		long long ans = 0;
		for (int i = 0; i < d; i++) {
			long long actual = days / d + (days % d >= i);
			ans += (actual / total_good_days) * good_days[i];
			ans += (actual %= total_good_days);
			for (int j = 0; j < n / d; j++) {
				if (bad_day[i][j] != -1 && bad_day[i][j] + 1 <= actual) {
					ans -= 1;
				}
			}
		}
		return ans;
	};

	long long lo = 0, hi = (long long)1e18;
	while (lo < hi) {
		long long mid = lo + (hi - lo) / 2;
		if (f(mid) < k)
			lo = mid + 1;
		else hi = mid;
	}

	cout << lo + 1 << '\n';
	return 0;
}