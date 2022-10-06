#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
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
	while (tests--) {
		Solve();
	}
	return 0;
}

int n;
int bit[MN];
void Add(int i, int x) {
	for (; i <= n; i += i & -i)
		bit[i] += x;
}
int Qur(int i) {
	int s = 0;
	for (; i; i -= i & -i)
		s += bit[i];
	return s;
}

void Solve() {
	static char s[MN], t[MN], p[MN];
	scanf("%d%s%s", &n, s + 1, t + 1);
	F(i, 1, n) p[i] = s[i];
	sort(p + 1, p + n + 1);
	int ok = 0;
	F(i, 1, n)
		if (p[i] < t[i])
			ok = 1;
		else if (p[i] > t[i])
			break;
	if (!ok)
		return puts("-1"), void();
	ok = 0;
	F(i, 1, n)
		if (s[i] < t[i])
			ok = 1;
		else if (s[i] > t[i])
			break;
	if (ok)
		return puts("0"), void();
	deque<int> v[26];
	F(i, 1, n) s[i] -= 'a', t[i] -= 'a';
	F(i, 1, n) v[s[i]].push_back(i);
	F2(j, 0, 26) v[j].push_back(n + 1);
	static int cho[MN];
	F(i, 1, n) cho[i] = 0;
	ll ans = LLONG_MAX, cnt = 0;
	F(i, 1, n) bit[i] = 0;
	F(i, 1, n) Add(i, 1);
	F(i, 1, n) {
		int pos = n + 1;
		F2(j, 0, t[i])
			pos = min(pos, v[j].front());
		if (pos != n + 1)
			ans = min(ans, cnt + Qur(pos) - i);
		pos = v[t[i]].front();
		if (pos == n + 1)
			break;
		cnt += Qur(pos) - i;
		Add(1, 1);
		Add(pos, -1);
		v[t[i]].pop_front();
		cho[pos] = 1;
//		F(j, 1, n)
//			if (!cho[j])
//				printf("(%d:%d) ", j, Qur(j));
//		puts("");
	}
	printf("%lld\n", ans);
}