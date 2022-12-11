#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, a, b;

int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	int d = n/m, r = n%m;
	printf("%d\n", min(n * a, min(d * b + r * a, (d + !!r) * b)));
	return 0;
}