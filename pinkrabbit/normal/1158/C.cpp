#include <cstdio>
#include <vector>

const int MN = 500005;

int N, p[MN], d[MN], a[MN], que[MN], l, r;
std::vector<int> G[MN];

bool check(int L, int R) {
	// printf(" # %d %d\n", L, R);
	for (int i = L + 1; i < R; ) {
		if (p[i] == -1) {
			if (L) G[L].push_back(i), ++d[i];
			++i;
		}
		else if (p[i] > R) return 1;
		else if (check(i, p[i])) return 1;
		else {
			if (L) G[L].push_back(i), ++d[i];
			i = p[i];
		}
	} return 0;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) scanf("%d", &p[i]);
		int ok = 1;
		for (int i = 1; i <= N; ++i) if (p[i] != -1 && p[i] <= i) { ok = 0; continue; }
		if (!ok) { puts("-1"); continue; }
		for (int i = 1; i <= N; ++i) G[i].clear(), d[i] = 0;
		if (check(0, N + 1)) { puts("-1"); continue; }
		for (int i = 1; i <= N; ++i) if (p[i] != -1 && p[i] != N + 1) G[p[i]].push_back(i), ++d[i];
		l = 1, r = 0;
		for (int i = 1; i <= N; ++i) if (d[i] == 0) que[++r] = i;
		while (l <= r) {
			int u = que[l];
			a[u] = N - l++ + 1;
			for (auto v : G[u])
				if (--d[v] == 0)
					que[++r] = v;
		}
		if (r != N) { puts("-1"); continue; }
		for (int i = 1; i <= N; ++i) printf("%d%c", a[i], " \n"[i == N]);
	}
	return 0;
}