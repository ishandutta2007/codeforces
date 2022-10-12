#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	k = 240 - k;
	
	int ans = 0;
	while (k > 0 && n > 0) {
		n--;
		k -= 5 * (ans + 1);
		if (k >= 0) ans++;
	}
	
	cout << ans << endl;
	return 0;
}