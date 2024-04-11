#include <bits/stdc++.h>
using namespace std;

int N;
string S;
int A[105], B[105];

int main() {
	scanf("%d", &N);
	cin >> S;
	for (int i = 0; i < N; i++) scanf("%d%d", &A[i], &B[i]);
	int ans = 0;
	for (int t = 0; t <= 10000; t++) {
		int on = 0;
		for (int i = 0; i < N; i++) {
			if (t < B[i]) {
				if (S[i] == '1') on++;
			} else {
				int val = (t - B[i]) / A[i];
				if (S[i] == '1' && val % 2 == 1) on++;
				if (S[i] == '0' && val % 2 == 0) on++;
			}
		}
		//if (on == 3) printf("%d\n", t);
		ans = max(ans, on);
	}
	printf("%d\n", ans);
}