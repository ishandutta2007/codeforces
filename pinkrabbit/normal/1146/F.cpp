#include <cstdio>
#include <vector>

typedef long long LL;
const int Mod = 998244353;
const int MN = 200005;

int N, Leaf[MN];
LL f[MN][3];
std::vector<int> G[MN];

void DFS(int u) {
	if (Leaf[u]) f[u][0] = 0, f[u][1] = 0, f[u][2] = 1;
	else f[u][0] = 1, f[u][1] = 0, f[u][2] = 0;
	for (auto v : G[u]) {
		DFS(v);
		f[u][2] = (f[u][2] * (f[v][0] + f[v][2]) + (f[u][1] + f[u][2]) * (f[v][1] + f[v][2])) % Mod;
		f[u][1] = (f[u][1] * (f[v][0] + f[v][2]) + f[u][0] * (f[v][1] + f[v][2])) % Mod;
		f[u][0] = f[u][0] * (f[v][0] + f[v][2]) % Mod;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) Leaf[i] = 1;
	for (int i = 2, x; i <= N; ++i) {
		scanf("%d", &x);
		G[x].push_back(i);
		Leaf[x] = 0;
	}
	DFS(1);
	printf("%lld\n", (f[1][0] + f[1][2]) % Mod);
	return 0;
}