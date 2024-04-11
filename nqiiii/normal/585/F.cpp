#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int m, d, n;
char s[1010], x[1010], y[1010];
int f[60][25010];
int a[60], ans;

namespace acm {
	const int maxc = 25000;
	int ch[maxc + 10][10], ndcnt;
	int nxt[maxc + 10];
	bool is[maxc + 10];

	void insert(char *s, int l) {
		int p = 0;
		for (int i = 1; i <= l; ++i) {
			int d = s[i] - '0';
			if (!ch[p][d]) ch[p][d] = ++ndcnt;
			p = ch[p][d];
		}
		is[p] = 1;
	}

	void build() {
		static queue<int> q;
		for (int i = 0; i < 10; ++i)
			if (ch[0][i]) q.push(ch[0][i]);
		while (!q.empty()) {
			int p = q.front(); q.pop();
			is[p] |= is[nxt[p]];
			for (int i = 0; i < 10; ++i)
				if (ch[p][i]) {
					nxt[ch[p][i]] = ch[nxt[p]][i];
					q.push(ch[p][i]);
				} else ch[p][i] = ch[nxt[p]][i];
		}
		for (int i = 1; i <= ndcnt; ++i)
			if (is[i]) {
				for (int j = 0; j < 10; ++j)
					ch[i][j] = i;
			}
	}
}

void init(char *s) {
	for (int i = 1; i <= d; ++i) a[i] = s[i] - '0';
	reverse(a + 1, a + d + 1);
}

void dec1() {
	--a[1];
	for (int i = 1; a[i] < 0; ++i) {
		a[i] += 10; --a[i + 1];
	}
}

int dfs(int p, int s, bool lim) {
	if (!p) return acm::is[s];
	if (!lim && f[p][s] != -1) return f[p][s];
	int mx = lim ? a[p] : 9, ans = 0;
	for (int i = 0; i <= mx; ++i)
		(ans += dfs(p - 1, acm::ch[s][i], lim && i == mx)) %= mod;
	if (!lim) f[p][s] = ans;
	return ans;
}

int main() {
	scanf("%s", s + 1); m = strlen(s + 1);
	scanf("%s", x + 1); d = strlen(x + 1);
	scanf("%s", y + 1); 
	n = d / 2;
	for (int i = 1; i + n - 1 <= m; ++i) 
		acm::insert(s + i - 1, n);
	acm::build();
	memset(f, -1, sizeof f);
	init(x); dec1(); ans = dfs(d, 0, 1);
	init(y); 
	printf("%d", (dfs(d, 0, 1) - ans + mod) % mod);
}