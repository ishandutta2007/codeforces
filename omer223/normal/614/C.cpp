#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <iomanip>
#define mp make_pair
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
const int sz = 1e5 + 5;
pld p[sz];
const ld pi = 3.14159265358979, tol = 1e-3;
pld center;
ld dist(pld a, pld b) {
	return sqrtl((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}
ld surface(pld a, pld b, pld c) {
	ld p = dist(a, b), q = dist(b, c), r = dist(a, c), s = (p + q + r) / 2;
	return sqrtl(s*(s - p)*(s - q)*(s - r));
}
ld lr(pld a, pld b) {
	return max(dist(a, center), dist(b, center));
}
ld sr(pld a, pld b) {
	if (a.first != b.first&&a.second != b.second) {
		ld slope = (a.second - b.second) / (a.first - b.first);
		ld pslope = -1 / slope, b1 = b.second - slope * b.first, b2 = center.second - pslope * center.first;
		ld myx = (b2 - b1) / (slope - pslope), myy = slope * myx + b1;
		pld cand = mp(myx, myy);
		ld distsum = dist(cand, a) + dist(cand, b), dab=dist(a,b);
		if (abs(distsum - dab) <= tol) {
			return 2*surface(a, b, center) / dab;
		}
		else {
			return min(dist(a, center), dist(b, center));
		}
	}
	else if (a.first == b.first) {
		if (center.second >= min(a.second, b.second) && center.second <= max(a.second, b.second)) {
			return abs(a.first - center.first);
		}
		else return min(dist(a, center), dist(b, center));
	}
	else {
		if (center.first >= min(a.first, b.first) && center.first <= max(a.first, b.first)) {
			return abs(a.second - center.second);
		}
		else return min(dist(a, center), dist(b, center));
	}
}

int main() {
	fast;
	int n;
	ld mx = 0, mn = 1e18;
	cin >> n >> center.first >> center.second;
	foru(i, 0, n)cin >> p[i].first >> p[i].second;
	foru(i, 0, n) {
		mx = max(mx, lr(p[i], p[(i + 1) % n]));
		mn = min(mn, sr(p[i], p[(i + 1) % n]));
	}
	cout << fixed << setprecision(8) << pi * (mx - mn)*(mx + mn) << endl;
	return 0;
}