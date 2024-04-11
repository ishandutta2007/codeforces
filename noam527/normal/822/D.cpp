#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
const int md = 1e9 + 7;
using namespace std;

vector<int> sieve(5e6 + 1, 1e9), f(5e6 + 1);

void preprocess() {
	for (int i = 2; i < sieve.size(); i++) {
		if (sieve[i] == 1e9) {
			sieve[i] = i;
			for (ll j = (ll)i * i; j < sieve.size(); j += i)
				if (sieve[j] == 1e9) sieve[j] = i;
		}
	}
	f[1] = 0;
	for (int i = 2; i < f.size(); i++)
		f[i] = (f[i / sieve[i]] + ((ll)i * (sieve[i] - 1) / 2) % md) % md;
}

int main() {
	preprocess();
	ll t, l, r, ans = 0;
	cin >> t >> l >> r;
	for (int i = r; i >= l; i--)
		ans = (ans * t + f[i]) % md;
	cout << ans << endl;
}