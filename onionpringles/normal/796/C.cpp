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
#ifndef __GNUG__
int __builtin_popcount(int n) {
	int c = 0;
	while (n) {
		n -= n&(-n); c++;
	}
	return c;
}
#endif
#define FN "contest"
//----------------------------------------------------------------------------//

const int N = 300000;
int a[N];
vector<int> adj[N];
int c[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif

	int n; ni(n);
	F(i, n)ni(a[i]);
	F(i, n - 1) {
		int u, v; nii(u, v); u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int low = -mod;
	int high = mod;
	while (low != high) {
		int mid = (low + high >= 0) ? (low + high) / 2 : (low + high - 1) / 2;
		vector<int> A, B;
		bool bad = false;
		F(i, n) {
			if (mid < a[i]) {
				bad = true; break;
			}
			if (mid == a[i] + 1)A.push_back(i);
			else if (mid == a[i])B.push_back(i);
		}
		if (bad) {
			low = mid + 1;
			continue;
		}
		if (B.size() > 1) {
			low = mid + 1;
			continue;
		}
		F(i, n)c[i] = 0;
		for (auto &x : A) {
			for (auto &y : adj[x])c[y]++;
			c[x]++;
		}
		for (auto &x : B) {
			for (auto &y : adj[x])c[y]++;
			c[x]++;
		}
		int sz = A.size() + B.size();
		if (!B.empty()) {
			if (c[B[0]] != sz) {
				low = mid + 1;
			}
			else high = mid;
		}
		else {
			bool bad = false;
			F(i, n) {
				if (c[i] == sz) bad = true;
			}
			if (bad)high = mid;
			else low = mid + 1;
		}
	}
	printf("%d\n", low);
}