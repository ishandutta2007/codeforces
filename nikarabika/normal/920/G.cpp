//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define sz(x) ((int)(x).size())

typedef long long int LL;

LL f(LL pos, LL p) {
	vector<LL> factors;
	for (LL i = 2; i * i <= p; i++)
		if (p % i == 0) {
			factors.PB(i);
			while (p % i == 0)
				p /= i;
		}
	if (p > 1)
		factors.PB(p);
	int sz = sz(factors);
	LL ans = 0;
	for (int mask = 0; mask < (1 << sz); mask++) {
		LL num = 1;
		for (int i = 0; i < sz; i++)
			if ((mask >> i) & 1)
				num *= factors[i];
		int sign = (__builtin_popcountll(mask) & 1) ? -1 : +1;
		ans += sign * pos / num;
	}
	return ans;
}

void solve(void) { 
	int x, k, p;
	cin >> x >> p >> k;
	if (p == 1) {
		cout << x + k << '\n';
		return;
	}
	k += f(x, p);
	//cout << "#" << k << endl;
	LL fp = f(p, p);
	LL lo = -1,
	   hi = p - 1;
	while (hi - lo > 1) {
		LL mid = (lo + hi) >> 1;
		if (f(mid, p) >= (k % fp == 0 ? fp : k % fp))
			hi = mid;
		else
			lo = mid;
	}
	//cout << "@ " << f(hi + p * (k / fp), p) << endl;
	cout << hi + 1LL * p * ((k - 1) / fp) << '\n';
}

int main() {
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}