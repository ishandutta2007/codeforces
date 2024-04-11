#pragma warning(disable:4996)
#include <stdio.h>
const int N = 500;
long long bd[N][N];
int main() {
	int n; scanf("%d", &n);
	if (n == 1) {
		puts("1"); return 0;
	}
	int ei = -1, ej = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lld", &bd[i][j]);
			if (!bd[i][j]) {
				ei = i; ej = j;
			}
		}
	}
	int ni = (ei + 1) % n;
	long long S = 0; long long ans = 0;
	for (int i = 0; i < n; i++)S += bd[ni][i];
	ans = S;
	for (int i = 0; i < n; i++) if (i != ej)S -= bd[ei][i];
	if (S <= 0) {
		puts("-1"); return 0;
	}
	else bd[ei][ej] = S;
	for (int i = 0; i < n; i++) {
		long long t = 0;
		for (int j = 0; j < n; j++) t += bd[i][j];
		if (t != ans) {
			puts("-1"); return 0;
		}
	}
	for (int j = 0; j < n; j++) {
		long long t = 0;
		for (int i = 0; i < n; i++) t += bd[i][j];
		if (t != ans) {
			puts("-1"); return 0;
		}
	}
	long long t = 0;
	for (int i = 0; i < n; i++) t += bd[i][i];
	if (t != ans) {
		puts("-1"); return 0;
	}
	t = 0;
	for (int i = 0; i < n; i++) t += bd[n - 1 - i][i];
	if (t != ans) {
		puts("-1"); return 0;
	}
	printf("%lld\n", S);
}