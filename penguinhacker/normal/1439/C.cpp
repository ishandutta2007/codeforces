#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, a[200000];
ll sum[4 * 200000], mn[4 * 200000], lazy[4 * 200000];

void pull(int u) {
	sum[u] = sum[2 * u] + sum[2 * u + 1];
	//mn[u] = min(mn[2 * u], mn[2 * u + 1]);
	mn[u] = mn[2 * u + 1];
}

void build(int u = 1, int l = 0, int r = n - 1) {
	if (l == r) {
		sum[u] = mn[u] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * u, l, mid), build(2 * u + 1, mid + 1, r);
	pull(u);
}

void push(int u, int l, int r) {
	if (lazy[u] == 0) return;
	sum[u] = (r - l + 1) * lazy[u];
	mn[u] = lazy[u];
	if (l != r) lazy[2 * u] = lazy[2 * u + 1] = lazy[u];
	lazy[u] = 0;
}

void upd(int ql, int qr, int x, int u = 1, int l = 0, int r = n - 1) {
	push(u, l, r); if (ql > r || qr < l) return;
	if (ql <= l && r <= qr) {lazy[u] = x; push(u, l, r); return;}
	int mid = (l + r) / 2;
	upd(ql, qr, x, 2 * u, l, mid), upd(ql, qr, x, 2 * u + 1, mid + 1, r);
	pull(u);
}

ll qry_sum(int ql, int qr, int u = 1, int l = 0, int r = n - 1) { //sum range query
	push(u, l, r); if (ql > r || qr < l) return 0;
	if (ql <= l && r <= qr) return sum[u];
	int mid = (l + r) / 2;
	return qry_sum(ql, qr, 2 * u, l, mid) + qry_sum(ql, qr, 2 * u + 1, mid + 1, r);
}

int find_first_smaller(int x, int u = 1, int l = 0, int r = n - 1) { //smaller than or equal to
	push(u, l, r); if (mn[u] > x) return -1;
	if (l == r) return l;
	int mid = (l + r) / 2;
	int temp = find_first_smaller(x, 2 * u, l, mid);
	if (temp != -1) return temp;
	return find_first_smaller(x, 2 * u + 1, mid + 1, r);
}

int find_take(ll& y, int u = 1, int l = 0, int r = n - 1) {
	push(u, l, r);
	if (y >= sum[u]) {
		y -= sum[u];
		return r - l + 1;
	}
	if (l == r) return 0; //otherwise covered by above case
	int mid = (l + r) / 2;
	push(2 * u, l, mid);
	if (y >= sum[2 * u]) {
		y -= sum[2 * u];
		return mid - l + 1 + find_take(y, 2 * u + 1, mid + 1, r);
	}
	return find_take(y, 2 * u, l, mid);
}

map<pair<int, ll>, int> speed;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> a[i];
	build();
	for (int i = 0; i < q; ++i) {
		int type, x; ll y; cin >> type >> x >> y, --x;
		if (type == 1) {
			int ind = find_first_smaller(y);
			if (ind == -1 || ind > x) continue;
			//cout << ind << " " << x << "\n";
			upd(ind, x, y);
			speed.clear();
		}
		else if (type == 2) {
			if (speed.find({x, y}) != speed.end()) {
				cout << speed[{x, y}] << "\n";
				continue;
			}
			int ans = 0;
			while(1) {
				int ind = find_first_smaller(y);
				if (ind == -1 || x == n) break;
				if (ind < x) ind = x;
				y += qry_sum(0, ind - 1);
				int take = find_take(y);
				ans += take - ind;
				//y -= qry_sum(ind, take - 1);
				x = take;
				//assert(y >= 0);
				//cout << ind << " " << take << "\n";
			}
			speed[{x, y}] = ans;
			cout << ans << "\n";
		}
		else assert(0);
	}
	return 0;
}