#include <bits/stdc++.h>
using namespace std;

int A[1005], B[1005];

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i <N;i++) scanf("%d", &A[i]);
		for (int i = 0; i < N; i++) scanf("%d", &B[i]);
		sort(A, A+N);
		sort(B,B+N);
		for (int i = 0; i < N; i++) {
			if (i) printf(" ");
			printf("%d", A[i]);
		}
		printf("\n");
		for (int i = 0; i < N; i++) {
			if (i) printf(" ");
			printf("%d", B[i]);
		}
		printf("\n");
	}
}