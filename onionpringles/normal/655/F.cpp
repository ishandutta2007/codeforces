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
#define F_(i,n) for(int i = 1; i <= (n); i++)
#define println(x) printf("%d\n", x)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 1000000;

int sieve[N + 1];
vector<int> prm;
int phi[N + 1];
int fact[N + 1];
int inv[N + 1];
int invfact[N + 1];

int tble[N + 1];

int ncr(int n, int r) {
	if (n < r || r < 0) return 0;
	int tm = fact[n];
	tm = mul(tm, invfact[n - r]);
	tm = mul(tm, invfact[r]);
	return tm;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sieve[0] = sieve[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (sieve[i]) continue;
		for (int j = i + i; j <= N; j += i) {
			sieve[j] = 1;
		}
		prm.push_back(i);
	}
	F_(i, N) {
		phi[i] = i;
	}
	for (auto &x : prm) {
		for (int i = x; i <= N; i += x) {
			phi[i] /= x;
			phi[i] *= x - 1;
		}
	}
	fact[0] = 1;
	F_(i, N) fact[i] = mul(fact[i - 1], i);
	inv[1] = 1;
	for (int i = 2; i <= N; i++) inv[i] = mul(mod - mod / i, inv[mod%i]);
	invfact[0] = 1;
	F_(i, N) invfact[i] = mul(invfact[i - 1], inv[i]);

	int n, k, q;
	nii(n, k); ni(q);
	F(i, n) {
		int x; ni(x);
		int j;
		for (j = 1; j*j < x; j++) {
			if (x%j == 0) {
				tble[j]++;
				tble[x / j]++;
			}
		}
		if (j*j == x) tble[j]++;
	}
	int ans = 0;
	F_(i, N) {
		if (tble[i] >= k) {
			ans += mul(phi[i], ncr(tble[i], k));
			if (ans >= mod) ans -= mod;
		}
	}
	F(tt, q) {
		int x;  ni(x);
		int j;
		for (j = 1; j*j < x; j++) {
			if (x%j == 0) {
				ans += mul(phi[j], ncr(tble[j], k - 1));
				if (ans >= mod) ans -= mod;
				ans += mul(phi[x / j], ncr(tble[x / j], k - 1));
				if (ans >= mod) ans -= mod;
				tble[j]++;
				tble[x / j]++;
			}
		}
		if (j*j == x) {
			ans += mul(phi[j], ncr(tble[j], k - 1));
			if (ans >= mod) ans -= mod;
			tble[j]++;
		}
		println(ans);
	}

	return 0;
}