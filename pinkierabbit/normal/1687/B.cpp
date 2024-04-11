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
#define MM 505
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
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int m;
int a[MM], p[MM];

void Solve() {
	scanf("%*d%d", &m);
	F(i, 1, m) {
		printf("? ");
		F(j, 1, m)
			printf("%c", '0' + (j == i ? 1 : 0));
		printf("\n"); fflush(stdout);
		scanf("%d", &a[i]);
		p[i] = i;
	}
	sort(p + 1, p + m + 1, [](int i, int j) {
		return a[i] < a[j];
	});
	static int b[MM];
	F(i, 1, m) b[i] = 0;
	int w = 0;
	F(id, 1, m) {
		int i = p[id];
		b[i] = 1;
		printf("? ");
		F(j, 1, m)
			printf("%c", '0' + b[j]);
		printf("\n"); fflush(stdout);
		int nw;
		scanf("%d", &nw);
		if (nw - w != a[i])
			b[i] = 0;
		else
			w = nw;
	}
	printf("! %d\n", w);
	fflush(stdout);
}