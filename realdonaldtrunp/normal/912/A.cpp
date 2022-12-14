#include<iostream>
#include<cstdio>

#include "bits/stdc++.h"

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld)-1);
const int inf = (int) 1.01e9;
const ld eps = 1e-12;

#define sz(a) (int) (a).size()

#ifdef DEBUGGG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif



int main() {
	long long int a;  //y
	long long int b;  //b
	scanf("%lld%lld", &a, &b);
	long long int x, y, z;
	scanf("%lld%lld%lld", &x, &y, &z);
	a -= x * 2LL;
	a -= y;
	b -= y;
	b -= 3LL * z;
	long long int need = 0;
	if (a < 0) {
		need += -a;
	}
	if (b < 0) {
		need += -b;
	}
	printf("%lld\n", need);
	return 0;
}