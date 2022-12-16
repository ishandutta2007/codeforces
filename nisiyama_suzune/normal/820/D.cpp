#include <bits/stdc++.h>

const int offset = 11E5;
int N;
int leftcnt[2400000], rightcnt[2400000];
int A[1100000];
int best = 0;
long long bans = 0;
long long ans = 0;

int main () {
	scanf ("%d", &N);
	long long cur = 0; 
	for (int i = 1; i <= N; ++i) {
		scanf ("%d", &A[i]);
		ans += abs (i - A[i]);
		cur += (A[i] <= i) ? 1 : -1;
		++leftcnt[A[i] - i + offset];
	}
//	printf ("%lld\n", cur);
	best = 0;
	bans = ans;
	for (int i = 1; i <= N - 1; ++i) {
		ans += cur;
		ans = ans - (N + 1 - A[N + 1 - i]) + A[N + 1 - i] - 1;
		--leftcnt[A[N + 1 - i] - (N + 1 - i) + offset];
		++rightcnt[A[N + 1 - i] - (N + 1 - i) + offset];
		cur -= 2;
//		printf ("cur = %lld\n", cur);
		cur += leftcnt[i + offset] * 2;
		cur += rightcnt[i - N + offset] * 2;
//		printf ("cur = %lld\n", cur);
//		printf ("%lld %lld\n", cur, ans);
		if (bans > ans) {
			best = i;
			bans = ans;
		}
	}
	printf ("%lld %d\n", bans, best);
}