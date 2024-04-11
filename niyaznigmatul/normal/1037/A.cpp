#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int i = 1;
	int ans = 0;
	while (n >= i) {
		n -= i;
		i *= 2;
		ans++;
	}
	if (n > 0) ans++;
	cout << ans << endl;
}