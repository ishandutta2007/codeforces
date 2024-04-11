#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

const int V = 1000000;
const int MV = V + 5;
const int MP = 78499;

bool ip[MV];
int p[MP], pc;
std::vector<int> pr[MV];
void Sieve(int N) {
	for (int i = 2; i <= N; ++i) {
		if (!ip[i]) p[++pc] = i;
		for (int j = 1, k; j <= pc; ++j) {
			if ((k = p[j] * i) > N) break;
			ip[k] = 1;
		}
	}
	for (int j = 1; j <= pc; ++j) {
		int x = p[j];
		for (int y = x; y <= N; y += x)
			pr[y].push_back(j);
	}
}

const int MN = 150005;
const int MM = 228505;

int N, Q, A[MN];

int pa[MM];
int fp(int x) {
	return pa[x] ? pa[x] = fp(pa[x]) : x;
}

bool vis[MN];
int bel[MN], cnt;
std::vector<int> V1[MN], V2[MN];
std::map<int, int> Ans[MN];

inline bool checkIntersect(std::vector<int> &v1, std::vector<int> &v2) {
	if (v1.size() <= v2.size()) {
		for (const int &x : v1)
			if (std::binary_search(v2.begin(), v2.end(), x))
				return true;
	} else {
		for (const int &x : v2)
			if (std::binary_search(v1.begin(), v1.end(), x))
				return true;
	}
	return false;
}

int main() {
	Sieve(V + 1);
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		for (int x : pr[A[i]]) {
			if (fp(N + x) != i)
				pa[fp(N + x)] = i;
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (!vis[fp(i)])
			vis[fp(i)] = true,
			bel[fp(i)] = ++cnt;
		bel[i] = bel[fp(i)];
	}
	for (int i = 1; i <= N; ++i) {
		for (int x : pr[A[i]])
			V1[bel[i]].push_back(x);
		for (int x : pr[A[i] + 1])
			V2[bel[i]].push_back(x);
	}
	for (int i = 1; i <= cnt; ++i) {
		std::sort(V1[i].begin(), V1[i].end());
		auto it1 = std::unique(V1[i].begin(), V1[i].end());
		V1[i].erase(it1, V1[i].end());
		std::sort(V2[i].begin(), V2[i].end());
		auto it2 = std::unique(V2[i].begin(), V2[i].end());
		V2[i].erase(it2, V2[i].end());
	}
//	for (int i = 1; i <= N; ++i)
//		printf("bel[%d] = %d\n", i, bel[i]);
//	for (int i = 1; i <= cnt; ++i) {
//		printf("V1[%d] = ", i);
//		for (int x : V1[i]) printf("%d, ", x);
//		puts("");
//		printf("V2[%d] = ", i);
//		for (int x : V2[i]) printf("%d, ", x);
//		puts("");
//	}
	for (int i = 1; i <= N; ++i) {
		std::vector<int> &v = pr[A[i] + 1];
		int len = (int)v.size();
		for (int p1 = 0; p1 <= len - 2; ++p1) if (fp(N + v[p1]) <= N)
			for (int p2 = p1 + 1; p2 <= len - 1; ++p2) if (fp(N + v[p2]) <= N) {
				int b1 = bel[fp(N + v[p1])], b2 = bel[fp(N + v[p2])];
				if (b1 != b2) {
					if (b1 > b2) std::swap(b1, b2);
					Ans[b1][b2] = 1;
				}
			}
	}
	for (int q = 1; q <= Q; ++q) {
		int u, v;
		scanf("%d%d", &u, &v);
		u = bel[u], v = bel[v];
		if (u == v) {
			puts("0");
			continue;
		}
		if (V1[u][0] == 1 || V1[v][0] == 1) {
			puts("1");
			continue;
		}
		if (u > v) std::swap(u, v);
		if (Ans[u][v]) {
			printf("%d\n", Ans[u][v]);
			continue;
		}
		if (checkIntersect(V1[u], V2[v])) {
			Ans[u][v] = 1;
			puts("1");
			continue;
		}
		if (checkIntersect(V1[v], V2[u])) {
			Ans[u][v] = 1;
			puts("1");
			continue;
		}
		Ans[u][v] = 2;
		puts("2");
	}
	return 0;
}