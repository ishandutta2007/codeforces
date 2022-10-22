#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	int ans = 1000000000;
	for (int i = 1; i <= N; i++) {
		int x = N / i;
		if (N % i != 0) x++;
		ans = min(ans, 2 * (i + x));
	}
	printf("%d\n", ans);
}