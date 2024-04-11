#include <bits/stdc++.h>

int N;
int A[210000];
int B[210000];

int main () {
	scanf ("%d", &N);
	for (int i = 1; i <= N; ++i) scanf ("%d", &A[i]);
	for (int i = 1; i <= N; ++i) scanf ("%d", &B[i]);
	int ans = 0;
	for (int i = 1; i <= N; ++i) if (B[i] == 1) {
		bool ok = true;
		for (int j = 0; i + j <= N; ++j) if (B[i + j] != j + 1) ok = false;
		if (ok) {
			bool pos = true;
			for (int j = 1; j <= i - 1; ++j) if (B[j] != 0)
				if (j - B[j] + 1 + N > i - 1) pos = false;
			if (pos) { printf ("%d\n", i - 1); return 0; }
		}
	}
	for (int i = 1; i <= N; ++i) if (B[i] != 0) ans = std::max (ans, i - B[i] + 1);
	printf ("%d\n", ans + N);
	return 0;
}