#include <bits/stdc++.h>
using namespace std;

template <int N>
struct sieve {
	std::vector<int> primes;
	std::array<int, N + 1> spf;

	sieve() : spf() {
		for (int i = 2; i <= N; i++) {
			if (spf[i] == 0) {
				spf[i] = i;
				primes.push_back(i);
			}
			for (int j = 0; j < (int) primes.size() && i * primes[j] <= N; j++) {
				spf[i * primes[j]] = primes[j];
				if (i % primes[j] == 0) {
					break;
				}
			}
		}
	}

	bool is_prime(int x) const {
		return spf[x] == x;
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
		std::vector<int> divisors = {1};
		while (x > 1) {
			int p = spf[x], c = 0;
			while (x % p == 0) {
				x /= p, c += 1;
			}
			int sz = (int) divisors.size();
			for (int i = 1, pw = p; i <= c; i++, pw *= p) {
				for (int j = 0; j < sz; j++) {
					divisors.push_back(divisors[j] * pw);
				}
			}
		}
		return divisors;
	}

	template <typename T, typename F>
	T compute_multiplicative_function(int x, F &&f) const {
		T result = T(1);
		while (x > 1) {
			int p = spf[x], c = 0;
			while (spf[x] == p) {
				x /= p, c += 1;
			}
			result *= f(p, c);
		}
		return result;
	}
};

constexpr int N = 200000;

sieve<N> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		auto query = [&](int i, int j) -> long long {
			cout << "? " << i + 1 << ' ' << j + 1 << endl;
			long long lcm;
			cin >> lcm;
			return lcm;
		};

		vector<long long> a(n);
		if (n < 100) {
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					long long lcm = query(i, j);
					a[i] = __gcd(a[i], lcm);
					a[j] = __gcd(a[j], lcm);
				}
			}

			if (n == 3 && (~a[0] & 1) && (~a[1] & 1) && (~a[2] & 1)) {
				*max_element(a.begin(), a.end()) /= 2;
			}
		} else {
			vector<int> ind(n);
			iota(ind.begin(), ind.end(), 0);
			random_shuffle(ind.begin(), ind.end(), [&](int j) {
				return rng() % j;
			});

			int largest_prime = -1;
			for (int i = 0; i < min(250, n); i++) {
				for (int j = 0; j < 20; j++) {
					int other;
					while (other = rng() % n, other == i);
					long long lcm = query(ind[i], ind[other]);
					a[ind[i]] = __gcd(a[ind[i]], lcm);
				}
				if (s.is_prime(a[ind[i]]) && (largest_prime == -1 || a[ind[i]] > a[largest_prime])) {
					largest_prime = ind[i];
				}
			}

			for (int i = 0; i < n; i++) {
				if (i != largest_prime) {
					a[i] = query(i, largest_prime) / a[largest_prime];
				}
			}
		}

		cout << "! ";
		for (auto &x : a) {
			cout << x << ' ';
		}
		cout << endl;
	}
	return 0;
}