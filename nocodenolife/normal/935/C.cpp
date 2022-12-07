#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

db sq(db a) {
	return a*a;
}
int main() {
	int R, x1, y1, x2, y2;
	scanf("%d %d %d %d %d", &R, &x1, &y1, &x2, &y2);
	if (x1 == x2 && y1 == y2) {
		printf("%.20lf %.20lf %.20lf\n", x1 + R / 2.0, (db)y1, R / 2.0);
		return 0;
	}

	db d = sqrt(sq(x1 - x2) + sq(y1 - y2));
	db r = min((db)R, (R + d) / 2);

	db dx = x1 - x2, dy = y1 - y2;
	db u = sqrt(dx*dx + dy*dy);
	dx /= u, dy /= u;

	db ax = dx*(R-r) + x1;
	db ay = dy*(R-r) + y1;
	return !printf("%.20lf %.20lf %.20lf\n", ax, ay, r);
}