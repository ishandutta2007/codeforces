#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const LL LIMIT = 1e18;

const int MAX = 992;
int min_factor[MAX];
vector<int>prime;
void make_prime() {
    assert("Call once" && prime.empty());
    for (int i=2; i<MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i*i<MAX; i++) {
	if (min_factor[i] == 0) {
	    min_factor[i] = i;
	    for (int j=i*i; j<MAX; j+=i)
		if (min_factor[j] == 0) min_factor[j] = i;
	}
    }
    for (int i=2; i<MAX; i++) {
	if (min_factor[i] == 0) min_factor[i] = i;
	if (min_factor[i] == i) prime.push_back(i);
    }
}

const LL X = 234598761;
int CNT = 0;
LL query(LL Q) {
    CNT++;
    printf("? %lld\n", Q);
    fflush(stdout);

#ifdef MYTEST
    return __gcd(X, Q);
#endif
    LL r;
    scanf("%lld", &r);
    return r;
}


void MAIN() {
//    printf("%d\n", (int)prime.size());
//    rprintf("%d", prime.begin(), prime.end());

    CNT = 0;

    LL rest = 1e9;
    int i = 0;
    VI P;

    while (CNT < 22 && i < (int)prime.size() && prime[i]*prime[i]*prime[i] <= rest) {
	LL m = 1;
	int j = i;
	while (j < (int)prime.size() && m <= LIMIT/prime[j]) {
	    m *= prime[j];
	    j++;
	}

	// printf("%d %d : %lld\n", cnt, i, m);
	assert(m <= LIMIT);

	LL g = query(m);
	rest /= g;

	for (int k=i; k<j; k++) {
	    if (g % prime[k] == 0) P.push_back(prime[k]);
	}

	i = j;
    }

    eprintf("CNT %d\n", CNT);
    int ans = 0;
    if (P.empty()) {
	ans = 8;
    } else if (CNT == 22) {
	ans = (1<<P.size()) * 2;
    } else {
	i = 0;
	vector<int> Z(P.size());
	vector<LL> H(P.size());
	while (CNT < 22 && i < (int)P.size()) {
	    REP (j, P.size()) {
		H[j] = 1;
		while (rest >= H[j] * P[j]) {
		    H[j] *= P[j];
		}
	    }

	    int j = i;
	    LL m = 1;
	    while (j < (int)H.size() && m <= LIMIT/H[j]) {
		m *= H[j];
		j++;
	    }

	    LL g = query(m);
	    for (int k=i; k<j; k++) {
		int c = 0;
		while (g % P[k] == 0) {
		    g /= P[k];
		    c++;
		}
		Z[k] = c;

		rest *= P[k];
		REP (a, c) rest /= P[k];
	    }

	    i = j;
	}

	ans = 1;
	REP (j, Z.size()) ans *= max(2, Z[j] + 1);
	if (rest > 0) ans *= 2;
    }

    printf("! %d\n", ans);
    fflush(stdout);

    ans = 1;
    LL x = X;
    for (int i=2; i*i<=x; i++) {
	int c = 0;
	while (x % i == 0) {
	    c++;
	    x /= i;
	}
	ans *= c+1;
    }
    if (x > 1) ans *= 2;
    eprintf("! %d .\n", ans);
}

int main() {
    make_prime();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}