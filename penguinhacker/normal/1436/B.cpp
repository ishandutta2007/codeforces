#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<int> generatePrimes(const int MXPRIME) { //nloglogn where n is MXPRIME
	vector<bool> isPrime(MXPRIME+1, 1);
	vector<int> primes;
	for (int i=2; i<=MXPRIME; ++i) {
		if (!isPrime[i]) {
			continue;
		}
		primes.push_back(i);
		for (ll j=(ll)i*i; j<=MXPRIME; j+=i) {
			isPrime[j]=0;
		}
	}
	return primes;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> primes = generatePrimes(100000);

	auto find = [&](int x) {
		auto it = upper_bound(primes.begin(), primes.end(), x);
		while(1) {
			assert(it != primes.end());
			int cand = *it - x;
			if (*lower_bound(primes.begin(), primes.end(), cand) != cand) {
				return cand;
			}
			++it;
		}
	};

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> ans(n, vector<int>(n));
		for (int i = 0; i < n - 1; ++i) for (int j = 0; j < n - 1; ++j) ans[i][j] = 1;
		int x = find(n - 1);
		for (int i = 0; i < n - 1; ++i) ans[n - 1][i] = ans[i][n - 1] = x;
		ans[n - 1][n - 1] = find(x * (n - 1));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}