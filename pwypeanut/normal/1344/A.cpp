#include <bits/stdc++.h>
using namespace std;

int T, N, A[200005], in[200005];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) in[i] = 0;
		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		for (int i = 0; i < N; i++) {
			in[(((i + A[i]) % N) + N) % N]++;
		}
		bool fail = 0;
		for (int i = 0; i < N; i++) {
			if (in[i] != 1) {
				fail = 1;
				break;
			}
		}
		if (fail) printf("NO\n");
		else printf("YES\n");
		
	}
}