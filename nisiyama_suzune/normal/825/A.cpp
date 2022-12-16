#include <bits/stdc++.h>

int N;
char S[10000];

int main () {
	scanf ("%d %s", &N, S);
	int ans = 0, dig = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] == '1') {
			++dig;
		} else {
			ans = ans * 10 + dig;
			dig = 0;
		}
	}
	ans = ans * 10 + dig;
	printf ("%d\n", ans);
	return 0;
}