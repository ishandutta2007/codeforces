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

int n, m, q, k;
char s[MN];
int b[100];

void Solve() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	F(j, 0, 25) b[j] = n + 1;
	F(i, 1, n)
		b[s[i] - 'a'] = i;
	int p = *min_element(b, b + 26);
	printf("%s\n", s + p);
}