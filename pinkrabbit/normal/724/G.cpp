#include <cstdio>
#include <cstring>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 100005;
const int MM = 400005;

int N, M;
int h[MN], nxt[MM], to[MM], tot; LL w[MM];
inline void ins(int x, int y, LL z) { nxt[++tot] = h[x], to[tot] = y, w[tot] = z, h[x] = tot; }

LL B[60]; int C;
inline void Add(LL x) {
	for (int j = 59; ~j; --j) if (x >> j & 1)
		if (!B[j]) { B[j] = x, ++C; break; }
		else x ^= B[j];
}

bool vis[MN];
LL d[MN];
int s[MN], t;

void DFS(int u, LL v) {
	vis[u] = 1, d[u] = v, s[++t] = u;
	for (int i = h[u]; i; i = nxt[i]) {
		if (vis[to[i]]) Add(v ^ d[to[i]] ^ w[i]);
		else DFS(to[i], v ^ w[i]);
	}
}

LL Ans;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		int x, y; LL z;
		scanf("%d%d%lld", &x, &y, &z);
		ins(x, y, z); ins(y, x, z);
	}
	for (int i = 1; i <= N; ++i) if (!vis[i]) {
		memset(B, 0, sizeof B), C = t = 0;
		DFS(i, 0);
		for (int j = 0; j < 60; ++j) {
			LL c = (1ll << j) % Mod;
			bool ok = 0;
			for (int k = 0; k < 60; ++k) if (B[k] >> j & 1) ok = 1;
			if (ok) Ans = (Ans + (LL)t * (t - 1) / 2 % Mod * ((1ll << C - 1) % Mod) % Mod * c) % Mod;
			else {
				int x = 0;
				for (int i = 1; i <= t; ++i) if (d[s[i]] >> j & 1) ++x;
				Ans = (Ans + (LL)x * (t - x) % Mod * ((1ll << C) % Mod) % Mod * c) % Mod;
			}
		}
	}
	printf("%d\n", (LL)Ans % Mod);
	return 0;
}