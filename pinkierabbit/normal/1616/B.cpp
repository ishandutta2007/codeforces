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

int n, m, q, k;

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
	static char s[MN];
	scanf("%d%s", &n, s + 1);
	if (n == 1)
		return printf("%c%c\n", s[1], s[1]), void();
	if (s[1] == s[2])
		return printf("%c%c\n", s[1], s[1]), void();
	s[n + 1] = 'z';
	F(i, 1, n) if (s[i + 1] > s[i]) {
		F(j, 1, i) printf("%c", s[j]);
		dF(j, i, 1) printf("%c", s[j]);
		break;
	}
	puts("");
}