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

const double pi = 3.1415926535897932384626433832795;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; double r;
	cin >> n >> r;
	double ang = pi / n;
	double L = 2 * r*cos(ang / 2);
	double r1 = sin(ang);
	double r2 = sin(2 * ang);
	double L1 = L*r1 / (r1 + r2);
	double L2 = L*r2 / (r1 + r2);
	double po = r*r - L1*L2;
	po = sqrt(po);
	double h = L*sin(ang / 2);
	double A = n*h*po;
	printf("%.15f", A);

}