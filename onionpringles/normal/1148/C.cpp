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
const int mod = 1000003;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 301010;
int a[N], r[N];

vector<pii> V;
void Do(int i, int j) {
	V.emplace_back(i + 1, j + 1);
	int x = a[i], y = a[j];
	swap(r[x], r[y]);
	swap(a[i], a[j]);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	int n; ni(n);
	F(i, n)ni(a[i]), a[i]--;
	F(i, n)r[a[i]] = i;
	for (int i = 1; i < n - 1; i++) {
		if (i == a[i])continue;
		int j = r[i];
		if (abs(i - j) >= n / 2)Do(i, j);
		else if (i >= n / 2 && j >= n / 2) {
			Do(0, j);
			Do(0, i);
		}
		else if (i < n / 2 && j < n / 2) {
			Do(n - 1, j);
			Do(n - 1, i);
		}
		else if(i < j){
			Do(0, j);
			Do(0, n - 1);
			Do(i, n - 1);
		}
		else {
			Do(n - 1, j);
			Do(0, n - 1);
			Do(i, 0);
			swap(i, j);
		}
	}
	if (a[0] != 0)Do(0, n - 1);
	printf("%d\n", (int)V.size());
	for (auto &x : V)printf("%d %d\n", x.first, x.second);
}