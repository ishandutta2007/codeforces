#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, k, n;
	cin >> a >> b >> k, n = a + b;

	//2^k - 1 = k ones
	//2^(k + 1) - 2
	//2^k - 1
	//2^(k + 1) - 2 - 2^k + 1
	//2^k - 1

	if (k == 0) {
		cout << "Yes\n";
		string x = string(b, '1') + string(a, '0');
		return cout << x << '\n' << x << '\n', 0;
	} else if (a == 0 || b == 1 || k > n - 2) {
		return cout << "No\n", 0;
	}

	string x(n, '0'), y(n, '0');
	x[0] = y[0] = '1', b -= 1;

	x[n - k - 1] = y[n - 1] = '1';
	b -= 1;

	for (int i = 0; i < n && b > 0; i++) {
		if (x[i] != '1' && y[i] != '1') {
			x[i] = y[i] = '1';
			b -= 1;
		}
	}
	cout << "Yes\n";
	cout << x << '\n' << y << '\n';
	return 0;
}