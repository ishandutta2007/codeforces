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
#define F(i,n) for(int i = 0; i < n; i++)
#define FF(i,n) for(int i = 1; i <= n; i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

vector<int> primes;
vector<int> chk;

int isprime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return 0;
	}
	return 1;
}
char buf[100];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 2; i <= 100; i++)if (isprime(i)) primes.push_back(i);
	primes.resize(19);
	chk.resize(19);
	for (int i = 0; i < 19; i++) {
		printf("%d\n", primes[i]);
		fflush(stdout);
		scanf("%s", buf);
		assert(!strcmp(buf, "yes") || !strcmp(buf, "no"));
		chk[i] = (buf[0] == 'y');
	}
	int haha = -1; int cnt = 0;
	for (int i = 0; i < 19; i++) {
		cnt += chk[i];
		if (chk[i]) haha = i;
	}
	if (cnt == 0) {
		puts("prime");
	}
	else if (cnt >= 2) {
		puts("composite");
	}
	else {
		int p = primes[haha];
		if (p*p > 100) {
			puts("prime");
		}
		else {
			printf("%d\n", p*p);
			fflush(stdout);
			scanf("%s", buf);
			if (buf[0] == 'y') puts("composite");
			else puts("prime");
		}
	}



	return 0;
}