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
	ll tmp = pow2(n, e / 2);
	tmp = tmp*tmp;
	if (e % 2) tmp *= n;
	return tmp;
}

typedef complex<double> Point;

const double pi = 3.1415926535897932384626433832795;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	double l3, l4, l5;
	cin >> l3 >> l4 >> l5;
	double V3 = sqrt(2)*l3*l3*l3 / 12;
	double V4 = l4*l4*l4 / sqrt(2) / 3;
	double V5 = 5 * l5*l5 / 2 * tan(54 * pi / 180) / 2 * l5*sqrt(1 - 1/4.0/cos(54*pi/180)/cos(54*pi/180)) / 3;
	printf("%.15f", V3 + V4 + V5);
}