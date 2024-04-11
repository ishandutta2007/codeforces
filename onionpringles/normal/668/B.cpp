#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)
#define println(x) printf("%d\n", x)
#define print(x) printf("%d ", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

vector<pii> qs;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, q;
	nii(n, q);
	F(i, q) {
		int x; ni(x);
		if (x == 1) {
			int y; ni(y);
			qs.push_back(mp(x, y));
		}
		else {
			qs.push_back(mp(x, 0));
		}
	}
	int ind = 0;
	for (auto &x : qs) {
		if (x.first == 1) {
			ind = (ind + x.second + n) % n;
		}
		else {
			if (ind % 2 == 0) ind++;
			else ind--;
		}
	}
	vector<int> ans(n);
	for (int i = 0; i < n / 2; i++) {
		ans[ind] = 2 * i + 1;
		ind += 2; ind %= n;
	}

	ind = 1;
	for (auto &x : qs) {
		if (x.first == 1) {
			ind = (ind + x.second + n) % n;
		}
		else {
			if (ind % 2 == 0) ind++;
			else ind--;
		}
	}
	for (int i = 0; i < n / 2; i++) {
		ans[ind] = 2 * i + 2;
		ind += 2; ind %= n;
	}
	for (auto &x : ans)print(x);
}