#include <bits/stdc++.h>

const int MAXN = 36000 * 4;

int lazy[MAXN], val[MAXN], ans[MAXN];

void push (int x, int l) {
	val[x] += l;
	lazy[x] += l;
	ans[x] += l;
	return;
}

void push_down (int x, int l, int r) {
	if (l < r) {
		push (x << 1, lazy[x]);
		push ((x << 1) + 1, lazy[x]);
	}
	lazy[x] = 0;
	return;
}

void update (int x, int l, int r) {
	ans[x] = val[x];
	if (l < r) {
		ans[x] = std::max (ans[x], ans[x << 1]);
		ans[x] = std::max (ans[x], ans[(x << 1) + 1]);
	}
	return;
}

void add (int x, int l, int r, int pl, int pr, int d) {
	if (pl <= l && r <= pr) {
		push (x, d);
		return;
	}
	push_down (x, l, r);
	int m = (l + r) >> 1;
	if (pl <= m)
		add (x << 1, l, m, pl, pr, d);
	if (pr >= m + 1)
		add ((x << 1) + 1, m + 1, r, pl, pr, d);
	update (x, l, r);
}

int query (int x, int l, int r, int pl, int pr) {
	if (pl <= l && pr <= r) 
		return ans[x];
	push_down (x, l, r);
	int m = (l + r) >> 1, an = 0;
	if (pl <= m)
		an = std::max (an, query (x << 1, l, m, pl, pr));
	if (pr >= m + 1)
		an = std::max (an, query ((x << 1) + 1, m + 1, r, pl, pr));
	return an;
}
	
int A[36000];
int prev[36000], tmp[36000];
int dp[60][36000];

int main () {
	int N, K;
	scanf ("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i)
		scanf ("%d", &A[i]);
	for (int i = 1; i <= N; ++i) {
		prev[i] = tmp[A[i]];
		tmp[A[i]] = i;
	}
	for (int i = 1; i <= N; ++i) {
		if (prev[i] == 0)
			dp[1][i] = dp[1][i - 1] + 1;
		else
			dp[1][i] = dp[1][i - 1];
//		printf ("%d %d = %d\n", 1, i, dp[1][i]);
	}
	for (int i = 2; i <= K; ++i) {
		std::fill (lazy, lazy + MAXN, 0);
		std::fill (val, val + MAXN, 0);
		std::fill (ans, ans + MAXN, 0);
		for (int j = 1; j <= N; ++j) {
			if (prev[j] <= j - 1 && j - 1 > 0) add (1, 1, N, prev[j], j - 1, 1);
			dp[i][j] = query (1, 1, N, 1, j);
//			printf ("%d %d = %d\n", i, j, dp[i][j]);
			add (1, 1, N, j, j, dp[i - 1][j]);
		}
	}
	printf ("%d\n", dp[K][N]);
}