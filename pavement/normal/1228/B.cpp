#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, t, co = 0;
	scanf("%d%d", &h, &w);
	short mat[h + 2][w + 2];
	int inp[h * w];
	memset(mat, -1, sizeof(mat));
	for (int i = 1; i <= h; i++) {
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) mat[i][j] = 1;
		mat[i][t + 1] = 2;
		inp[co++] = t;
	}
	for (int i = 1; i <= w; i++) {
		scanf("%d", &t);
		for (int j = 1; j <= t; j++) mat[j][i] = 1;
		mat[t + 1][i] = 2;
		inp[co++] = t;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 1; j <= inp[i]; j++) {
			if (mat[i + 1][j] != 1) {
				printf("0\n");
				return 0;
			}
		}
		if (mat[i + 1][inp[i] + 1] != 2) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = h; i < h + w; i++) {
		for (int j = 1; j <= inp[i]; j++) {
			if (mat[j][i + 1 - h] != 1) {
				printf("0\n");
				return 0;
			}
		}
		if (mat[inp[i] + 1][i + 1 - h] != 2) {
			printf("0\n");
			return 0;
		}
	}
	long long c = 0, r = 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			c += mat[i][j] == -1;
		}
	}
	for (int i = 0; i < c; i++) {
		r *= 2;
		r %= 1000000007;
	}
	printf("%lld\n", (r));
}