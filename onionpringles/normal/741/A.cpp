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
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
const int N = 100;
int a[N]; int chk[N];
ll gcd(ll a, ll b) {
	if (!b)return a;
	else return gcd(b, a%b);
}
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n) {
		ni(a[i]); a[i]--;
	}
	vector<int> V;
	F(i, n) {
		if (chk[i])continue;
		int st = i;
		int cnt = 0;
		int j = i;
		while (!chk[j]) {
			chk[j] = 1;
			cnt++;
			j = a[j];
		}
		if (j != st) {
			puts("-1"); return 0;
		}
		if (cnt & 1)V.push_back(cnt);
		else V.push_back(cnt / 2);
	}
	long long x = 1;
	for (auto &y : V) {
		ll g = gcd(x, y);
		x /= g;
		x *= y;
	}
	printf("%I64d\n", x);

	return 0;
}