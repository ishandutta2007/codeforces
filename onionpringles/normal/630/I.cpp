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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//1,2,...., n-2, n-1,... 2n-2
	ll n; cin >> n;
	cout << 4 * (2 * 3 * pow2(4, n - 3) + (n - 3) * 9 * pow2(4, n - 4));
	return 0;
}