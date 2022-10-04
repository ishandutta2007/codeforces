#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <complex>
#include <tuple>

#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = 3.1415926535897932384626433832795;
const int mod = 1000000007;

void bad() {
	puts("0"); exit(0);
}

int nd[40];
int xr[40];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll s, x;
	cin >> s >> x;
	int flag = 0;
	if (s == x)flag = 1;
	if (s < x || (s - x) % 2 != 0) bad();
	ll a = (s - x) / 2;
	ll ans = 1;
	for (int i = 0; i < 40; i++) {
		int xx = x % 2;
		int aa = a % 2;
		if (aa == 0) {
			if (xx == 1)ans *= 2;
		}
		else if (xx == 1) bad();
		x /= 2;
		a /= 2;
	}
	if (flag) ans -= 2;
	cout << ans;

	return 0;
}