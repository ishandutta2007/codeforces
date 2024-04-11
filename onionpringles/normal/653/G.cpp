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
#include <tuple>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int fact[300001];
int inv[300001];
int invfact[300001];

int ncr(int n, int r) {
	return mul(mul(fact[n], invfact[n - r]), invfact[r]);
}

int modpow(int n, int e) {
	if (!e) return 1;
	int tm = modpow(n, e / 2);
	tm = mul(tm, tm);
	if (e % 2) tm = mul(tm, n);
	return tm;
}

vector<int>	exps[300001];
int coeff[300000];
int n;

int solve(vector<int>& v) {
	sort(v.begin(), v.end());
	int ans = 0;
	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		int tm = mul(coeff[n - sz + i], v[i]);
		ans += tm;
		if (ans >= mod) ans -= mod;
	}
	v = vector<int>();
	return ans;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ni(n);
	fact[0] = 1;
	for (int i = 1; i <= 300000; i++) fact[i] = mul(fact[i - 1], i);
	inv[1] = 1;
	for (int i = 2; i <= 300000; i++) inv[i] = mul(mod - mod / i, inv[mod%i]);
	invfact[0] = 1;
	for (int i = 1; i <= 300000; i++) invfact[i] = mul(invfact[i - 1], inv[i]);

	for (int i = 0; i < n; i++) {
		coeff[i] = ncr(n, i);
	}
	for (int i = 1; i < n; i++) {
		coeff[i] += coeff[i - 1];
		if (coeff[i] >= mod) coeff[i] -= mod;
	}
	int p2 = modpow(2, n - 1);
	for (int i = 0; i < n; i++) {
		coeff[i] -= p2;
		if (coeff[i] < 0) coeff[i] += mod;
	}

	for (int i = 0; i < n; i++) {
		int t; ni(t);
		for (int j = 2; j*j <= t; j++) {
			if (t%j != 0) continue;
			int cnt = 0;
			while (t%j == 0) {
				cnt++;
				t /= j;
			}
			exps[j].push_back(cnt);
		}
		if (t > 1) exps[t].push_back(1);
	}
	int res = 0;
	for (int i = 2; i <= 300000; i++) {
		if (exps[i].empty()) continue;
		res += solve(exps[i]);
		if (res >= mod) res -= mod;
	}
	printf("%d", res);
	return 0;
}