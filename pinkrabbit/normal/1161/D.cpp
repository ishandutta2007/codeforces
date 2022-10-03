#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define mp std::make_pair

typedef std::pair<int, int> pii;
const int Mod = 998244353;
const int MN = 1005;

int N;
char str[MN];
std::vector<pii> G[MN * 2];
int ok, c[MN * 2];
int Ans, Sum;

void DFS(int u, int col) {
	if (~c[u]) { if (c[u] != col) ok = 0; return ; }
	c[u] = col;
	for (auto e : G[u]) DFS(e.first, col ^ e.second);
}

int main() {
	scanf("%s", str + 1), N = strlen(str + 1);
	if (N == 1) return puts("0"), 0;
	for (int k = 2; k <= N; ++k) {
		ok = 1, Sum = 1;
		for (int i = 1; i <= N; ++i)
			c[i] = -1, G[i].clear();
		for (int i = N + k; i <= N + N; ++i)
			c[i] = -1, G[i].clear();
		for (int i = 1; i < N - i + 1; ++i)
			G[i].push_back(mp(N - i + 1, 0)),
			G[N - i + 1].push_back(mp(i, 0));
		for (int i = k; i < N - i + k; ++i)
			G[N + i].push_back(mp(N + N - i + k, 0)),
			G[N + N - i + k].push_back(mp(N + i, 0));
		for (int i = k; i <= N; ++i) {
			if (str[i] == '0')
				G[i].push_back(mp(N + i, 0)),
				G[N + i].push_back(mp(i, 0));
			if (str[i] == '1')
				G[i].push_back(mp(N + i, 1)),
				G[N + i].push_back(mp(i, 1));
		}
		for (int i = 1; i < k; ++i) {
			if (str[i] == '?') continue;
			if (!~c[i]) DFS(i, str[i] - '0');
			else if (c[i] != str[i] - '0') ok = 0;
		}
		if (!~c[N + k]) DFS(N + k, 1);
		else if (c[N + k] != 1) ok = 0;
		for (int i = 1; i <= N; ++i) {
			if (~c[i]) continue;
			Sum -= (Sum += Sum) >= Mod ? Mod : 0;
			DFS(i, 0);
		}
		for (int i = N + k; i <= N + N; ++i) {
			if (~c[i]) continue;
			Sum -= (Sum += Sum) >= Mod ? Mod : 0;
			DFS(i, 0);
		}
		if (!ok) Sum = 0;
		Ans -= (Ans += Sum) >= Mod ? Mod : 0;
	}
	printf("%d\n", Ans);
	return 0;
}