#include <cstdio>

const int N = 2000;
int diag1[N], diag2[N];

int main () {
	int n;
	scanf ("%d", &n);
	
	int x, y;
	for (int i=0; i<n; i++) {
		scanf ("%d %d", &x, &y);
		x--, y--;
		
		diag1[x + y]++;
		diag2[x - y + (N >> 1)]++;
	}
	
	long long ans = 0;
	for (int i=0; i<N; i++) ans += diag1[i] * (diag1[i] - 1) >> 1, ans += diag2[i] * (diag2[i] - 1) >> 1;
	
	printf ("%I64d\n", ans);
	
	return 0;
}