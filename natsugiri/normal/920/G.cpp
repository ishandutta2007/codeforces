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

const int MAX = 1000111;
int min_factor[MAX+1];
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
}

int mu[MAX];
void init() {
    REP (i, MAX) {
	mu[i] = 1;
    }
    EACH (e, prime) {
	LL d = *e;
	for (LL i=d; i<MAX; i+=d) {
	    mu[i] = -mu[i];
	}
	d *= d;
	for (LL i=d; i<MAX; i+=d) {
	    mu[i] = 0;
	}
    }
}


vector<int> D;
LL F(LL Z) {
    LL ret = 0;
    EACH (e, D) {
	if (mu[*e]) ret += Z / *e * mu[*e];
    }
    return ret;
}


struct Data {
    int x, k, i;
};
vector<Data> G[1000111];
LL ans[30011];

void MAIN() {
    int T;
    scanf("%d", &T);
    REP (i, T) {
	int X, P, K;
	scanf("%d%d%d", &X, &P, &K);
	G[P].push_back((Data){X, K, i});
    }

    REP (p, 1000111) if (G[p].size()) {
	D.clear();
	for (int i=1; i*i<=p; i++) {
	    if (p%i == 0) {
		if (mu[i]) D.push_back(i);
		if (i*i < p && mu[p/i]) D.push_back(p / i);
	    }
	}

	EACH (e, G[p]) {
	    int head = F(e->x);
	    LL lo = e->x, hi = e->x + 1;
	    while (F(hi) - head < e->k) {
		lo = hi;
		hi *= 2;
	    }
	    while (hi - lo > 1) {
		LL mid = (lo + hi) / 2;
		if (F(mid) - head < e->k) lo = mid;
		else hi = mid;
	    }

	    ans[e->i] = hi;
	}
    }

    REP (i, T) {
	printf("%lld\n", ans[i]);
    }
}

int main() {
    make_prime();
    init();
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}