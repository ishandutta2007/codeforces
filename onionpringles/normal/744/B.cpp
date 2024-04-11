#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
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
#include <iterator>
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
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 1000;
const int LG = 10;
int a[10][N];
int b[10][N];
int main() {
#ifndef __GNUG__
	//freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, LG) {
		vector<int> V;
		F(j, 1 << LG) {  //ith bit is zero0
			if (j&(1 << i)) continue;
			if (j < n) {
				V.push_back(j + 1);
			}
		}
		if (V.empty()) {
			F(j, n) a[i][j] = inf;
			goto lab;
		}
		printf("%d\n", (int)V.size());
		for (auto &x : V)printf("%d ", x); puts(""); fflush(stdout);
		F(j, n)scanf("%d", &a[i][j]);
		lab:
		V.clear();
		F(j, 1 << LG) {  //ith bit is obne
			if (!(j&(1 << i))) continue;
			if (j < n) {
				V.push_back(j + 1);
			}
		}
		if (V.empty()) {
			F(j, n)b[i][j] = inf;
			continue;
		}

		printf("%d\n", (int)V.size());
		for (auto &x : V)printf("%d ", x); puts(""); fflush(stdout);
		F(j, n) scanf("%d", &b[i][j]);
	}
	puts("-1");
	F(i, n) {
		int ans = inf;
		F(j, LG) {
			if (i&(1 << j)) {
				ans = min(ans, a[j][i]);
			}
			else ans = min(ans, b[j][i]);
		}
		printf("%d ", ans);
	}
	puts("");
	fflush(stdout);
	return 0;
}