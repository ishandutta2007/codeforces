#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

int dyn[150][76][5625];

int q[150];
int r[150];
int badflag = 0;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k, s;
	scanf("%d %d %d", &n, &k, &s);
	for (int i = 0; i < n; i++) scanf("%d", q + i);
	if (s >= 5625) {
		sort(q, q + n);
		int res = 0;
		for (int i = 0; i < k; i++) res += q[i];
		printf("%d\n", res);
		return 0;
	}
	int sum = 0;
	if (2 * k > n) {
		k = n - k;
		for (int i = 0; i < n; i++) sum += q[i];
		for (int i = 0; i < n; i++) r[i] = 1000000 - q[i];
		for (int i = 0; i < n; i++) q[i] = r[n - 1 - i];
		
		badflag = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i+1 && j<=k ; j++) {
			for (int l = 0; l <= s; l ++) {
				if (j == 0) {
					dyn[i][j][l] = 0;
					continue;
				}
				if (i == 0) {
					dyn[i][j][l] = q[0];
					continue;
				}
				if (j == i + 1) {
					dyn[i][j][l] = dyn[i - 1][j - 1][l] + q[i];
					continue;
				}
				dyn[i][j][l] = dyn[i - 1][j][l];
				if (l >= i + 1 - j) {
					dyn[i][j][l] = min(dyn[i][j][l], dyn[i - 1][j - 1][l - (i + 1 - j)] + q[i]);
				}
			}
		}
	}
	if (badflag) {
		printf("%d\n", dyn[n - 1][k][s] + sum - 1000000 * k);
	}
	else {
		printf("%d\n", dyn[n - 1][k][s]);
	}
	return 0;
}