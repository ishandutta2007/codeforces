#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int ML = 1005, MZ = 55, MN = 50005, Sig = 10;

char s[ML], a[MZ], b[MZ]; int len, d;

int ch[MN][Sig], key[MN], fail[MN], cnt;
void BuildAC() {
	static int que[MN], l, r;
	fail[0] = -1, que[l = r = 1] = 0;
	while (l <= r) {
		int u = que[l++];
		for (int j = 0; j < Sig; ++j) {
			int v = u ? ch[fail[u]][j] : 0;
			if (ch[u][j]) fail[ch[u][j]] = v, que[++r] = ch[u][j];
			else ch[u][j] = v;
		}
	}
}

LL DP(char *V) {
	static int A[MZ];
	for (int i = 1; i <= d; ++i) A[i] = V[d - i + 1] - '0';
	static int f[MN], g[MN];
	LL S = 0;
	for (int u = 0; u <= cnt; ++u) f[u] = 0;
	int now = 0, o = 1;
	for (int i = d; i >= 1; --i) {
		for (int u = 0; u <= cnt; ++u) g[u] = 0;
		for (int u = 0; u <= cnt; ++u)
			for (int j = 0; j < Sig; ++j)
				if (!key[ch[u][j]]) (g[ch[u][j]] += f[u]) %= Mod;
		for (int j = 0; j < A[i]; ++j)
			if (!key[ch[now][j]]) g[ch[now][j]] += o;
		now = ch[now][A[i]];
		o &= key[now] ^ 1;
		S = (S * 10ll + A[i]) % Mod;
		std::swap(f, g);
	}
	for (int u = 0; u <= cnt; ++u) S -= f[u];
	return ((S - o) % Mod + Mod) % Mod;
}

int main() {
	scanf("%s%s%s", s + 1, a + 1, b + 1), len = strlen(s + 1), d = strlen(b + 1);
	for (int i = 1; i <= len - d / 2 + 1; ++i) {
		int now = 0;
		for (int j = 0; j < d / 2; ++j) {
			int c = s[i + j] - '0';
			if (!ch[now][c]) ch[now][c] = ++cnt;
			now = ch[now][c];
		} key[now] = 1;
	}
	BuildAC();
	int pos = d;
	while (a[pos] == '0') --pos; --a[pos];
	for (int i = d; i > pos; --i) a[i] = '9';
	printf("%lld\n", (DP(b) - DP(a) + Mod) % Mod);
	return 0;
}