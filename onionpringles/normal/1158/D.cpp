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
#include <array>
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
#define FE(i,n) for(int i = 0; i <= (n); i++)

#ifndef __GNUG__
int __builtin_popcount(int n) {
	int x = 0;
	while (n)n -= n&(-n), x++;
	return x;
}
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 2010;
pii a[N];
char b[N];
int chk[N];
ll cr(const pii& x, const pii& y) {
	return 1LL*x.first*y.second - 1LL*x.second*y.first;
}
ll ccw(const pii& x, const pii& y, const pii& z) {
	return cr(x, y) + cr(y, z) + cr(z, x);
}


int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
		int n; ni(n);
		F(i, n) {
			int x, y; nii(x, y); a[i] = { x,y };
		}
		vector<int> V;
		int s = min_element(a, a + n) - a;
		V.push_back(s);
		chk[s] = 1;
		scanf("%s", b);
		b[n - 2] = 'L';
		F(i, n - 1) {
			int cr = -1;
			if (b[i] == 'R') {
				F(j, n) {
					if (chk[j])continue;
					if (cr == -1 || ccw(a[s], a[cr], a[j]) > 0)cr = j;
				}
			}
			else {
				F(j, n) {
					if (chk[j])continue;
					if (cr == -1 || ccw(a[s], a[cr], a[j]) < 0)cr = j;
				}
			}
			chk[cr] = 1;
			s = cr;
			V.push_back(cr);
		}
		for (auto &x : V)printf("%d ", x + 1); puts("");
	

}