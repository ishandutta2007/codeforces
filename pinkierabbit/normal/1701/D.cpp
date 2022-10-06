#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 500005
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
int b[MN], l[MN], r[MN], p[MN], a[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) {
		scanf("%d", b + i);
		if (!b[i])
			l[i] = i + 1, r[i] = n;
		else
			l[i] = i / (b[i] + 1) + 1, r[i] = i / b[i];
		p[i] = i;
	}
//	F(i, 1, n) printf("%d%c", l[i], " \n"[i == n]);
//	F(i, 1, n) printf("%d%c", r[i], " \n"[i == n]);
	sort(p + 1, p + n + 1, [](int i, int j) {
		return l[i] < l[j];
	});
	std::priority_queue<pii> pq;
	int j = 1;
	F(i, 1, n) {
		while (j <= n && l[p[j]] == i)
			pq.push({-r[p[j]], p[j]}),
			++j;
		a[pq.top().se] = i;
		pq.pop();
	}
	F(i, 1, n) printf("%d%c", a[i], " \n"[i == n]);
}