#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

const int MAX = 10000011;
int min_factor[MAX];
vector<int>prime;
bool init_prime() {
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
    return true;
}

vector<pair<LL, int> > prime_factor(LL n) {
    assert(n <= (LL)MAX * MAX);
    vector<pair<LL, int> > ret;
    REP (i, prime.size()) {
	if (n < MAX) break;
	if (n < (LL)prime[i] * prime[i]) break;
	int cnt = 0;
	while (n % prime[i] == 0) {
	    n /= prime[i];
	    cnt++;
	}
	if (cnt) ret.emplace_back(prime[i], cnt);
    }
    if (MAX <= n) {
	ret.emplace_back(n, 1);
    } else {
	while (1 < n) {
	    int p = min_factor[n], cnt = 0;
	    while (n % p == 0) { n /= p, cnt++; }
	    ret.emplace_back(p, cnt);
	}
    }
    return ret;
}

bool normal(int X) {
    auto xs = prime_factor(X);
    int cnt = 0;
    EACH (e, xs) {
	cnt += e->second;
    }
    return cnt >= 2;
}

void MAIN() {
    LL X, D;
    scanf("%lld%lld", &X, &D);
    
    bool yes;
    if (X % (D * D) == 0) {
	X /= (D * D);
	auto ds = prime_factor(D);

	if (ds.size() == 1u) {
	    int p = ds[0].first;
	    if (ds[0].second == 1) {
		while (X % D == 0) X /= D;
		yes = normal(X);
	    } else if (ds[0].second == 2 && X == (LL)p * p * p) {
		yes = false;
	    } else {
		yes = normal(X);
	    }
	} else {
	    yes = normal(X);
	}
    } else {
	yes = false;
    }

    puts(yes?"YES":"NO");
}


int main() {
    init_prime();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}