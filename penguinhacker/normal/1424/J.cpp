#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

deque<int> generatePrimes(const int MXPRIME) { //nloglogn where n is MXPRIME
	vector<bool> isPrime(MXPRIME+1, 1);
	deque<int> primes;
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
	deque<int> p = generatePrimes(2000000);
	vector<int> ans(1000001);
	ans[0] = 1;

	for (int i : p) {
		if (i > 1000000) break;
		++ans[i];
	}
	for (int i : p) {
		int x = i * i;
		if (x > 1000000) break;
		--ans[x];
	}
	for (int i = 1; i <= 1000000; ++i) {
		ans[i] += ans[i - 1];
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << ans[n] << "\n";
	}
	return 0;
}