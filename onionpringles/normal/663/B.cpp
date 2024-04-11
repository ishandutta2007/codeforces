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
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

char buf[100];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int T; ni(T);
	while (T--) {
		scanf("%s", buf);
		int n = strlen(buf);
		int k = strstr(buf, "'") - buf;
		ll pp = 1;
		ll m = 1989;
		ll cur = 0;
		set<ll> S;
		for (int i = n - 1; i > k; i--) {
			cur += (buf[i] - '0') * pp;
			ll np = pp * 10;
			while (m%np != cur) m += pp;
			while (1) {
				auto p = S.insert(m);
				if (p.second) break;
				else m += np;
			}
			pp = np;
		}
		printf("%I64d\n", *S.rbegin());
	}
	return 0;
}