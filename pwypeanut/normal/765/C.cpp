#include <bits/stdc++.h>
using namespace std;

int K, A, B;

int main() {
	scanf("%d%d%d", &K, &A, &B);
	int sa = A / K, sb = B / K;
	if (sa >= 1 && sb >= 1) {
		printf("%d\n", sa + sb);
	} else if (sa == 0 && sb == 0) {
		printf("-1\n");
	} else if (sa == 0) {
		// B must be a multiple of K
		if (B % K == 0) printf("%d\n", sb);
		else printf("-1\n");
	} else {
		if (A % K == 0) printf("%d\n", sa);
		else printf("-1\n");
	}
}