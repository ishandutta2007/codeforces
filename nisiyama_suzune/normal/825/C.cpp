#include <bits/stdc++.h>

int N, K;
int A[11000];

int main () {
	scanf ("%d%d", &N, &K);
	for (int i = 0; i < N; ++i)
		scanf ("%d", &A[i]);
	std::sort (A, A + N);
	int ans = 0;
	for (int i = 0; i < N; ++i)
		if (A[i] <= K * 2)
			K = std::max (K, A[i]);
		else {
			while (A[i] > K * 2) {
				++ans;
				K = K * 2;
			}
			K = std::max (K, A[i]);
		}
	printf ("%d\n", ans);
}