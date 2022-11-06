#include <bits/stdc++.h>
using namespace std;
#define int long long

int w, m, c;
map<int, int> a;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> w >> m;
	while (m) {
		a[c++] = m % w;
		m /= w;
	}
	for (int i = 0; i < c; i++) {
		if (a[i] == w - 1 || a[i] == w) a[i + 1]++;
		else if (a[i] != 1 && a[i]) return cout << "NO\n", 0;
	}
	cout << "YES\n";
}