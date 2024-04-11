#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const LL Infll = 0x3f3f3f3f;
const int Mod = 1000000007, Inv2 = (Mod + 1) / 2;
const int MN = 2005, MM = 2005;

int N, M, Q, eu[MM], ev[MM], ew[MM];
int to[MM * 2], wgh[MM * 2], tot;
std::vector<int> G[MN];

LL f[MN][MN], Ans[MN];
LL k[MM], b[MM]; int p[MM];
int stk[MN], tp;
int tAns;

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%d", &eu[i], &ev[i], &ew[i]);
		++tot, to[tot] = ev[i], wgh[tot] = ew[i], G[eu[i]].push_back(tot);
		++tot, to[tot] = eu[i], wgh[tot] = ew[i], G[ev[i]].push_back(tot);
	}
	f[0][1] = 0;
	for (int u = 2; u <= N; ++u) f[0][u] = -Infll;
	for (int i = 1; i < N; ++i) {
		Ans[i] = -Infll;
		for (int u = 1; u <= N; ++u) {
			f[i][u] = -Infll;
			for (int j : G[u])
				f[i][u] = std::max(f[i][u], f[i - 1][to[j]] + wgh[j]);
			Ans[i] = std::max(Ans[i], f[i][u]);
		}
	}
	for (int i = 1; i <= M; ++i) {
		LL val = -Infll;
		for (int j = 0; j < N; ++j)
			val = std::max(val, std::max(f[j][eu[i]], f[j][ev[i]]) - (LL)j * ew[i]);
		k[i] = ew[i], b[i] = val, p[i] = i;
	}
	std::sort(p + 1, p + M + 1, [](int i, int j) { return k[i] == k[j] ? b[i] < b[j] : k[i] < k[j]; });
	k[0] = 0, b[0] = 0;
	stk[tp = 1] = 0;
	for (int i = 1; i <= M; ++i) {
		while (tp >= 2 && (b[stk[tp - 1]] - b[stk[tp]]) * (k[p[i]] - k[stk[tp]]) >= (b[stk[tp]] - b[p[i]]) * (k[stk[tp]] - k[stk[tp - 1]])) --tp;
		stk[++tp] = p[i];
	}
	for (int i = 1; i < N; ++i) tAns = (tAns + Ans[i]) % Mod;
	for (int i = 2; i <= tp; ++i) {
		LL lb = std::max((LL)N, (b[stk[i - 1]] - b[stk[i]]) / (k[stk[i]] - k[stk[i - 1]]) + 1);
		LL rb = i == tp ? Q : std::min((LL)Q, (b[stk[i]] - b[stk[i + 1]]) / (k[stk[i + 1]] - k[stk[i]]));
		if (lb > rb) continue;
		tAns = (tAns + (LL)((lb * k[stk[i]] + b[stk[i]]) + (rb * k[stk[i]] + b[stk[i]])) % Mod * (rb - lb + 1) % Mod * Inv2) % Mod;
	}
	printf("%d\n", tAns);
	return 0;
}