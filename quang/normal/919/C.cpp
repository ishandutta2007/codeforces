#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, m, k;
char a[N][N];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cur = 0;
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '.') {
				cur++;
			} else {
				cur = 0;
			}
			if (cur >= k) {
				res++;
			}
		}
	}
	// cout << res << endl;
	if (k == 1) {
		cout << res << endl;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int cur = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j][i] == '.') {
				cur++;
			} else {
				cur = 0;
			}
			if (cur >= k) {
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}