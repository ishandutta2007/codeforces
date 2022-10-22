#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
	scanf("%d%d", &N, &K);
	K = 240 - K;
	for (int i = 1; i <= N; i++) {
		if (K < 5 * i) {
			printf("%d\n", i - 1);
			return 0;
		} else K -= 5*i;
	}
	printf("%d\n", N);
	
}