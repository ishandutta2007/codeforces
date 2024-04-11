#include <bits/stdc++.h>

#define __ __attribute__ ((optimize ("-Ofast")))
#define _ __ __inline __attribute__ ((__gnu_inline__, __always_inline__, __artificial__))
int W, N, M;
int cnt[1 << 12];
int pre[1 << 24];
int mask[1 << 12];
char gate[100];
int tr[1000];
int trm[6][2] = {{0, 3}, {-1, 0}, {1, 0}, {1, -1}, {3, 1}, {0, 1}};

__ int main () {
	scanf ("%d%d%d", &W, &N, &M);
	for (int i = 0; i < N; ++i) {
		int u; scanf ("%d ", &u); cnt[u]++;
	}
	for (int i = 0; i < 1 << W; ++i) for (int j = 0; j < W; ++j) if (i >> j & 1) mask[i] |= 3 << j * 2;
	for (int i = 0; i < 1 << W; ++i) {
		int pop = 0;
		for (int j = 0; j < W; ++j) if (i >> j & 1) pop |= 1 << j * 2;
		for (int j = 0; j < 1 << W; ++j) pre[pop | mask[j]] += cnt[i]; //, printf (": %d\n", pop | mask[j]);
	}
	tr['A'] = 0;
	tr['O'] = 1;
	tr['X'] = 2;
	tr['a'] = 3;
	tr['o'] = 4;
	tr['x'] = 5;
	for (int tt = 0; tt < M; ++tt) {
		scanf (" %s", gate);
		std::reverse (gate, gate + W);
		int res = 0;
		for (int u = 0; u < 1 << W; ++u) if (cnt[u]) {
			int pop = 0, ok = 1;
			for (int i = 0; i < W; ++i) {
				int a = trm[tr[gate[i]]][(u >> i & 1) ^ 1];
				if (a == -1) { ok = 0; break; }
				pop |= a << i * 2;
			}
			if (ok) res += cnt[u] * pre[pop];
		}
/*
		for (int u = 0; u < 1 << W; ++u) {
			int ok = 1;
			for (int i = 0; i < W; ++i) {
				if ((gate[i] == 'A' || gate[i] == 'O' || gate[i] == 'x') && (u >> i & 1)) ok = 0;
				else if ((gate[i] == 'a' || gate[i] == 'o' || gate[i] == 'x') && !(u >> i & 1)) ok = 0;
			}
			if (ok) res -= cnt[u] * (cnt[u] - 1);
		}
*/
		printf ("%d\n", res);
	}
}