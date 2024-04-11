#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cout << 500009 << ' ' << 500009 << '\n';
	for (int i=1; i<n-1; ++i) {
		cout << i << ' ' << i+1 << ' ' << 1 << '\n';
	}
	cout << n-1 << ' ' << n << ' ' << 500009-(n-2) << '\n';
	m -= (n-1);

	for (int gap=2; gap<=n-1; ++gap) {
		for (int i=1; i<=n-gap; ++i) {
			if (m<=0)
				break;
			cout << i << ' ' << i+gap << ' ' << 10000000 << '\n';
			m--;
		}
		if (m<=0)
			break;
	}
	return 0;
}