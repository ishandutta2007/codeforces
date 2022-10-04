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

#ifndef __GNUG__
int __builtin_popcount(int n) {
	int x = 0;
	while (n)n -= n&(-n), x++;
	return x;
}
#endif

map<int,int> get(ll& n, bool s = false) {
	int a[3];
	F(t, 3)ni(a[t]);
	if (s)a[0] *= 2;
	n = 1;
	F(t, 3){
		n *= a[t];
	}
	map<int, int> pf;
	F(t, 3) {
		for (int i = 2; i*i <= a[t]; i++) {
			if (a[t]%i == 0) {
				while (a[t]%i == 0) {
					pf[i]++;
					a[t] /= i;
				}
			}
		}
		if (a[t] > 1) pf[a[t]]++;
	}
	return pf;
}
ll P(ll n, int e) {
	if (!e)return 1;
	ll t = P(n, e / 2);
	t = t*t;
	if (e & 1)t = t*n;
	return t;
}

int ans = 0;

void gen(ll cur, const vector<pii>& V, ll ub, int i) {
	if (i == V.size()) {
		if (cur <= ub) ans++;
		return;
	}
	ll pp = 1;
	for (int j = 0; j <= V[i].second; j++) {
		gen(cur*pp, V, ub, i + 1);
		pp *= V[i].first;
	}
}

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int solve(int n, int m, int s) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)if (s%gcd(i, m) == 0)cnt++;
	printf("HI %d\n", cnt);
	for (int i = 1; i <= m; i++)if (s%i == 0)cnt++;
	return cnt;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int T; ni(T);
	while (T--) {
		ll n, m, s;
		auto mv = get(m);
		auto nv = get(n);
		auto sv = get(s, true);
		vector<ll> V;
		for (auto &x : mv) {
			int e;
			if (sv.count(x.first)) {
				if (x.second <= sv[x.first]) continue;
				e = sv[x.first];
			}
			else e = 0;
			ll pp = P(x.first, e);
			if (pp <= n / x.first) {
				V.emplace_back(pp*x.first);
			}
		}
		int sz = V.size();
		ll tot = 0;
		F(ms, 1 << sz) {
			ll x = n;
			F(j, sz) {
				if (ms&(1 << j)) {
					x /= V[j];
				}
			}
			if (__builtin_popcount(ms) & 1)tot -= x;
			else tot += x;
		}
		ans = 0;
		vector<pii> ps;
		for (auto &x : sv) {
			ps.push_back(x);
		}
		gen(1, ps, m, 0);
		printf("%lld\n", tot + ans);
		//printf("%d\n", solve((int)n, (int)m, (int)s));
		//assert(tot + ans == solve((int)n, (int)m, (int)s));
	}
	return 0;
}