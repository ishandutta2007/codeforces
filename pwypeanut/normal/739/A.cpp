#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
	scanf("%d%d", &N, &K);
	int mn = 2000000000;
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		mn = min(mn, b - a + 1);
	}
	printf("%d\n", mn);
	for (int i = 0; i < N; i++) {
		if (i) printf(" ");
		printf("%d", i % mn);
	}
	printf("\n");
}