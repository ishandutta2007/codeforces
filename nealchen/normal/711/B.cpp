#include <stdio.h>
int n;
long long a[500][500], row[500], col[500], dia[2];
int main() {
	int i, j, x, y;
	scanf("%d", &n);
	if(n == 1) return !printf("1");
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n; ++j) {
			scanf("%lld", &a[i][j]);
			if(!a[i][j]) x = i, y = j;
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
		dia[0] += a[i][i];
		dia[1] += a[i][n - 1 - i];
	}
	a[x][y] = x ? row[0] - row[x] : row[1] - row[0];
	if(a[x][y] <= 0) return !printf("-1");
	row[x] += a[x][y];
	col[y] += a[x][y];
	dia[0] += (x == y) * a[x][y];
	dia[1] += (x + y == n - 1) * a[x][y];
	if(dia[0] != dia[1]) return !printf("-1");
	for(i = 0; i < n; ++i) if(row[i] != dia[0] || col[i] != dia[0]) return !printf("-1");
	printf("%lld", a[x][y]);
	return 0;
}