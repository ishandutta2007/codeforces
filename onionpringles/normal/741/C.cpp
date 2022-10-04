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

const int N = 100000;
int x[N<<1];
int chk[N << 1];
int ans[N << 1];
vector<pii> V;
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n) {
		int a, b; nii(a, b); a--; b--;
		V.emplace_back(a, b);
		x[a] = b; x[b] = a;
	}
	F(i, n << 1) {
		if (chk[i])continue;
		int cur = i;
		while (!chk[cur]) {
			ans[cur] = 0;
			chk[cur] = 1;
			cur = x[cur];
			ans[cur] = 1;
			cur = cur ^ 1;
		}
	}
	for (auto &p : V) {
		printf("%d %d\n", ans[p.first] + 1, ans[p.second] + 1);
	}
	return 0;
}