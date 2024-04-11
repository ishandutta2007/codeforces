#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int dat[50][50];
int chk[50];
int ans[50];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &dat[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			int bad = 0;
			if (chk[j]) continue;
			for (int k = 0; k < n; k++) {
				if (j == k) continue;
				if (chk[k]) continue;
				if (dat[j][k] != i) {
					bad = 1;
					break;
				}
			}
			if (!bad) {
				ans[j] = i;
				chk[j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}