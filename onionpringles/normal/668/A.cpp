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

int a[100][100];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, q;
	nii(n, m); ni(q);
	vector<pair<pii,pii> > qs;
	F(i, q) {
		int x; ni(x);
		if (x == 1 || x == 2) {
			int y; ni(y);
			qs.push_back(mp(mp(x, y), mp(0, 0)));
		}
		else {
			int y, z, w; nii(y, z); ni(w);
			qs.push_back(mp(mp(x, y), mp(z, w)));
		}
	}
	for (int i = q - 1; i >= 0; i--) {
		int tp = qs[i].first.first;
		if (tp == 1 || tp == 2) {
			int y = qs[i].first.second;
			y--;
			if (tp == 1) {
				for (int j = m - 1;j >= 1; j--) {
					swap(a[y][j], a[y][j - 1]);
				}
			}
			else if (tp == 2) {
				for (int j = n - 1; j >= 1; j--) {
					swap(a[j][y], a[j - 1][y]);
				}
			}
		}
		else {
			int r = qs[i].first.second;
			int c = qs[i].second.first;
			int x = qs[i].second.second;
			r--; c--;
			a[r][c] = x;
		}
	}
	F(i, n) {
		F(j, m) print(a[i][j]);
		puts("");
	}
	return 0;
}