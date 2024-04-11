#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int n, d; cin >> n >> d;
		int now = 1;
		if (d <= n) {
			printf("YES\n");
			continue;
		}
		while ((d + now - 1) / now > 1) {
			int l = now + 1, r = d;
			while (l < r) {
				int mid = l + r >> 1;
				if ((d + mid - 1) / mid == (d + now - 1) / now) l = mid + 1;
				else r = mid;
			}
			now = l;
			if ((d + now - 1) / now + now - 1 <= n) {
				printf("YES\n");
				goto END;
			}
		}
		printf("NO\n");
		END:;
	}
	return 0;
}