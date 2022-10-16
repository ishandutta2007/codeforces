#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1234;
int n, m, c[maxn], a[maxn];

int main() {
	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%d", &c[i]);
	REP(i, m) scanf("%d", &a[i]);
	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) {
		if (a[j] >= c[i]) i++, j++, ans++;
		else i++;
	}
	printf("%d\n", ans);
	return 0;
}