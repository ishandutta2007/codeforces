#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

const int Inf = 0x3f3f3f3f;
const int MN = 600;
const int MM = 360005;

int N, M;
int b[MM], c[MM];
std::vector<int> G[MN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		int x;
		scanf("%d%d%d", &x, &b[i], &c[i]);
		G[x].push_back(i);
	}
	for (int i = 0; i < N; ++i) {
		static int val[MN], vis[MN];
		for (int j = 0; j < N; ++j) val[j] = Inf, vis[j] = 0;
		for (int e : G[i]) val[b[e]] = c[e];
		for (int k = 1; k <= N; ++k) {
			int p = -1;
			for (int j = 0; j < N; ++j) if (!vis[j])
				p = !~p ? j : val[j] < val[p] ? j : p;
			vis[p] = 1;
			for (int e : G[p]) {
				int &v = val[(b[e] + val[p]) % N];
				v = std::min(v, val[p] + c[e]);
			}
			int &v = val[(p + 1) % N];
			v = std::min(v, val[p] + 1);
		}
		for (int j = 0; j < N; ++j)
			printf("%d%c", j == i ? 0 : val[j], " \n"[j == N - 1]);
	}
	return 0;
}