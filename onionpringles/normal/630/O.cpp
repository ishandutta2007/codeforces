#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <limits.h>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string.h>
#include <string>

#define mp make_pair
#define mtp make_tuple
#define ni(x) scanf("%d", &(x))
#define nii(x, y) scanf("%d%d", &(x), &(y))
#define mul(x,y) (ll)(x)*(y)%mod

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

ll ncr(ll n, ll r) {
	ll st = 1;
	for (int i = 1; i <= r; i++) {
		st *= n - i + 1;
		st /= i;
	}
	return st;
}

ll pow2(ll n, ll e) {
	if (e<=0)return 1;
	ll tmp = pow(n, e / 2);
	tmp = tmp*tmp;
	if (e % 2) tmp *= n;
	return tmp;
}

typedef complex<double> Point;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	double px, py, vx, vy, a, b, c, d;
	cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
	Point O = Point(px, py);
	Point v = Point(vx, vy);
	v = v / abs(v);
	Point pts[7];
	pts[0] = O + b*v;
	pts[1] = O + a/2*Point(0, 1)*v;
	pts[6] = O + a/2*Point(0, -1)*v;
	pts[2] = O + c / 2 * Point(0, 1)*v;
	pts[3] = pts[2] - d*v;
	pts[5] = O + c / 2 * Point(0, -1)*v;
	pts[4] = pts[5] - d*v;
	for (int i = 0; i < 7; i++) printf("%.15f %.15f\n", pts[i].real(), pts[i].imag());
}