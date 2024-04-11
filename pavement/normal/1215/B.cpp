#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, a[200005], p[200005], m[4];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + (a[i] < 0);
		p[i] %= 2;
	}
	m[0]++;
	for (int i = 1; i <= n; i++) {
		t += m[p[i]];
		m[p[i]]++;
	}
	cout << n * (n + 1) / 2 - t << ' ' << t << '\n';
}