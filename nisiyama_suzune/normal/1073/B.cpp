#include <bits/stdc++.h>

int N;
int A[210000], B[210000];

int main () {
	scanf ("%d", &N);
	for (int i = 1; i <= N; ++i) { int u; scanf ("%d", &u); A[u] = i; }
	for (int i = 1; i <= N; ++i) scanf ("%d", &B[i]);
	for (int i = 1, cur = 0; i <= N; ++i) {
		if (A[B[i]] > cur) {
			printf ("%d ", A[B[i]] - cur); cur = A[B[i]];
		} else {
			printf ("0 ");
		}
	}
}