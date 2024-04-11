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

const int N = 100000;
ll a[N];
vector<ll> V[N];
int cnt[40];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)scanf("%lld", &a[i]);
	int l = 0;
	vector<ll> le;
	for (int j = 0; j < 40; j++) {
		while (l < n && a[l] < 1LL << j) {
			le.push_back(a[l]); l++;
		}
		if (l >= n || a[l] > 1LL << j) {
			for (; l < n; l++)le.push_back(a[l]); 
			break;
		}
		int r = l;
		while (r < n && a[r] == 1LL << j) r++;
		int k = 0;
		for (k = 0; k < min(r - l, j ? cnt[j - 1] : inf); k++) {
			V[k].push_back(1LL << j);
		}
		cnt[j] = k;
		for (; k < r - l; k++) le.push_back(1LL << j);
		l = r;
	}
	for (; l<n; l++)le.push_back(a[l]);
	sort(le.begin(), le.end(), greater<ll>());
	if ((int)le.size()>cnt[0]) {
		puts("-1");
		return 0;
	}
	int sz = le.size();
	for (int i = 0; i < sz; i++) {
		int j = V[i].size();
		if (1LL << j < le[i]) {
			puts("-1");
			return 0;
		}
	}
	int cr = 0;
	vector<int> ans;
	for (int i = cnt[0] - 1; i >= 0; i--) {
		if (cr + sz <= i + 1) {
			ans.push_back(i + 1);
		}
		cr += (int)V[i].size();
	}
	reverse(ans.begin(), ans.end());
	if (ans.empty())puts("-1");
	else {
		for (auto &x : ans)printf("%d ", x); puts("");
	}
	return 0;
}