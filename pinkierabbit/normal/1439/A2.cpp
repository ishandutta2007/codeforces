#include <cstdio>
#include <algorithm>
#include <vector>

#define fi first
#define se second
typedef std::pair<int, int> pii;

const int MN = 105;

int N, M, A[MN][MN];
std::vector<pii> A1, A2, A3;

void Solve(int x, int y) {
	if (x == 2) {
		if (y > 2) {
			if (A[1][y]) {
				if (A[2][y]) {
					A1.push_back({1, y}), A[1][y] ^= 1;
					A2.push_back({2, y}), A[2][y] ^= 1;
					A3.push_back({1, y - 1}), A[1][y - 1] ^= 1;
				} else {
					A1.push_back({1, y}), A[1][y] ^= 1;
					A2.push_back({1, y - 1}), A[1][y - 1] ^= 1;
					A3.push_back({2, y - 1}), A[2][y - 1] ^= 1;
				}
			} else if (A[2][y]) {
				A1.push_back({2, y}), A[2][y] ^= 1;
				A2.push_back({1, y - 1}), A[1][y - 1] ^= 1;
				A3.push_back({2, y - 1}), A[2][y - 1] ^= 1;
			}
			Solve(2, y - 1);
		} else {
			int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
			if (A[1][1]) p2 ^= 1, p3 ^= 1, p4 ^= 1;
			if (A[1][2]) p1 ^= 1, p3 ^= 1, p4 ^= 1;
			if (A[2][1]) p1 ^= 1, p2 ^= 1, p4 ^= 1;
			if (A[2][2]) p1 ^= 1, p2 ^= 1, p3 ^= 1;
			if (p1) {
				A1.push_back({1, 2});
				A2.push_back({2, 1});
				A3.push_back({2, 2});
			}
			if (p2) {
				A1.push_back({1, 1});
				A2.push_back({2, 1});
				A3.push_back({2, 2});
			}
			if (p3) {
				A1.push_back({1, 1});
				A2.push_back({1, 2});
				A3.push_back({2, 2});
			}
			if (p4) {
				A1.push_back({1, 1});
				A2.push_back({1, 2});
				A3.push_back({2, 1});
			}
		}
	} else {
		if (y > 1) {
			if (A[x][y]) {
				A1.push_back({x, y}), A[x][y] ^= 1;
				A2.push_back({x - 1, y}), A[x - 1][y] ^= 1;
				A3.push_back({x, y - 1}), A[x][y - 1] ^= 1;
			}
			Solve(x, y - 1);
		} else {
			if (A[x][1]) {
				A1.push_back({x, 1}), A[x][1] ^= 1;
				A2.push_back({x - 1, 1}), A[x - 1][1] ^= 1;
				A3.push_back({x - 1, 2}), A[x - 1][2] ^= 1;
			}
			Solve(x - 1, M);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= M; ++j)
				scanf("%1d", &A[i][j]);
		A1.clear(), A2.clear(), A3.clear();
		Solve(N, M);
		int len = (int)A1.size();
		printf("%d\n", len);
		for (int j = 0; j < len; ++j)
			printf("%d %d %d %d %d %d\n", A1[j].fi, A1[j].se, A2[j].fi, A2[j].se, A3[j].fi, A3[j].se);
	}
	return 0;
}