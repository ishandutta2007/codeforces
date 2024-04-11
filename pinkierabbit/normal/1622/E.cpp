#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define MN 10
#define MM 10005

int n, m;
int a[MN], b[MN][MM];

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

void Solve() {
	scanf("%d%d", &n, &m);
	F2(i, 0, n) scanf("%d", a + i);
	F2(i, 0, n)
		F(j, 1, m)
			scanf("%1d", &b[i][j]);
	static int ans[MM];
	int maxdif = -1; // love miepu
	F2(s, 0, 1 << n) {
		static int c[MM];
		F(j, 1, m) c[j] = 0;
		F2(i, 0, n)
			F(j, 1, m)
				c[j] += b[i][j] ? s >> i & 1 ? -1 : 1 : 0;
		static int per[MM], val[MM];
		F(j, 1, m) per[j] = j;
		sort(per + 1, per + m + 1, [&](int i, int j) {
			return c[i] < c[j];
		});
		F(j, 1, m) val[per[j]] = j;
//		F(j, 1, m) printf("%d%c", val[j], " \n"[j == m]);
		int dif = 0;
		F2(i, 0, n) {
			int sc = 0;
			F(j, 1, m)
				if (b[i][j])
					sc += val[j];
			dif += abs(a[i] - sc);
		}
//		printf("\tdif = %d\n", dif);
		if (dif > maxdif) {
			maxdif = dif;
			F(j, 1, m) ans[j] = val[j];
		}
	}
	F(j, 1, m) printf("%d%c", ans[j], " \n"[j == m]);
}