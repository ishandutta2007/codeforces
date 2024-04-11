#include <cstdio>
#include <cstring>
#include <algorithm>

int N, Ans;
int A[105];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
	for (int j = 1; j <= N; j <<= 1) {
		for (int i = 0; i < N; i += j) {
			int ok = 1;
			for (int k = 1; k < j; ++k)
				if (A[i + k] < A[i + k - 1])
					ok = 0;
			if (ok) Ans = std::max(Ans, j);
		}
	}
	printf("%d\n", Ans);
	return 0;
}