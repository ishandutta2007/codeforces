#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int K, n, m, s[maxn + 10], id[maxn + 10], opcnt;
ll a[maxn + 10];
vector<pair<int, pair<int, int> > > g[maxn + 10];

struct data {
	ll x, y; int id, tp;

	bool operator < (const data &t) const {
		return x * t.y > t.x * y;
	}
}op[maxn + 10];

bool cmp(const data &a, const data &b) {
	return a.tp < b.tp;
}

int main() {
	scanf("%d%d%d", &K, &n, &m);
	for (int i = 1; i <= K; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i) {
		int t, p, b; scanf("%d%d%d", &t, &p, &b);
		if (t == 1) {
			if (b > s[p]) {
				s[p] = b; id[p] = i;
			}
		} else if (t == 2) g[p].push_back(make_pair(b, make_pair(i, 2)));
		else op[++opcnt] = (data){b - 1, 1, i, 3};
	}
	for (int i = 1; i <= K; ++i) {
		if (s[i] > a[i]) g[i].push_back(make_pair(s[i] - a[i], make_pair(id[i], 1)));
		sort(g[i].begin(), g[i].end(), greater<pair<int, pair<int, int> > >());
		for (int j = 0; j < (int)g[i].size(); ++j) {
			pair<int, pair<int, int> > e = g[i][j];
			op[++opcnt] = (data){e.first, a[i], e.second.first, e.second.second};
			a[i] += e.first;
		}
	}
	sort(op + 1, op + opcnt + 1); int r = min(opcnt, m);
	sort(op + 1, op + r + 1, cmp);
	printf("%d\n", r);
	for (int i = 1; i <= r; ++i)
		printf("%d ", op[i].id);
}