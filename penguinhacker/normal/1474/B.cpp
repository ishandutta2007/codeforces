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

vector<int> p = generatePrimes(100000);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int d; cin >> d;
		int a = *lower_bound(p.begin(), p.end(), d + 1);
		int b = *lower_bound(p.begin(), p.end(), a + d);
		cout << (ll)a * b << "\n";
	}
	return 0;
}