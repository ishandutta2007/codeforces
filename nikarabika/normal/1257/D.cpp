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

const int maxn = 200 * 1000 + 10;
int seg[maxn << 2];
int a[maxn],
	mx[maxn],
	n, m;

void build(int l = 0, int r = n, int id = 1) {
	if (r - l == 1) {
		seg[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id << 1 | 0);
	build(mid, r, id << 1 | 1);
	seg[id] = max(seg[id << 1 | 0],
			seg[id << 1 | 1]);
}

int get(int st, int en, int l = 0, int r = n, int id = 1) {
	if (st >= r or en <= l)
		return -1;
	if (st <= l and r <= en)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(st, en, l, mid, id << 1 | 0),
			get(st, en, mid, r, id << 1 | 1));
}

int solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build();
	cin >> m;
	fill(mx, mx + n + 1, -1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		smax(mx[y], x);
	}
	for (int i = n; i > 0; i--)
		smax(mx[i - 1], mx[i]);
	int st = 0;
	int ans = 0;
	while (st < n) {
		int lo = st - 1,
			hi = n;
		while (hi - lo > 1) {
			int mid = (lo + hi) >> 1;
			if (get(st, mid + 1) <= mx[mid - st + 1])
				lo = mid;
			else
				hi = mid;
		}
		if (lo == st - 1)
			return cout << -1 << '\n', 0;
		st = hi;
		ans++;
	}
	cout << ans << '\n';
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