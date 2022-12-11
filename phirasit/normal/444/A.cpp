#include <stdio.h>
#include <algorithm>

#define N 510

double arr[N];
double ans = 0;
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) {
		scanf("%lf", &arr[i]);
	}
	for(int i = 0;i < m;i++) {
		int a, b;
		double c;
		scanf("%d%d%lf", &a, &b, &c);
		ans = std::max(ans, (arr[a] + arr[b]) / c);
	}
	printf("%.10lf\n", ans);
	return 0;
}