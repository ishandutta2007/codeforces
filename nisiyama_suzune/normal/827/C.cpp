#include <bits/stdc++.h>

std::string S;
int Q;

int a[4][11][10][110000];

int tr (char c) {
	if (c == 'A') return 0;
	else if (c == 'T') return 1;
	else if (c == 'C') return 2;
	return 3;
}

int lowbit (int x) { return x & (-x); }

void add (int e, int x, int d) {
	for (int i = 1; i <= 10; ++i) {
		int l = x % i, t = x;
		while (t < 110000) {
			a[e][i][l][t] += d;
			t += lowbit (t);
		}
	}
}

int query (int e, int len, int mod, int x) {
	int ans = 0;
	while (x > 0) {
		ans += a[e][len][mod][x];
		x -= lowbit (x);
	}
	return ans;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	std::cin >> S;
	for (int i = 0; i < S.size (); ++i) 
		add (tr (S[i]), i + 1, 1);
	std::cin >> Q;
	for (int q = 0; q < Q; ++q) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int x;
			char c;
			std::cin >> x >> c;
			add (tr (S[x - 1]), x, -1);
			add (tr (c), x, 1);
			S[x - 1] = c;
		} else {
			int l, r;
			std::string str;
			std::cin >> l >> r >> str;
			int ans = 0;
			for (int i = 0; i < str.size (); ++i) {
//				printf ("%d %d %d %d\n", tr (str[i]), str.size (), (l + i) % str.size (), r);
				ans += query (tr (str[i]), str.size (), (l + i) % str.size (), r) - query (tr (str[i]), str.size (), (l + i) % str.size (), l - 1);
			}
			printf ("%d\n", ans);
		}
	}
}