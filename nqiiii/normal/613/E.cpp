#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000, mod1 = 919260817, mod2 = 998244353, base = 131, mod = 1e9 + 7;
char s[2][maxn + 10], t[maxn + 10];
int f[2][maxn + 10][maxn + 10], g[2][maxn + 10][maxn + 10];
int pw1[maxn + 10], pw2[maxn + 10];
int n, ans, ext, l;

void hashinit() {
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= maxn; ++i) {
		pw1[i] = 1ll * pw1[i - 1] * base % mod1;
		pw2[i] = 1ll * pw2[i - 1] * base % mod2;
	}
}


struct hashs {
	int hsh1[maxn + 10], rhsh1[maxn + 10];
	int hsh2[maxn + 10], rhsh2[maxn + 10];

	void init() {
		memset(hsh1, 0, sizeof hsh1);
		memset(hsh2, 0, sizeof hsh2);
		memset(rhsh1, 0, sizeof rhsh1);
		memset(rhsh2, 0, sizeof rhsh2);
	}

	void build(char *s) {
		int n = strlen(s + 1);
		for (int i = n; i >= 1; --i) {
			hsh1[i] = (1ll * hsh1[i + 1] * base + s[i]) % mod1;
			hsh2[i] = (1ll * hsh2[i + 1] * base + s[i]) % mod2;
		}
		for (int i = 1; i <= n; ++i) {
			rhsh1[i] = (1ll * rhsh1[i - 1] * base + s[i]) % mod1;
			rhsh2[i] = (1ll * rhsh2[i - 1] * base + s[i]) % mod2;
		}
	}

	pair<int, int> gethash(int l, int r) {
		int ans1 = (hsh1[l] - 1ll * hsh1[r + 1] * pw1[r - l + 1] % mod1 + mod1) % mod1;
		int ans2 = (hsh2[l] - 1ll * hsh2[r + 1] * pw2[r - l + 1] % mod2 + mod2) % mod2;
		return make_pair(ans1, ans2);
	}

	pair<int, int> getrhash(int l, int r) {
		int ans1 = (rhsh1[r] - 1ll * rhsh1[l - 1] * pw1[r - l + 1] % mod1 + mod1) % mod1;
		int ans2 = (rhsh2[r] - 1ll * rhsh2[l - 1] * pw2[r - l + 1] % mod2 + mod2) % mod2;
		return make_pair(ans1, ans2);
	}
}sh[2], th;

int main() {
	scanf("%s%s%s", s[0] + 1, s[1] + 1, t + 1);
	n = strlen(s[0] + 1); l = strlen(t + 1);

	if (l == 1) {
		for (int i = 1; i <= n; ++i) {
			if (s[0][i] == t[1]) ++ans;
			if (s[1][i] == t[1]) ++ans;
		}
		printf("%d", ans); return 0;
	}

	if (l == 2) {
		for (int i = 1; i <= n; ++i) {
			if (s[0][i] == t[1] && s[1][i] == t[2]) ++ans;
			if (s[1][i] == t[1] && s[0][i] == t[2]) ++ans;
		}
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < 2; ++j) {
				if (s[j][i] == t[1] && s[j][i + 1] == t[2]) ++ans;
				if (s[j][i + 1] == t[1] && s[j][i] == t[2]) ++ans;
			}
		printf("%d", ans); return 0;
	}

	hashinit();
	sh[0].build(s[0]); sh[1].build(s[1]);
	th.build(t);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k * 2 <= l && k <= i; ++k)
				if (k != 1 && sh[j ^ 1].getrhash(i - k + 1, i) == th.gethash(1, k) && sh[j].gethash(i - k + 1	, i) == th.gethash(k + 1, k * 2)) {
					++g[j][i][k * 2];
					if (k * 2 == l) ++ext;
				}
		}
		for (int j = 0; j < 2; ++j)
			for (int k = 1; k <= l; ++k)
				if (s[j][i] == t[k]) {
					(f[j][i][k] += f[j][i - 1][k - 1]) %= mod;
					(f[j][i][k] += g[j][i - 1][k - 1]) %= mod;
				}
		for (int j = 0; j < 2; ++j)
			for (int k = 1; k <= l; ++k)
				if (s[j][i] == t[k]) {
					(g[j][i][k] += f[j ^ 1][i][k - 1]) %= mod;
				}
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k * 2 <= l && i + k <= n; ++k)
				if (k != 1 && sh[j].gethash(i + 1, i + k) == th.gethash(l - k * 2 + 1, l - k) && sh[j ^ 1].getrhash(i + 1, i + k) == th.gethash(l - k + 1, l)) {
					if (k * 2 == l) ++ext;
					(ans += f[j][i][l - k * 2]) %= mod;
					(ans += g[j][i][l - k * 2]) %= mod;
				}
		}
	reverse(t + 1, t + l + 1);
	th.init(); th.build(t);
	memset(f, 0, sizeof f); memset(g, 0, sizeof g);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k * 2 <= l && k <= i; ++k)
				if (k != 1 && sh[j ^ 1].getrhash(i - k + 1, i) == th.gethash(1, k) && sh[j].gethash(i - k + 1	, i) == th.gethash(k + 1, k * 2)) {
					++g[j][i][k * 2];
				}
		}
		for (int j = 0; j < 2; ++j)
			for (int k = 1; k <= l; ++k)
				if (s[j][i] == t[k]) {
					(f[j][i][k] += f[j][i - 1][k - 1]) %= mod;
					(f[j][i][k] += g[j][i - 1][k - 1]) %= mod;
				}
		for (int j = 0; j < 2; ++j)
			for (int k = 1; k <= l; ++k)
				if (s[j][i] == t[k]) {
					(g[j][i][k] += f[j ^ 1][i][k - 1]) %= mod;
				}
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k * 2 <= l && i + k <= n; ++k)
				if (k != 1 && sh[j].gethash(i + 1, i + k) == th.gethash(l - k * 2 + 1, l - k) && sh[j ^ 1].getrhash(i + 1, i + k) == th.gethash(l - k + 1, l)) {
					(ans += f[j][i][l - k * 2]) %= mod;
					(ans += g[j][i][l - k * 2]) %= mod;
				}
	}
	printf("%d", (ans - ext + mod) % mod);
}