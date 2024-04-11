#include <bits/stdc++.h>
using namespace std;

int count(int mask) {
	int res = 0;
	while (mask) {
		res += mask & 1;
		mask >>= 1;
	}
	return res;
}

int main () {
	int T; cin >> T;
	while (T--) {
		int a[3]; cin >> a[0] >> a[1] >> a[2];
		int tmp[3] = {a[0], a[1], a[2]};
		int ans = 0;
		for (int mask = 0; mask < (1 << 8); mask += 2) {
			int cnt = count(mask);
			a[0] = tmp[0], a[1] = tmp[1], a[2] = tmp[2];
			for (int i = 1; i < 8; i++) {
				if (mask >> i & 1) {
					for (int j = 0; j < 3; j++) {
						if (i >> j & 1) a[j]--;
					}
				}
			}
			if (a[0] < 0 || a[1] < 0 || a[2] < 0) continue;
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
	return 0;
}