#include <bits/stdc++.h>
using namespace std;

bool Check(int n) {
	int tmp = max((int)(sqrt(n) - 100), 0);
	while (1ll * tmp * tmp < n) tmp++;
	if (1ll * tmp * tmp == n && tmp % 2 == 0) return 1;
	return 0;
}

int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		if (Check(n) || Check(2 * n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}