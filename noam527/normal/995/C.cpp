#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct point {
	ll x, y;
	int i;
	point(ll xx = 0, ll yy = 0, ll ii = 0) {
		x = xx;
		y = yy;
		i = ii;
	}
	bool operator < (const point &a) const {
		if (x != a.x) return abs(x) > abs(a.x);
		return abs(y) > abs(a.y);
	}
};

int n;
vector<point> a;
vector<int> ans;

ll dist(ll x, ll y) {
	return x * x + y * y;
}

bool isok(ll x, ll y) {
	if (x * x + y * y <= 225LL * 10000000000LL) return true;
	return false;
}

int main() {
	fast;
	cin >> n;
	a.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].i = i;
	}
	sort(a.begin(), a.end());

	ll curx = 0, cury = 0;
	for (const auto &i : a) {
		if (dist(curx + i.x, cury + i.y) < dist(curx - i.x, cury - i.y)) {
			curx += i.x;
			cury += i.y;
			ans[i.i] = 1;
		}
		else {
			curx -= i.x;
			cury -= i.y;
			ans[i.i] = -1;
		}
	}
	if (dist(curx, cury) > 225LL * 10000000000LL) {
		for (auto &i : a) swap(i.x, i.y);
		sort(a.begin(), a.end());

		curx = 0, cury = 0;
		for (const auto &i : a) {
			if (dist(curx + i.x, cury + i.y) < dist(curx - i.x, cury - i.y)) {
				curx += i.x;
				cury += i.y;
				ans[i.i] = 1;
			}
			else {
				curx -= i.x;
				cury -= i.y;
				ans[i.i] = -1;
			}
		}
		if (dist(curx, cury) > 225LL * 10000000000LL) finish("aww");
	}
	for (const auto &i : ans) cout << i << " "; cout << endl;
}