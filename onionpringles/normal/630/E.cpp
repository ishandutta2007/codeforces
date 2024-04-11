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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll dx = x2 - x1 + 1;
	ll dy = y2 - y1 + 1;
	ll ans = dx*dy / 2;
	if (dx % 2 == 1 && dy % 2 == 1) {
		 ans++;
	}
	cout << ans;
	return 0;
}