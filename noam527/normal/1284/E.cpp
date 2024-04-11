#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct point {
	ll x, y;
	int r;
	point() {
		x = y = r = 0;
	}
	point(ll xx, ll yy) {
		x = xx;
		y = yy;
		if (y > 0 || (y == 0 && x > 0)) r = 0;
		else r = 1;
	}
	point operator - (const point &a) const {
		return point(x - a.x, y - a.y);
	}
	point operator + (const point &a) const {
		return point(x + a.x, y + a.y);
	}
	bool operator < (const point &a) const {
		if (r != a.r) return r < a.r;
		return x * a.y - y * a.x > 0;
	}
};

int turn(point a, point b, point c) {
	b = b - a;
	c = c - a;
	ll m = b.x * c.y - b.y * c.x;
	if (m == 0) return 0;
	if (m > 0) return -1;
	return 1;
}

ll c3(ll n) {
	if (n < 3) return 0;
	return n * (n - 1) * (n - 2) / 6;
}
ll c4(ll n) {
	if (n < 4) return 0;
	return n * (n - 1) * (n - 2) * (n - 3) / 24;
}

ll calc(vector<point> p) {
	p.pop_back();
	sort(p.begin(), p.end());
	if (OO) {
		for (auto &i : p)
			cout << i.x << " " << i.y << endl;
	}

	int n = p.size();
	ll ans = 0;
	int nxt = 0;
	for (int i = 0; i < n; i++) {
		if (nxt == i) nxt = (nxt + 1) % n;
		while (nxt != i && turn(p[i], point(), p[nxt]) == 1)
			nxt = (nxt + 1) % n;
		if (OO) {
			cout << "i nxt " << i << " " << nxt << endl;
		}
		int d = nxt - i;
		if (d <= 0) d += n;
		if (OO) cout << "d " << d << endl;
		ans += c3(d - 1);
	}
	if (OO) cout << "ans " << ans << endl << endl;
	return ans;
}

int n;
vector<point> p;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		p[i] = point(x, y);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (OO) cout << "start " << i << endl;
		swap(p[i], p.back());
		for (int j = 0; j < n - 1; j++)
			p[j] = p[j] - p.back();
		ans += c4(n - 1) - calc(p);
		for (int j = 0; j < n - 1; j++)
			p[j] = p[j] + p.back();
		swap(p[i], p.back());
	}
	cout << ans << endl;
}