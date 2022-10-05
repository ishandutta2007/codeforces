#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct point {
	ll x, y, z;
	int i;
	point(ll xx = 0, ll yy = 0, ll zz = 0, int ii = 0) {
		x = xx;
		y = yy;
		z = zz;
		i = ii;
	}
	bool operator < (const point &a) const {
		if (x != a.x) return x < a.x;
		if (y != a.y) return y < a.y;
		return z < a.z;
	}
};

int n;
vector<point> a;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].i = i + 1;
	}
	sort(a.begin(), a.end());
	vector<point> b;
	// 2
	for (const auto &i : a) {
		if (!b.size() || b.back().x != i.x || b.back().y != i.y) b.push_back(i);
		else {
			cout << b.back().i << " " << i.i << '\n';
			b.pop_back();
		}
	}
	a = b;
	b.clear();
	// 1
	for (const auto &i : a) {
		if (!b.size() || b.back().x != i.x) b.push_back(i);
		else {
			cout << b.back().i << " " << i.i << '\n';
			b.pop_back();
		}
	}
	a = b;
	b.clear();
	for (int i = 0; i < a.size(); i += 2)
		cout << a[i].i << " " << a[i + 1].i << '\n';
}