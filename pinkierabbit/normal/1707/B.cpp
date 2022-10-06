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
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n;
int a[MN], b[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	F(i, 1, n - 1) b[i] = a[i + 1] - a[i];
	sort(b + 1, b + n);
	--n;
	if (n == 1)
		return printf("%d\n", b[1]), void();
	F(i, 1, n - 1) a[i] = b[i + 1] - b[i];
	sort(a + 1, a + n);
	--n;
	int numz = 0;
	while (numz < n && a[numz + 1] == 0)
		++numz;
	int len = n - numz;
	F(i, 1, len) a[i] = a[i + numz];
	F(t, 1, n - 1) {
		if (!len)
			return puts("0"), void();
		if (!numz) {
			F(i, 1, len - 1) b[i] = a[i + 1] - a[i];
			sort(b + 1, b + len);
			--len;
			F(i, 1, len) a[i] = b[i];
		} else {
			a[0] = 0;
			F(i, 1, len) b[i] = a[i] - a[i - 1];
			sort(b + 1, b + len + 1);
			F(i, 1, len) a[i] = b[i];
			--numz;
		}
		int numz2 = 0;
		while (numz2 < len && a[numz2 + 1] == 0)
			++numz2;
		len -= numz2;
		F(i, 1, len) a[i] = a[i + numz2];
		numz += numz2;
	}
	printf("%d\n", numz ? 0 : a[1]);
}