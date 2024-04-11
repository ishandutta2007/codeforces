#include <bits/stdc++.h>
using namespace std;

int a[3510];
int minj[3510][3510];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int len = n - m;
		for (int i = 0; i + len < n; i++) {
			a[i] = max(a[i], a[i + len]);
		}
		for (int i = 0; i + len < n; i++) {
			for (int j = i; j + len < n; j++) {
				minj[i][j] = a[j];
				if (i != j) minj[i][j] = min(minj[i][j], minj[i][j - 1]);
			}
		}
		int ans = 0;
		for (int i = 0; i <= min(k, m - 1); i++) {
			for (int j = 0, k = i; k >= 0; j++, k--) {
				int l = j, r = n - k - 1;
				ans = max(ans, minj[l][r - len]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}