#include <bits/stdc++.h>
using namespace std;

template <int N>
struct sieve {
	std::array<int, N + 1> spf;

	constexpr sieve() {
		spf.fill(0);
		for (int i = 2; i * i <= N; i++) {
			if (spf[i] == 0) {
				for (int j = i * i; j <= N; j += i) {
					if (spf[j] == 0) spf[j] = i;
				}
			}
		}
		for (int i = 2; i <= N; i++) {
			if (spf[i] == 0) {
				spf[i] = i;
			}
		}
	}

	bool is_prime(int x) const {
		return spf[x] == x;
	}

	std::vector<int> primes() const {
		std::vector<int> primes;
		for (int i = 1; i <= N; i++) {
			if (spf[i] == i) {
				primes.push_back(i);
			}
		}
		return primes;
	}

	std::vector<std::pair<int, int>> prime_factors(int x) const {
		std::vector<std::pair<int, int>> factors;
		while (x != 1) {
			if (factors.empty() || factors.back().first != spf[x]) {
				factors.emplace_back(spf[x], 0);
			}
			factors.back().second++;
			x /= spf[x];
		}
		return factors;
	}

	std::vector<int> divisors(int x) const {
		if (x == 1)
			return {1};
		int c = 0, n = x;
		for (; spf[x] == spf[n]; n /= spf[x], c++);
		std::vector<int> d = divisors(n);
		std::vector<int> res((c + 1) * d.size());
		for (int i = 0, j = 0, p = 1; i <= c; i++, p *= spf[x]) {
			for (int item : d) {
				res[j++] = p * item;
			}
		}
		return res;
	}
};

sieve<100000> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<bool> taken(n + 1);
	vector<pair<int, int>> ans;

	vector<vector<pair<int, int>>> factors(n + 1);
	for (int i = 1; i <= n; i++) {
		factors[i] = s.prime_factors(i);
	}

	vector<int> others, primes = s.primes();
	reverse(primes.begin(), primes.end());

	for (auto p : primes) {
		vector<int> can_take;
		for (int i = p; i <= n; i += p) {
			if (!taken[i]) {
				can_take.push_back(i);
			}
		}

		if (can_take.size() % 2 != 0 && 2 * p <= n) {
			can_take.erase(can_take.begin() + 1);
			taken[2 * p] = true;
			others.push_back(2 * p);
		}
		for (int i = 1; i < can_take.size(); i += 2) {
			taken[can_take[i - 1]] = taken[can_take[i]] = true;
			ans.emplace_back(can_take[i - 1], can_take[i]);
		}
	}

	for (int i = 1; i < others.size(); i += 2) {
		ans.emplace_back(others[i - 1], others[i]);
	}

	cout << ans.size() << '\n';
	for (auto &[x, y] : ans) {
		cout << x << ' ' << y << '\n';
	}
	return 0;
}