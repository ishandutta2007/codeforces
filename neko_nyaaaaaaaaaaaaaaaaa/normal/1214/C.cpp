#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	int op = 0, clo = 0;
	for (char c: s) {
		op += (c == '(');
		clo += (c == ')');
	}
	if (op != clo) {
		cout << "No"; return 0;
	}

	int met_clo = 0;
	string sk;
	for (char c: s) {
		if (c == '(') {
			sk.push_back(c);
		} else {
			if (met_clo == 0) {
				met_clo = 1;
			} else {
				sk.push_back(c);
			}
		}
	}
	sk.push_back(')');

	int cnt = 0;
	for (char c: sk) {
		if (c == '(') cnt++;
		else cnt--;

		if (cnt < 0) {
			cout << "No"; exit(0);
		}
	}
	cout << "Yes";

	return 0;
}