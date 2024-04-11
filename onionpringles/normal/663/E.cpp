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

const int N = 20;
const int M = 100010;

char buf[M];
int a[M], b[1 << N], c[1 << N];

#ifndef __GNUG__
int __builtin_popcount(int x) {
	int cnt = 0;
	while (x) x -= x&(-x), cnt++;
	return cnt;
}
#endif
template<typename A>
vector<ll> fft(A it, int lg) {
	if (!lg) return vector<ll>({ *it });
	int m = 1 << (lg - 1);
	vector<ll> ret(m << 1);
	auto a = fft(it, lg - 1);
	auto b = fft(it + m, lg - 1);
	F(i, m) {
		ret[i << 1] = a[i] + b[i];
		ret[i << 1|1] = a[i] - b[i];
	}
	return ret;
}

int inv(int m) {
	if (m == 1)return 1;
	else return mul(mod - mod / m, inv(mod%m));
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, m; nii(n, m);
	F(i, n) {
		scanf("%s", buf);
		F(j, m) a[j] = 2 * a[j] + buf[j] - '0';
	}
	F(i, m)b[a[i]]++;
	F(i, (1 << n)) {
		int p = __builtin_popcount(i);
		c[i] = min(p, n - p);
	}
	auto bf = fft(b, n); auto cf = fft(c, n);
	F(i, (1 << n))bf[i] = cf[i]*bf[i];
	bf = fft(bf.begin(), n);
	F(i, (1 << n)) bf[i] = bf[i] / (1LL << n);
	printf("%d\n", (int)(*min_element(bf.begin(), bf.end())));
	return 0;
}