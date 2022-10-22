#include <bits/stdc++.h>
using namespace std;

int N, A[100005];
bool isPrime(int x) {
	int sq = sqrt(x);
	for (int i = 2; i <= sq; i++) if (x % i == 0) return 0;
	return 1;
}

int main() {
	scanf("%d", &N);
	if (N == 1 || N == 2) {
		printf("1\n");
		for (int i = 0; i < N; i++) {
			if (i) printf(" ");
			printf("1");
		}
		printf("\n");
		return 0;
	}
	printf("2\n");
	for (int i = 2; i <= N + 1; i++) {
		if (i != 2) printf(" ");
		if (isPrime(i)) printf("1");
		else printf("2");
	}
	printf("\n");
}