#include <bits/stdc++.h>
using namespace std;

char S[1000005];
int wows_left[1000005], wows_right[1000005];

int main() {
	scanf("%s", &S);
	int N = strlen(S);
	int curv = 0, cursum = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'v') {
			curv++;
		} else {
			cursum += max(0, curv - 1);
			wows_left[i] = cursum;
			curv = 0;
		}
	}
	curv = 0;
	cursum = 0;
	for (int i = N-1; i >= 0; i--) {
		if (S[i] == 'v') {
			curv++;
		} else {
			cursum += max(0, curv - 1);
			wows_right[i] = cursum;
			curv = 0;
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (long long)wows_left[i] * wows_right[i];
	}
	printf("%lld\n", ans);
}