#include <bits/stdc++.h>
using namespace std;

int TC, N, A[55];

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		
		long long sum = 0;
		for (int i = 0; i < N; i++) sum += A[i];
		if (sum == 0) printf("NO\n");
		else if (sum < 0) {
			sort(A, A + N);
			printf("YES\n");
			for (int i = 0; i < N; i++) {
				if (i) printf(" ");
				printf("%d", A[i]);
			}
			printf("\n");
		} else {
			sort(A, A + N, greater<int>());
			printf("YES\n");
			for (int i = 0; i < N; i++) {
				if (i) printf(" ");
				printf("%d", A[i]);
			}
			printf("\n");
		}
		
		
	}
}