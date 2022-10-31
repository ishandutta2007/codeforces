#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int ceil_div(int a, int b) {
	return (a <= 0) ? 0 : (a + b - 1) / b;
}

void doit(int n, int m) {
	vector<int> x(n);
	vector<int> y(n);
	vector<int> z(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		z[i] = x[i] + y[i];
	}
	const int M = 500;
	vector<int> d(m);
	vector<int> s(n, -1);
	vector<vector<int>> g(M);
	for (int i = 1; i < M; ++i) {
		g[i] = vector<int>(i);
	}
	int total = 0;
	int cur = 0;
	for (int t = 0; t < m; t++) {
		int op, k;
		cin >> op >> k;
		--k;
		if (op == 1) {
			assert(s[k] == -1);
			s[k] = t;
			++total;
			if (z[k] >= M) {
				for (int w1 = s[k]; w1 < m; w1 += z[k]) {
					++d[w1];
				}
				for (int w2 = s[k] + x[k]; w2 < m; w2 += z[k]) {
					--d[w2];
				}
			}
			else {
				++g[z[k]][s[k] % z[k]];
				--g[z[k]][(s[k] + x[k]) % z[k]];
			}
		}
		else {
			assert(s[k] >= 0);
			--total;
			if ((t - s[k] - 1) % z[k] < x[k]) {
				--cur;
			}
			if (z[k] >= M) {
				int w1 = s[k] + ceil_div(t - s[k], z[k]) * z[k];
				for (; w1 < m; w1 += z[k]) {
					--d[w1];
				}
				int w2 = (s[k] + x[k]) + ceil_div(t - (s[k] + x[k]), z[k]) * z[k];
				for (; w2 < m; w2 += z[k]) {
					++d[w2];
				}
			}
			else {
				--g[z[k]][s[k] % z[k]];
				++g[z[k]][(s[k] + x[k]) % z[k]];
			}
			s[k] = -1;
		}
		cur += d[t];
		for (int i = 1; i < M; ++i) {
			cur += g[i][t % i];
		}
		printf("%d\n", total - cur);
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		doit(n, m);
	}
	return 0;
}