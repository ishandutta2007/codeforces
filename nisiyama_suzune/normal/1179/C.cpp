#include <bits/stdc++.h>

const int LIMIT = 1000010;

int N, M;
long long tr[4 * LIMIT], lz[4 * LIMIT];
int A[400000], B[400000];

void push_down (int n, int l, int r) {
	if (l < r) {
		int m = l + r >> 1;
		tr[n << 1] += lz[n];
		lz[n << 1] += lz[n];
		tr[n << 1 | 1] += lz[n];
		lz[n << 1 | 1] += lz[n];
	}
	lz[n] = 0;
}

void add (int n, int l, int r, int ql, int qr, int d) {
	push_down (n, l, r);
	if (ql <= l && r <= qr) {
		tr[n] += d;
		lz[n] += d;
		return;
	}
	int m = l + r >> 1;
	if (ql <= m) add (n << 1, l, m, ql, qr, d);
	if (m + 1 <= qr) add (n << 1 | 1, m + 1, r, ql, qr, d);
	tr[n] = std::max (tr[n << 1], tr[n << 1 | 1]);
//	printf ("%d %d %d %d %d %d %lld\n", n, l, r, ql, qr, d, tr[n]);
}

int query (int n, int l, int r) {
	push_down (n, l, r);
	if (l == r) return l;
	int m = l + r >> 1;
	if (tr[n << 1 | 1] > 0) return query (n << 1 | 1, m + 1, r);
	return query (n << 1, l, m);
}

int main () {
	scanf ("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf ("%d", &A[i]), add (1, 1, LIMIT, 1, A[i], 1);
	for (int i = 1; i <= M; ++i) scanf ("%d", &B[i]), add (1, 1, LIMIT, 1, B[i], -1);
	int Q; scanf ("%d", &Q);
	for (int i = 1; i <= Q; ++i) {
		int op, ind, nval; scanf ("%d%d%d", &op, &ind, &nval);
		if (op == 1) {
			add (1, 1, LIMIT, 1, A[ind], -1);
			A[ind] = nval;
			add (1, 1, LIMIT, 1, A[ind], 1);
		} else {
			add (1, 1, LIMIT, 1, B[ind], 1);
			B[ind] = nval;
			add (1, 1, LIMIT, 1, B[ind], -1);
		}
//		printf ("%lld\n", tr[1]);
		if (tr[1] <= 0) puts ("-1");
		else printf ("%d\n", query (1, 1, LIMIT));
	}
}