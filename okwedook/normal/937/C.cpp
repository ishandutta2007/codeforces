#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	ll k, d, t; 
	cin >> k >> d >> t;
	if (k % d == 0) {
		cout << t;
		return 0;
	}
	ll block = (k / d + 1) * d;
	ll blockd = block - k;
	t *= 2;
	ll full = t / (block + k);
	t %= (block + k);
	cout << fixed;
	if (t > k * 2) cout << full * block + t - k;
	else cout << full * block + t / 2.0;
    return 0;
}