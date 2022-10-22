#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<int> generatePrimes(const int MXPRIME) {
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

int n, a[100000];
vector<int> primes = generatePrimes(200000);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll ans = 1;
	for (int p : primes) {
		pair<int, int> worst = {INT_MAX, INT_MAX};
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			while(a[i] % p == 0) {
				a[i] /= p;
				++cnt;
			}
			if (cnt < worst.first) {
				worst = {cnt, worst.first};
			}
			else if (cnt < worst.second) {
				worst.second = cnt;
			}
			if (worst.second == 0) {
				break;
			}
		}
		for (int i = 0; i < worst.second; ++i) {
			ans *= p;
		}
	}
	cout << ans;
	return 0;
}