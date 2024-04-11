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

vector<int> primes = generatePrimes(100000);
int n, k, a[100000], cnt[100001];
vector<int> f[100001];
ll ans = 0;

void solve(int x) {
	int y = x;
	int base = 1;
	for (int p : f[x]) {
		int cnt = 0;
		while(y % p == 0) y /= p, ++cnt;
		cnt = (1000 * k - cnt) % k;
		for (int i = 0; i < cnt; ++i) {
			if ((ll)base * p > 100000) return;
			base *= p;
		}
	}
	for (int i = 1; i <= 1000; ++i) {
		int cur = base;
		for (int j = 0; j < k; ++j) {
			if ((ll)cur * i > 100000) return;
			cur *= i;
		}
		ans += (ll)cnt[x] * cnt[cur];
		ans -= (cur == x) * cnt[x];
		//if (cnt[x] * cnt[cur]) cout << x << " " << cur << " " << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int p : primes) for (int i = p; i <= 100000; i += p) f[i].push_back(p);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++cnt[a[i]];
	}
	for (int i = 1; i <= 100000; ++i) if (cnt[i]) solve(i);
	assert(ans % 2 == 0);
	ans /= 2;
	cout << ans;
	return 0;
}