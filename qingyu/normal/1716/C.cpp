#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 50;

int a[2][N], x[2][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		x[0][n] = x[1][n] = 0;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				++a[i][j];
				x[i][j] = 0;
			}
		a[0][0] = 0;
		for (int j = n - 1; j >= 0; --j) {
			for (int i = 0; i < 2; ++i) {
				int v = max(a[!i][j], a[i][j] + 2 * (n - j) - 1);
				x[i][j] = max(v, x[i][j + 1] + 1);
				//printf("x[%d][%d] = %d\n", i, j, x[i][j]);
			}
		}
		int ans = 0x3f3f3f3f, pre = 0, j = 0;
		for (int i = 0; i < n; ++i, j ^= 1) {
			int ret = max(pre, x[j][i]);
			//printf("ret = %d, pre = %d, x[j][i] = %d\n", ret, pre, x[j][i]);
			ans = min(ans, ret);
			pre = max(pre, 2 * (n - i) + max(a[j][i] - 1, a[!j][i] - 2));
		}
		cout << ans << '\n';
	}	
	return 0;
}