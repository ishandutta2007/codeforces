#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
	int sq = sqrt(x);
	for (int i = 2; i <= sq; i++) if (x % i == 0) return false;
	return true;
}

int main() {
	long long N;
	scanf("%lld", &N);
	if (N == 2) {
		printf("1\n");
	} else if (N % 2 == 0) {
		printf("2\n");
	} else if (N == 3) {
		printf("1\n"); // 3
	} else if (N == 5) {
		printf("1\n");
	} else if (N == 7) printf("1\n");
	else {
		// max 3
		if (isPrime(N)) printf("1\n");
		else if (isPrime(N - 2)) printf("2\n");
		else printf("3\n");
	}
}