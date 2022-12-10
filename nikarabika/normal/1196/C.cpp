//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

#define INF 100000
#define INFRECT MP(MP(-INF, +INF), MP(-INF, +INF))

void solve() {
	pair<pii, pii> ans = INFRECT;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, f1, f2, f3, f4;
		cin >> x >> y >> f1 >> f2 >> f3 >> f4;
		pair<pii, pii> cur;
		cur = INFRECT;
		if (!f1) cur.L.L = x;
		if (!f2) cur.R.R = y;
		if (!f3) cur.L.R = x;
		if (!f4) cur.R.L = y;
		smax(ans.L.L, cur.L.L);
		smax(ans.R.L, cur.R.L);
		smin(ans.L.R, cur.L.R);
		smin(ans.R.R, cur.R.R);
	}
	if (ans.L.L <= ans.L.R and ans.R.L <= ans.R.R)
		cout << 1 << ' ' << ans.L.L << ' ' << ans.R.L << '\n';
	else
		cout << 0 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}