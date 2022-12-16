#include <bits/stdc++.h>

int N, K;
int H[210000];
int cnt[210000];

int main () {
	scanf ("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf ("%d", &H[i]);
	for (int i = 0; i < N; ++i) ++cnt[H[i]];
	int res = 0, tot = 0, cur = 0;
	for (int i = 200000; i >= 0 && tot < N; --i) {
		if (cur + tot > K) { cur = tot; ++res; }
		else cur += tot;
		tot += cnt[i];
	}
	if (cur) ++res;
	printf ("%d\n", res);
}