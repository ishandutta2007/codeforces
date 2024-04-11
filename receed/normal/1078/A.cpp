#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

ld eps = 1e-8;
struct pt {
	ld x, y;
	pt() : x(0), y(0) {}
	pt(ld x, ld y) : x(x), y(y) {}

	ld dist(pt p) {
		return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
	}
	ld md(pt p) {
		return abs(x - p.x) + abs(y - p.y);
	}
};

void inter(ll a, ll b, ll c, ll a1, ll b1, ll c1, vector<pt> &v) {
	ll f = a * b1 - b * a1;
	if (f == 0)
		return;
	v.push_back(pt({(ld) (c1 * b - c * b1) / f, (ld) (c * a1 - c1 * a) / f}));
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll a, b, c, ax, ay, bx, by;
	cin >> a >> b >> c >> ax >> ay >> bx >> by;
	vector<pt> v;
	inter(a, b, c, -1, 0, ax, v);
	inter(a, b, c, -1, 0, bx, v);
	inter(a, b, c, 0, -1, ay, v);
	inter(a, b, c, 0, -1, by, v);
	pt q(ax, ay), w(bx, by);
	ld ans = q.md(w);
	for (pt p1 : v) {
		for (pt p2 : v) {
			ans = min(ans, q.md(p1) + p1.dist(p2) + p2.md(w));
		}
	}
	cout << fixed << setprecision(8) << ans;
}