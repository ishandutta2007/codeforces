#include <bits/stdc++.h>

std::vector <std::tuple <int, int, int>> op;

int N, X;
int L[210000], R[210000], cost[210000];

int dp[210000];
int ans = -1;

int main () {
	scanf ("%d%d", &N, &X);
	for (int i = 0; i < N; ++i) {
		scanf ("%d%d%d", &L[i], &R[i], &cost[i]);
		op.push_back (std::make_tuple (L[i], 0, i));
		op.push_back (std::make_tuple (R[i], 1, i));
	}
	std::sort (op.begin (), op.end ());
	for (int i = 0; i < op.size (); ++i) {
		int o = std::get <1> (op[i]), ind = std::get <2> (op[i]);
		if (o == 0) {
			int dur = R[ind] - L[ind] + 1, nec = X - dur;
			if (nec < 0 || dp[nec] == 0) continue;
			if (ans == -1 || ans > dp[nec] + cost[ind]) ans = dp[nec] + cost[ind];
		} else {
			int dur = R[ind] - L[ind] + 1;
			if (dp[dur] == 0 || dp[dur] > cost[ind]) dp[dur] = cost[ind];
		}
	}
	printf ("%d\n", ans);
}