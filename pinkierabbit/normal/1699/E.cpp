#include <cstdio>
#include <algorithm>
using namespace std;

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define MM 5000005

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, m;
int b[MM];
int f[MM];
int b2[MM];

void Solve() { int xx;
	scanf("%d%d", &n, &m);
	F(i, 1, m) b2[i] = b[i] = f[i] = 0;
	F(i, 1, n) scanf("%d", &xx), b[xx] = 1;
	f[1] = 1;
	F(i, 1, m) if (b[i]) ++b2[f[i]];
	int p = 0;
	while (!b2[p]) ++p;
	if (p)
		return puts("0"), void();
	int ans = m;
	F(i, 2, m) {
		if (b[i])
			--b2[f[i]],
			++b2[i];
		f[i] = i;
		int lim = m / i;
		F(j, 2, lim) {
			int k = i * j;
			if (f[k] < f[j]) {
				if (b[k])
					--b2[f[k]],
					++b2[f[j]];
				f[k] = f[j];
			}
		}
		while (!b2[p]) ++p;
		if (p)
			ans = min(ans, i - p);
	}
	printf("%d\n", ans);
}