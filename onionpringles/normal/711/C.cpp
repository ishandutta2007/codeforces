#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 100;
long long D[N][N][N];
int c[N]; int p[N][N];
void upd(long long &n, long long v) {
	if (n == -1) n = v;
	else n = min(n, v);
}
int main() {
	int n, m, spl; scanf("%d%d%d", &n, &m, &spl);
	for (int i = 0; i < n; i++)scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &p[i][j]);
	for (int i = 0; i < n; i++) for (int j = 0; j < spl; j++)for (int k = 0; k < m; k++) D[i][j][k] = -1;
	if (c[0]) {
		D[0][0][c[0] - 1] = 0;
	}
	else {
		for (int k = 0; k < m; k++) {
			D[0][0][k] = p[0][k];
		}
	}
	for (int i = 1; i < n; i++) {
		if (c[i]) {
			D[i][0][c[i] - 1] = D[i - 1][0][c[i] - 1];
		}
		else {
			for (int k = 0; k < m; k++) {
				if (D[i - 1][0][k] == -1) D[i][0][k] = -1;
				else D[i][0][k] = D[i - 1][0][k] + p[i][k];
			}
		}
		for (int j = 1; j <= i; j++) {
			if (c[i]) {
				for (int k = 0; k < m; k++) {
					if (k + 1 != c[i]) {
						if (D[i - 1][j - 1][k] != -1) upd(D[i][j][c[i] - 1], D[i - 1][j - 1][k]);
					}
					else {
						if (D[i - 1][j][k] != -1) upd(D[i][j][c[i] - 1], D[i - 1][j][k]);
					}
				}
			}
			else {
				for (int k = 0; k < m; k++) {
					for (int t = 0; t < m; t++) {
						if (t == k) {
							if (D[i - 1][j][t] != -1) upd(D[i][j][k], D[i - 1][j][t] + p[i][k]);
						}
						else {
							if (D[i - 1][j - 1][t] != -1) upd(D[i][j][k], D[i - 1][j - 1][t] + p[i][k]);
						}
					}
				}
			}
		}
	}
	long long M = -1;
	for (int i = 0; i < m; i++) {
		if (D[n - 1][spl - 1][i] != -1) upd(M, D[n - 1][spl - 1][i]);
	}
	printf("%lld\n", M);
}