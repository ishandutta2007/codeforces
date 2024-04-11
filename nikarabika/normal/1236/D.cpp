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

const int maxn = 1e5 + 100;
vector<int> rows[maxn],
	cols[maxn];
int dx[] = {+0, +1, -0, -1};
int dy[] = {+1, +0, -1, -0};
int n, m, k;

void add_obs(int x, int y) {
	cols[y].PB(x);
	rows[x].PB(y);
}

bool is_obs(int x, int y) {
	auto it = lower_bound(all(rows[x]), y);
	if (it == rows[x].end() or *it != y)
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		add_obs(i, 0), add_obs(i, m + 1);
	for (int i = 1; i <= m; i++)
		add_obs(0, i), add_obs(n + 1, i);
	for (int i = 0; i < k; i++) {
		int fi, se;
		cin >> fi >> se;
		add_obs(fi, se);
	}
	for (int i = 0; i < maxn; i++)
		sort(all(cols[i])), sort(all(rows[i]));
	int xl = 1,
		xr = n,
		yl = 1,
		yr = m;
	int dir = 0;
	pii pos(1, 1);
	LL area = 0;
	while (true) {
		if (dir & 1) {
			// column
			int id = lower_bound(all(cols[pos.R]), pos.L) - cols[pos.R].begin();
			if (dir == 1) {
				smin(xr, cols[pos.R][id] - 1);
				area += xr - pos.L + 1;
				pos.L = xr;
				yr--;
				pos.R--;
			}
			else {
				id--;
				smax(xl, cols[pos.R][id] + 1);
				area += pos.L - xl + 1;
				pos.L = xl;
				yl++;
				pos.R++;
			}
		}
		else {
			// row
			int id = lower_bound(all(rows[pos.L]), pos.R) - rows[pos.L].begin();
			if (dir == 0) {
				smin(yr, rows[pos.L][id] - 1);
				area += yr - pos.R + 1;
				pos.R = yr;
				xl++;
				pos.L++;
			}
			else {
				id--;
				smax(yl, rows[pos.L][id] + 1);
				area += pos.R - yl + 1;
				pos.R = yl;
				xr--;
				pos.L--;
			}
		}
		if (is_obs(pos.L, pos.R) or pos.L < xl or xr < pos.L or pos.R < yl or yr < pos.R) {
			if (area == 1LL * n * m - k)
				return cout << "Yes\n", 0;
			cout << "No\n";
			return 0;
		}
		dir = (dir + 1) & 3;
	}
	return 0;
}