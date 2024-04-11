#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN = 20000001;
short p[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 2; i < mxN; ++i) {
		if (p[i])
			continue;
		for (int j = i; j < mxN; j += i)
			++p[j];
	}
	int t; cin >> t;
	while(t--) {
		ll c, d, x; cin >> c >> d >> x;
		ll ans = 0;
		auto Cmp = [&](int dv) {
			dv += d;
			if (dv % c)
				return;
			dv /= c;
			ans += 1 << p[dv];
		};
		for (int i = 1; i * i <= x; ++i) {
			if (x % i)
				continue;
			Cmp(i);
			if (i * i != x)
				Cmp(x / i);
		}
		cout << ans << "\n";
	}
	return 0;
}