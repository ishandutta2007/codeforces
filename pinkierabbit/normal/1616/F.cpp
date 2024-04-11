#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 75
#define MM 265
#define MT 2505
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

int n, m;
int a[MM], b[MM], c[MM];

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

int rows, A[MT][MM];

bool Gauss() {
	int now = 1;
	F(i, 1, m) {
		int p = 0;
		F(j, now, rows) if (A[j][i]) { p = j; break; }
		if (!p) continue;
		if (p != now)
			F(k, i, m + 1)
				swap(A[now][k], A[p][k]);
		if (A[now][i] == 2)
			F(k, i, m + 1)
				A[now][k] = 2 * A[now][k] % 3;
		F(j, now + 1, rows) {
			int cc = A[j][i];
			F(k, i, m + 1)
				A[j][k] = (A[j][k] - cc * A[now][k] + 6) % 3;
		}
		++now;
		if (now > rows)
			break;
	}
	F(j, now, rows)
		if (A[j][m + 1])
			return false;
	dF(j, now - 1, 1) {
		int p = 0;
		F(k, 1, m) if (A[j][k]) { p = k; break; }
		c[p] = (A[j][m + 1] + 2) % 3 + 1;
		F2(j2, 1, j) if (A[j2][p])
			A[j2][m + 1] = (A[j2][m + 1] - A[j][m + 1] * A[j2][p] + 6) % 3;
	}
	F(i, 1, m) if (c[i] == -1)
		c[i] = 3;
	return true;
}

void Solve() {
	static int id[MN][MN];
	scanf("%d%d", &n, &m);
	F(i, 1, n) F(j, 1, n) id[i][j] = 0;
	F(i, 1, m)
		scanf("%d%d%d", a + i, b + i, c + i),
		id[a[i]][b[i]] = i,
		id[b[i]][a[i]] = i;
	rows = 0;
	F(i, 1, n - 2) F(j, i + 1, n - 1) if (id[i][j]) F(k, j + 1, n) if (id[i][k] && id[j][k]) {
		int x = id[i][j], y = id[i][k], z = id[j][k];
		++rows;
		F(p, 1, m + 1) A[rows][p] = 0;
		A[rows][x] = A[rows][y] = A[rows][z] = 1;
	}
	F(i, 1, m) if (c[i] != -1) {
		++rows;
		F(p, 1, m + 1) A[rows][p] = 0;
		A[rows][i] = 1;
		A[rows][m + 1] = c[i] % 3;
	}
//	F(i, 1, rows) {
//		F(j, 1, m)
//			if (A[i][j])
//				printf(" + x_%d", j);
//		printf(" = %d\n", A[i][m + 1]);
//	}
	if (!Gauss())
		return puts("-1"), void();
	F(i, 1, m)
		printf("%d%c", c[i], " \n"[i == m]);
}