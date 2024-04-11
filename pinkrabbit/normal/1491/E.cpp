// PinkRabbit
#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 200005;

int Fibs[55], iFibId[MN];
void Init(int N) {
	Fibs[0] = Fibs[1] = 1;
	for (int i = 2; ; ++i) {
		Fibs[i] = Fibs[i - 1] + Fibs[i - 2];
		if (Fibs[i] > N) break;
		iFibId[Fibs[i]] = i;
	}
}

int N;
std::vector<int> G[MN];

int par[MN], ldf[MN], rdf[MN], dfc;
void DFS(int u, int p) {
	par[u] = p;
	ldf[u] = ++dfc;
	for (int v : G[u]) if (v != p) DFS(v, u);
	rdf[u] = dfc;
}

int bit[MN];
inline void bAdd(int i, int x) { for (; i <= N; i += i & -i) bit[i] += x; }
inline int bQur(int i) { int s = 0; for (; i; i -= i & -i) s += bit[i]; return s; }
inline int Qur(int u) { return bQur(rdf[u]) - bQur(ldf[u] - 1); }

std::vector<int> V[35];
bool Solve(int lay) {
	if (lay <= 3) return true;
	int siz = Fibs[lay];
	int csiz1 = Fibs[lay - 1];
	int csiz2 = Fibs[lay - 2];
	for (int i = 0; i < siz; ++i) {
		int u = V[lay][i];
		int sz = Qur(u);
		if (sz == csiz1 || sz == csiz2) {
			int ch1 = (sz == csiz1) ? (lay - 1) : (lay - 2);
			int ch2 = (sz == csiz1) ? (lay - 2) : (lay - 1);
			int lb = ldf[u], rb = rdf[u];
			for (int j = 0; j < siz; ++j) {
				int v = V[lay][j];
				if (lb <= ldf[v] && ldf[v] <= rb)
					V[ch1].push_back(v);
			}
			bool ret = Solve(ch1);
			V[ch1].clear();
			if (ret) {
				bAdd(ldf[par[u]], -sz);
				for (int j = 0; j < siz; ++j) {
					int v = V[lay][j];
					if (ldf[v] < lb || rb < ldf[v])
						V[ch2].push_back(v);
				}
				bool ret2 = Solve(ch2);
				V[ch2].clear();
				bAdd(ldf[par[u]], sz);
				if (ret2) return true;
			}
			break;
		}
	}
	return false;
}

int main() {
	Init(200000);
	scanf("%d", &N);
	if (N <= 3) return puts("YES"), 0;
	if (!iFibId[N]) return puts("NO"), 0;
	for (int i = 1; i <= N - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1, 0);
	for (int i = 1; i <= N; ++i) bAdd(i, 1);
	int lay = iFibId[N];
	for (int i = 1; i <= N; ++i) V[lay].push_back(i);
	puts(Solve(lay) ? "Yes" : "No");
	return 0;
}