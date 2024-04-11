#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes;
    for (int i = 1; i <= 1000; i++) {
    	if (is_prime(i)) {
    		primes.push_back(i);
    	}
    }

	int t;
	cin >> t;

	while (t--) {
		int n; long long k;
		cin >> n >> k;

		vector<long long> a(n);
		for (auto &x : a) cin >> x;

		sort(a.begin(), a.end());

		long long g = 0;
		for (int i = 1; i < n; i++) {
			g = __gcd(g, a[i] - a[i - 1]);
		}

		bool f = false;
		f |= binary_search(a.begin(), a.end(), k);
		f |= (k % g + g) % g == (a[0] % g + g) % g;
		cout << (f ? "YES" : "NO") << '\n';
	}
    return 0;
}