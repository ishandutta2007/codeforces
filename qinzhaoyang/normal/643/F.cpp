#include <stdio.h>
#include <bits/stdc++.h>
#define ui unsigned int

using namespace std;

ui n, p, q, s[200], A;

ui S(ui x) {
	vector <ui> a, b;
	for (int i = 1; i <= x; i++) b.push_back(i);
	for (int i = 1; i <= x; i++) a.push_back(n - i + 1);
	for (auto &i : a) for (auto &j : b) {
		ui d = __gcd(i, j);
		i /= d, j /= d;
	}
	ui ret = 1;
	for (auto i : a) ret *= i;
	return ret;
}

int main() {
	cin >> n >> p >> q, p = min(p, n - 1);
	for (ui i = 0; i <= p; i++) s[i] = S(i);
	for (ui i = 1; i <= q; i++) {
		ui res = 0;
		for (ui j = 0, k = 1; j <= p; j++, k *= i)
			res += s[j] * k;
		A ^= res * i;
	}
	cout << A << "\n";
	return 0;
}