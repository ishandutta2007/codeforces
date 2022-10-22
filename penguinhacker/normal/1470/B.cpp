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

vector<int> primes = generatePrimes(1000);

void reduce(int& x) {
	for (int i : primes) {
		if (i * i > x) break;
		while(x % (i * i) == 0) x /= i * i;
	}
}

void solve() {
	int n; cin >> n;
	map<int, int> mp;
	map<int, int> mp2;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		reduce(a);
		++mp[a];
	}
	int ans1 = 0, ans2 = 0;
	for (auto&x : mp) {
		ans1 = max(ans1, x.second);
		if (x.second % 2 == 0) mp2[1] += x.second;
		else mp2[x.first] = x.second;
	}
	for (auto&x : mp2) ans2 = max(ans2, x.second);
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		ll w; cin >> w;
		cout << (w == 0 ? ans1 : ans2) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}