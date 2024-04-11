#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int now = 1;
		vector <int> ans;
		while (now <= n) {
			ans.push_back(n / now);
			int l = now, r = n + 1;
			while (l < r) {
				int mid = l + r >> 1;
				if (n / mid == n / now) l = mid + 1;
				else r = mid;
			}
			now = l;
		}
		ans.push_back(0);
		reverse(ans.begin(), ans.end());
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}