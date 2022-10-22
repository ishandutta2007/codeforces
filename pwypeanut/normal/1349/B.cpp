#include <bits/stdc++.h>
using namespace std;

int T, N, K, A[100005], pref[100005];
int mnp[100005], mxs[100005];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; i++) scanf("%d", &A[i]);
		if (N == 1) {
			if (A[0] == K) printf("yes\n");
			else printf("no\n");
			continue;
		}
		bool findK = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] >= K) pref[i] = 1;
			else pref[i] = -1;
			if (A[i] == K) findK = 1;
		}
		for (int i = 1; i < N; i++) pref[i] += pref[i - 1];
		mnp[0] = min(0, pref[0]);
		for (int i = 1; i < N; i++) {
			mnp[i] = min(mnp[i - 1], pref[i]);
		}
		mxs[N - 1] = pref[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			mxs[i] = max(mxs[i + 1], pref[i]);
		}
		bool win = 0;
		for (int i = 0; i < N; i++) {
			if (i > 0) {
				if (pref[i] - ((i == 1) ? 0 : mnp[i - 2]) > 0) {
					win = 1;
					break;
				}
			}
			if (i < N - 1) {
				if (mxs[i + 1] - ((i == 0) ? 0 : pref[i - 1]) > 0) {
					win = 1;
					break;
				}
			}
		}
		if (win && findK) printf("yes\n");
		else printf("no\n");
	}
}