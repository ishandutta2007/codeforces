#pragma warning(disable:4996)

#include <stdio.h>
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
#define print(x) printf("%d\n", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

map<int, int> ind;
map<int, int> ind2;
map<int, int> lm;

const int N = 2*262144;
int tr[2 * N];
int ans[N];

void upd(int i, int val) {
	tr[N + i] = val;
	int cur = (N + i) / 2;
	while (cur) {
		tr[cur] = tr[2 * cur] + tr[2 * cur + 1] ;
		cur /= 2;
	}
}

int get(int l, int r) {
	int ans = 0;
	l += N;
	r += N;
	while (l / 2 != r / 2) {
		if (l % 2 == 0) {
			ans += tr[l + 1];
		}
		if (r % 2) ans += tr[r - 1];
		l /= 2; r /= 2;
	}
	return ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	F(i, n) {
		int a, b;
		nii(a, b);
		lm[b] = a;
		ind[a] = 0;
		ind[b] = 0;
		ind2[b] = i;
	}
	int j = 0;
	for (auto &x : ind) {
		x.second = j++;
	}
	for (auto &y : ind) {
		int x = y.first;
		if (ind2.find(x)!=ind2.end()) {
			int l = lm[x];
			l = ind[l];
			ans[ind2[x]] = get(l,ind[x]);
			upd(l, 1);
		}
	}
	F(i, n) {
		print(ans[i]);
	}


	
	return 0;
}