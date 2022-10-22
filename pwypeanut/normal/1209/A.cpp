#include <bits/stdc++.h>
using namespace std;

int N, A[105], val[105];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A+N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (val[j] == 0) {
				val[j] = A[i];
				ans++;
				break;
			} else if (A[i] % val[j] == 0) {
				break;
			}
		}
	}
	printf("%d\n", ans);
}