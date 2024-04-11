#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Point {
	int x, y, type;
	void print() {
		cout << "[" << x << ", " << y << ", " << (type == 0 ? "Red" : "Blue") << "]\n";
	}
	Point operator-(const Point& o) const {
		return {x - o.x, y - o.y, type};
	}
	ll operator*(const Point& o) const {
		return (ll)x * o.y - (ll)y * o.x;
	}
};

int n, m, ans;
Point a[500], b[500];

void solve(vector<Point>& v) {
	sort(v.begin(), v.end(), [](const Point& x, const Point& y) {
		//return atan2(x.y, x.x) < atan2(y.y, y.x);
		if (x.y == 0 && x.x > 0) return true;
		if (y.y == 0 && y.x > 0) return false;
		if ((x.y >= 0) ^ (y.y >= 0)) return x.y >= 0;
		return x * y > 0;
	});
	//for (Point x : v)
	//	x.print();
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].type == 1) // skip if blue
			continue;
		Point blue = {-1, -1, -1};
		for (int j = 1; j < v.size(); ++j) {
			Point& cur = v[(i + j) % v.size()];
			if (v[i] * cur < 0)
				break;
			if (cur.type == 0) {
				if (blue.type == -1 || (cur - v[i]) * (blue - v[i]) < 0)
					++ans;
			}
			else {
				if (blue.type == -1 || (cur - v[i]) * (blue - v[i]) < 0)
					blue = cur;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y, a[i].type = 0;
	for (int i = 0; i < m; ++i)
		cin >> b[i].x >> b[i].y, b[i].type = 1;
	for (int i = 0; i < n; ++i) {
		vector<Point> v; v.reserve(n - i - 1 + m);
		for (int j = i + 1; j < n; ++j)
			v.emplace_back(a[j] - a[i]);
		for (int j = 0; j < m; ++j)
			v.emplace_back(b[j] - a[i]);
		solve(v);
	}
	cout << ans;
	return 0;
}