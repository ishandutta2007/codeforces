#include <bits/stdc++.h>
using namespace std;

int hamming(string a, string b) {
	int res = 0;
	for (int i = 0; i < size(a); i++) {
		res += a[i] != b[i];
	}
	return res;
}

int solve(string a, string b) {
	int n = size(a);

	int ka = 0, kb = 0;
	for (char c: a) ka += c == '1';
	for (char c: b) kb += c == '1';

	if (a == b) return 0;
	if (ka == 0 || kb == 0) return -1;
	if (ka != kb && ka+kb != n+1) return -1;

	auto flip = [&]() {
		for (char &c: a) c ^= 1;
		for (int i = 0; i < n; i++) {
			if (a[i] < b[i]) {
				a[i] = '1';
				return;
			}
		}
		assert(0);
	};
	
	int res = 1e9;
	if (ka == kb) {
		res = min(res, hamming(a,b));
	}
	if (ka+kb == n+1) {
		flip();
		res = min(res, hamming(a,b) + 1);
	}
	return res;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		string a, b;
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}
}