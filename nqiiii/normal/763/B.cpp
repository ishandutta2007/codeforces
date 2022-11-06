#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		int x, y; scanf("%d%d", &x, &y); scanf("%d%d", &x, &y);
		printf("%d\n", (x + 1000000000) % 2 * 2 + (y + 1000000000)% 2 + 1);
	}
}