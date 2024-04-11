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
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 200000;
pii cl[N];
int p[N];
set<pii> S[4];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)ni(p[i]);
	F(i, n)ni(cl[i].first);
	F(i, n)ni(cl[i].second);
	F(i, n) {
		S[cl[i].first].insert(pii(p[i], i));
		S[cl[i].second].insert(pii(p[i], i));
	}
	int m; ni(m);
	F(i, m) {
		int x; ni(x);
		if (S[x].empty()) {
			printf("-1 "); continue;
		}
		printf("%d ", S[x].begin()->first);
		int j = S[x].begin()->second;
		S[cl[j].first].erase(pii(p[j], j));
		S[cl[j].second].erase(pii(p[j], j));
	}
	puts("");
	return 0;
}