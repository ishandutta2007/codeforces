#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, k; cin >> a >> b >> k;
	int n = a + b;
	string s(n, '0');
	string t(n, '0');
	s[0] = t[0] = '1', --b;
	if (a == 0 || b == 0) {
		if (k) cout << "No";
		else {
			for (int i = 0; i < b; ++i) s[i + 1] = t[i + 1] = '1';
			cout << "Yes\n" << s << "\n" << t;
		}
	}
	else if (k > n - 2) cout << "No\n";
	else {
		s[1] = t[1 + k] = '1', --b;
		for (int i = 1; i < n && b; ++i) {
			if (s[i] == '0' && t[i] == '0') {
				--b;
				s[i] = t[i] = '1';
			}
		}
		assert(b == 0);
		cout << "Yes\n" << s << "\n" << t;
	}
	return 0;
}