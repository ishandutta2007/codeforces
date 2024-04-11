#include <bits/stdc++.h>

int A[110][110];

int main () {
	int N;
	scanf ("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf ("%d", &A[i][j]);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (A[i][j] > 1) {
				for (int k = 0; k < N; ++k)
					for (int l = 0; l < N; ++l)
						if (A[i][j] == A[i][k] + A[l][j])
							goto next;
				puts ("No");
				return 0;
next:;
			}
	puts ("Yes");
	return 0;
}