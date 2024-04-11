#include <bits/stdc++.h>
using namespace std;

int T, A, B, N;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &A, &B, &N);
		int ans = 1000000000, cur = 0;
		while (1) {
			if (A > N || B > N) {
				ans = min(ans, cur);
				break;
			}
			int timesB = (N + 1 - A + B - 1) / B;
			int timesA = (N + 1 - B + A - 1) / A;
			ans = min(ans, min(cur + timesB, cur + timesA));
			if (A > B) {
				B += A;
			} else A += B;
			cur++;
		}
		printf("%d\n", ans);
	}
}