//sobskdrbhvk
//remeber... ):(
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, l, a;
	cin >> n >> l >> a;
	int tmp = 0,
		ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ans += (x - tmp) / a;
		tmp = x + y;
	}
	ans += (l - tmp) / a;
	cout << ans << endl;
	return 0;
}