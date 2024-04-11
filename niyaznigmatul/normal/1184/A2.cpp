/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : (gcd(b, a % b));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);	
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		if (n % i != 0) continue;
		vector<int> count(i);
		for (int j = 0; j < n; j++) {
			count[j % i] += s[j] - '0';
		}
		bool ok = true;
		for (int j = 0; j < i; j++) {
			if (count[j] % 2 != 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans[i] = true;
		}
	}
	int aa = 0;
	for (int i = 0; i < n; i++) {
		if (ans[gcd(i, n)]) {
			aa++;
		}
	}
	cout << aa << endl;
}