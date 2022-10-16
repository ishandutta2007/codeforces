#include <bits/stdc++.h>
using namespace std;

int last_digit(long long tmp) {
	int ans = 0;
	while (tmp > 0) {
		ans = tmp % 10;
		tmp /= 10;
	}
	return ans;
}

long long count(long long n) {
	while (n > 0 && ((n % 10) != last_digit(n))) n--;
	if (n < 10) return n;

	return 9 + n/10;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	long long l, r; cin >> l >> r;
	cout << count(r) - count(l-1);

	return 0;
}