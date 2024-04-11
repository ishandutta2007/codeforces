#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	if (n == 1) {
		printf("%d", k ? -1 : 1); return 0;
	}
	if (k < n / 2) printf("-1");
	else {
		for (int i = 1; i <= (n / 2 - 1) * 2; ++i) printf("%d ", i);
		k -= n / 2 - 1; int v = (((n / 2 - 1) * 2) / k + 1) * k;
		printf("%d %d ", v, v + k); if (n & 1) printf("1000000000");
	}
}