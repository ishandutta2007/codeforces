#include <iostream>
using namespace std;
int main() {
	int n, a[3], ans = 3, md = 1e9 + 7; cin >> n;
	if (n < 3) {
		if (n == 1) cout << 1;
		else cout << 3;
		return 0;
	}
	a[0] = 1, a[1] = 2;
	for (int i = 2; i < n; i++) a[i % 3] = (a[(i - 1) % 3] + a[(i - 2) % 3]) % md, ans = (ans + a[i % 3]) % md;
	cout << ans << endl;
}