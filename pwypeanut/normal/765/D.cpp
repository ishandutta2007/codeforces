#include <bits/stdc++.h>
using namespace std;

int A[100005], N, ans_a[100005], ans_b[100005];
bool nm[100005];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) {
		if (A[i] != i + 1) {
			nm[i] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		if (nm[i] && nm[A[i] - 1]) {
			printf("-1\n");
			return 0;
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++) sum += !nm[i];
	printf("%d\n", sum);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!nm[i]) {
			ans_a[i] = cnt;
			ans_b[cnt] = i;
			cnt++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (nm[i]) ans_a[i] = ans_a[A[i] - 1];
	}
	for (int i = 0; i < N; i++) {
		if (i) printf(" ");
		printf("%d", ans_a[i] + 1);
	}
	printf("\n");
	for (int i = 0; i < sum; i++) {
		if (i) printf(" ");
		printf("%d", ans_b[i] + 1);
	}
	printf("\n");
	
}