#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template<typename T>
bool is_prime(T x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; (T) i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

template<typename T>
std::vector<T> divisors(T n) {
	std::vector<T> divisors;
	for (int i = 1; (T) i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i != n / i) {
				divisors.push_back(n / i);
			}
		}
	}
	return divisors;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll temp = 1;
	vector<vector<int>> primes(1);
	for (int i = 1, c = 0; i <= 643; i++) {
		if (is_prime(i)) {
			if ((ld)temp * i > ll(1e18)) {
				c++;
				primes.emplace_back();
				temp = i;
			} else {
				temp *= i;
			}
			primes.back().push_back(i);
		}
	}

	vector<ll> prod(primes.size(), 1);
	for (int i = 0; i < primes.size(); i++) {
		for (int prime : primes[i]) {
			prod[i] *= prime;
		}
	}

	int t;
	cin >> t;

	auto query = [&](ll Q) {
		cout << "? " << Q << endl;
		int g;
		cin >> g;
		return g;
	};

	while (t--) {
		vector<ll> to_query;
		for (int i = 0; i < primes.size(); i++) {
			int g = query(prod[i]);
			for (auto prime : primes[i]) {
				if (g % prime == 0) {
					int pw = 1;
					while ((ll)pw * prime <= int(1e9))
						pw *= prime;
					to_query.push_back(pw);
				}
			}
		}

		int num = 1;
		for (int i = 0; i < to_query.size(); i += 2) {
			num *= query(to_query[i] * (i + 1 < to_query.size() ? to_query[i + 1] : 1));
		}

		int cnt = divisors(num).size();
		if (cnt == 1) {
			cout << "! " << 8 << endl;
		} else if (cnt == 2) {
			cout << "! " << 9 << endl;
		} else {
			cout << "! " << 2 * cnt << endl;
		}
	}
	return 0;
}