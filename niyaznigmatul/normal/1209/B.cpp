/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int mx = 0;
	for (int it = 0; it < 30000; it++) {
		int cur = 0;
		for (char e : s) {
			if (e == '1') cur++;
		}
		mx = max(mx, cur);
		for (int i = 0; i < n; i++) {
			if (it >= b[i] && (it - b[i]) % a[i] == 0) {
				s[i] = s[i] == '1' ? '0' : '1';
			}
		}
	}
	cout << mx << endl;
}