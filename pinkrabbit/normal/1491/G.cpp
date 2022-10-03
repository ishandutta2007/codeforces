#include <cstdio>
#include <vector>

const int MN = 200005;

int N, A[MN], vis[MN], M;
std::vector<int> V[MN];

int tAns, Ans[MN][2];
inline void Add(int x, int y) {
	++tAns, Ans[tAns][0] = x, Ans[tAns][1] = y;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) if (A[i] != i && !vis[i]) {
		++M;
		V[M].push_back(i), vis[i] = 1;
		for (int x = A[i]; x != i; x = A[x])
			V[M].push_back(x), vis[x] = 1;
	}
	while (M >= 2) {
		auto &v1 = V[M];
		auto &v2 = V[M - 1];
		int s1 = (int)v1.size();
		int s2 = (int)v2.size();
		Add(v1[0], v2[0]);
		for (int i = 1; i < s1; ++i)
			Add(v2[0], v1[i]);
		for (int i = 1; i < s2; ++i)
			Add(v1[0], v2[i]);
		Add(v1[0], v2[0]);
		M -= 2;
	}
	if (M) {
		auto &v = V[1];
		int s = (int)v.size();
		if (s == 2) {
			int p = 0;
			if (!p && v[0] != 1 && v[1] != 1) p = 1;
			if (!p && v[0] != 2 && v[1] != 2) p = 2;
			if (!p && v[0] != 3 && v[1] != 3) p = 3;
			Add(v[0], p);
			Add(v[1], p);
			Add(v[0], p);
		} else {
			Add(v[0], v[1]);
			Add(v[1], v[2]);
			for (int i = 3; i < s; ++i)
				Add(v[1], v[i]);
			Add(v[0], v[2]);
			Add(v[0], v[1]);
		}
	}
	printf("%d\n", tAns);
	for (int i = 1; i <= tAns; ++i)
		printf("%d %d\n", Ans[i][0], Ans[i][1]);
	return 0;
}