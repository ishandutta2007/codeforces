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


long long int n;
long long int k;

deque<long long int> d;

int main() {
	scanf("%lld%lld", &n, &k);
	long long int ans = 0;
	long long int pr = 1;
	if (k == 1LL) {
		printf("%lld\n", n);
		return 0;
	}
	 ans = 0;
	while (pr <= n) {
		d.push_back(pr);
		ans += pr;
		pr *= 2LL;
	}
	printf("%lld\n", ans);
	return 0;
}