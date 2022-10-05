#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct point {
	ll x, y;
	point() {}
	point(ll xx, ll yy) {
		x = xx;
		y = yy;
	}
	point operator - (const point &a) const {
		return point(x - a.x, y - a.y);
	}
	ll operator * (const point &a) const {
		return x * a.y - y * a.x;
	}
	bool operator < (const point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
};

int turn(point a, point b, point c) {
	ll m = (b - a) * (c - a);
	if (m < 0) return 1;
	if (m > 0) return -1;
	return 0;
}

int n, m, x, y;
vector<point> a, b;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> x >> y;
	a.resize(n);
	b.resize(m);
	for (auto &i : a) cin >> i.x >> i.y;
	for (auto &i : b) cin >> i.x >> i.y;
	sort(b.begin(), b.end());
	vector<point> tmp;
	for (const auto &i : b) {
		while (tmp.size() >= 1 && tmp.back().y <= i.y) tmp.pop_back();
		while (tmp.size() >= 2 && turn(tmp[tmp.size() - 2], tmp.back(), i) != 1) tmp.pop_back();
		tmp.push_back(i);
	}
	b = tmp;
	for (const auto &i : a) {
		if (i.y >= b[0].y || i.x >= b.back().x) finish("Max");
		else if (b.size() >= 2 && i.x > b[0].x) {
			int i2 = lower_bound(b.begin(), b.end(), point(i.x, 0)) - b.begin();
			point p1 = b[i2 - 1], p2 = b[i2];
			if (turn(p1, i, p2) != -1) finish("Max");
		}
	}
	finish("Min");
}