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
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
const ll infl = -9000000000000000000LL;
const int N = 101010;
int a[N], v[N]; ll m[N];
int fi, sc;
void upd(int i, ll v) {
	
	if (i == fi) m[i] = v;
	else if (i == sc) {
		if (v > m[fi]) {
			swap(fi, sc);
			m[fi] = v;
		}
		else m[sc] = v;
	}
	else {
		if (fi == -1) {
			m[i] = v;
			fi = i;
			return;
		}
		else if (sc == -1) {
			m[i] = v;
			sc = i;
			if (m[fi] < m[sc])swap(fi, sc);
		}
		else {
			m[i] = v;
			if (v > m[sc]) {
				sc = i;
				if (m[fi] < m[sc])swap(fi, sc);
			}
			
		}
		
	}
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	int Q; ni(Q);
	F(i, n) {
		ni(v[i]);
	}
	F(i, n) {
		ni(a[i]); a[i]--;
	}
	F(q, Q) {
		F(i, n)m[i] = infl;
		fi = sc = -1;
		int x, y; nii(x, y);
		F(i, n) {
			ll ans = infl;
			//same
			if (m[a[i]] != infl) {
				ans = m[a[i]] + (ll)x*v[i];
			}
			//diff
			ans = max(ans, (ll)y*v[i]);
			if (fi!=-1) {
				int cur = fi;
				if (cur == a[i])cur = sc;
				if (cur != -1) {
					ans = max(ans, m[cur] + (ll)y*v[i]);
				}
			}
			if (m[a[i]] < ans) {
				upd(a[i], ans);
			}
		}
		ll ans = *max_element(m, m + n);
		printf("%I64d\n", max(ans, 0LL));
	}
	return 0;
}