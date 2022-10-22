#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M = 1e9 + 7;
int n, a[1 << 20], p[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++a[x];
	}
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j <= 1000000; ++j)
			if (!(j & (1 << i)))
				a[j] += a[j ^ (1 << i)];
	p[0] = 1;
	for (int i = 1; i <= 1000000; ++i)
		p[i] = p[i - 1] * 2 % M;
	ll ans = p[n] - 1 + 10000000ll * M;
	for (int i = 1; i <= 1000000; ++i) {
		int s = (__builtin_popcount(i) & 1) ? -1 : 1;
		ans += s * (p[a[i]] - 1);
	}
	cout << ans % M;
	return 0;
}