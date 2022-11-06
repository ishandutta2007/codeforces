#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, a[5];
	cin >> t;
	while (t--) {
		int T = 0;
		cin >> a[0] >> a[1] >> a[2];
		T += !!a[0] + !!a[1] + !!a[2];
		a[0] = max(0ll, a[0] - 1);
		a[1] = max(0ll, a[1] - 1);
		a[2] = max(0ll, a[2] - 1);
		sort(a, a + 3);
		if (a[1] && a[2]) T++, a[1]--, a[2]--;
		if (a[0] && a[1]) T++, a[0]--, a[1]--;
		if (a[0] && a[2]) T++, a[0]--, a[2]--;
		if (a[0] && a[1] && a[2]) T++;
		cout << T << '\n';
	}
}