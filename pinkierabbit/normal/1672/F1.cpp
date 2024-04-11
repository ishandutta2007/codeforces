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
int a[MN], b[MN], c[MN];
vector<int> G[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) b[i] = 1, G[i].clear();
	F(i, 1, n) scanf("%d", a + i), ++b[a[i]];
	F(i, 1, n) c[i] = i;
	sort(c + 1, c + n + 1, [](int i, int j) {
		return b[i] > b[j];
	});
	b[c[n + 1] = n + 1] = 0;
	while (b[c[1]]) {
		for (int i = 1; ; ++i) {
			--b[c[i]];
			if (b[c[i + 1]])
				G[c[i]].push_back(c[i + 1]);
			else {
				G[c[i]].push_back(c[1]);
				break;
			}
		}
	}
	F(i, 1, n)
		printf("%d%c", G[a[i]].back(), " \n"[i == n]),
		G[a[i]].pop_back();
}