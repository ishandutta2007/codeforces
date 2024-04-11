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

int n, m, x, d;
ll ans, coeff[2];

int main() {
	scanf("%d%d", &n, &m);
	coeff[0] = ll(n - 1 >> 1) * ((n - 1) / 2 + 1);
	if ((n ^ 1) & 1) coeff[0] += n >> 1;
	coeff[1] = ll(n) * (n - 1) / 2;
	REP(i, m) {
		scanf("%d%d", &x, &d);
		ans += ll(x) * n;
		ans += coeff[d > 0] * d;
	}
	printf("%.10lf\n", double(ans) / n);
	return 0;
}