#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
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
char s[MN];

void Solve() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	bool ok = s[n] == 'B';
	int t = 0;
	F(i, 1, n) {
		t += s[i] == 'B' ? -1 : +1;
		if (t < 0)
			ok = false;
	}
	puts(ok ? "YES" : "NO");
}