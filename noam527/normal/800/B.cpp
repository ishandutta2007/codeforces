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
	ll ix, iy;
	ldb x, y;
	point() {}
	point(ll xx, ll yy) {
		ix = xx;
		iy = yy;
		x = xx;
		y = yy;
	}
};

ldb dist(point A, point B, point P) {
	if (A.ix == B.ix) {
		return abs(A.ix - P.ix);
	}
	if (OO) {
		cout << A.x << " " << A.y << endl;
		cout << B.x << " " << B.y << endl;
		cout << P.x << " " << P.y << endl;
	}
	ldb m = (B.y - A.y) / (A.x - B.x);
	ldb tmp = A.x * m + A.y;
	ldb b, a, res;
	if (abs(tmp) < 1e-8) {
		b = 1;
		a = m;
		res = a * P.x + b * P.y;
	}
	else {
		b = -1 / tmp;
		a = b * m;
		res = a * P.x + b * P.y + 1;
	}
	if (OO) {
		cout << "equation:\n";
		cout << "m: " << m << endl;
		cout << "something: " << A.x * m + A.y << endl;
		cout << a << " " << b << endl;
		cout << "res: " << res << endl;
		cout << "return: " << abs(res) / sqrtl(a*a + b*b);
	}
	return abs(res) / sqrtl(a*a + b*b);
}

int n;
vector<point> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) {
		ll x, y;
		cin >> x >> y;
		i = point(x, y);
	}
	ldb mn = inf;
	for (int i = 0; i < n; i++) {
		int l = (i + n - 1) % n, r = (i + 1) % n;
		mn = min(mn, dist(a[l], a[r], a[i]));
	}
	cout.precision(10);
	cout << fixed << mn / 2.0 << endl;
}