#include <iostream>
#include <algorithm>
#include <vector>
const int lim = 31625; // upper bound to the square root of 1000000000 (1e9), the maximum N.
using namespace std;

vector<int> primes;

void computeprimes() {
	vector<bool> sieve(lim, true);
	int i;
	for (i = 2; i * i < lim; i++) {
		if (sieve[i]) {
			primes.push_back(i);
			for (int j = i * i; j < lim; j += i) sieve[j] = false;
		}
	}
	for (; i < lim; i++) if (sieve[i]) primes.push_back(i);
}

int main() {
	computeprimes();
	int n, ans; // answer won't exceed integer limit. "worst case" for ans is (1e9 + 1e9 / 2 + 1e9 / 4 + 1e9 / 8 + ......) = 2e9
	cin >> n;
	ans = n;
	for (auto i : primes) {
		while (n % i == 0)
			n /= i, ans += n;
	}
	if (n > 1) ans++;
	cout << ans << endl;
}