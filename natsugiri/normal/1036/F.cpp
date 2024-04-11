#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL sqrtll(LL n) {
    LL lo = 0, hi = 1;
    while (n / hi >= hi) {
	lo = hi;
	hi += hi;
    }
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	if (mid * mid <= n) lo = mid;
	else hi = mid;
    }
    return lo;
}
//LL cbrtll(LL n) {
//    LL lo = 0, hi = 1;
//    while (n/(hi*hi) >= hi) {
//	lo = hi;
//	hi += hi;
//    }
//    while (hi - lo > 1) {
//	LL mid = (lo + hi) / 2;
//	if (mid * mid * mid <= n) lo = mid;
//	else hi = mid;
//    }
//    return lo;
//}
LL safe_pow(LL x, int y) {
    if (x == 0) return 0;
    LL v = 2e18;
    REP (i, y) v /= x;
    if (v == 0) return 2e18;
    v = 1;
    REP (i, y) v *= x;
    return v;
}


const int MAX = 100;
int min_factor[MAX+1];
int mu[MAX+1];
vector<int>prime;
void make_prime() {
    for (int i=2; i<=MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i<=MAX; i+=3) if (!min_factor[i]) min_factor[i] = 3;
    for (int i=5, d=2; i*i<=MAX; ) {
	if (!min_factor[i]) {
	    min_factor[i] = i;
	    for (int j=i*i; j<=MAX; j+=i)
		if (!min_factor[j]) min_factor[j] = i;
	}
	i += d; d = 6 - d;
    }
    for (int i=2; i<=MAX; i++) {
	if (min_factor[i]==0) min_factor[i] = i;
	if (min_factor[i]==i) prime.push_back(i);
    }
    REP (i, MAX+1) mu[i] = 1;

    EACH (e, prime) {
	for (int i=*e; i<=MAX; i+=*e) mu[i] *= -1;
	LL d = (LL)*e**e;
	if (d > MAX) continue;
	for (int i=d; i<=MAX; i+=d) mu[i] = 0; 
    }
}
vector<LL> Z[62];
void init() {
    for (int t=61; t>=3; t--) {
	if (mu[t] == 0) continue;
	for (int i=0; ; i++) {
	    LL x = safe_pow(i, t);
	    if (x == 2e18) break;
	    Z[t].push_back(x);
	}
    }
}


void MAIN() {
    LL N;
    scanf("%lld", &N);
    LL ans = N-1;
    for (int t=61; t>=3; t--) {
	if (mu[t] == 0) continue;
	int pos = upper_bound(Z[t].begin(), Z[t].end(), N) - Z[t].begin();
	ans += mu[t] * (pos-2);
    }

    ans -= sqrtll(N)-1;
    printf("%lld\n", ans);
}

int main() {
    make_prime();
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}