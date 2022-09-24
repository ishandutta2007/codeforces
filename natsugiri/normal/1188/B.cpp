#include<map>
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL powmod(LL x, LL y, LL mod) {
    x %= mod;
    LL r = 1;
    for (; y; y>>=1) {
	if (y & 1) r *= x %= mod;
	x *= x %= mod;
    }
    return r;
}


int N;
LL P, K;

LL get_key(LL a) {
    LL key = powmod(a, 4, P) - K * a;
    key %= P;
    if (key < 0) key += P;
    return key;
}
int A[300011];

void MAIN() {
    scanf("%d%lld%lld", &N, &P, &K);
    REP (i, N) scanf("%d", A+i);

    sort(A, A+N);
    vector<pair<LL, LL> > mp;
    REP (i, N) {
	mp.emplace_back(get_key(A[i]), 0LL);
    }
    sort(mp.begin(), mp.end());
    mp.erase(unique(mp.begin(), mp.end()), mp.end());

    LL ans = 0;

    for (int i=0; i<N; ) {
	int j = i;
	while (j < N && A[i] == A[j]) j++;

	LL key = get_key(A[i]);

	int pos = lower_bound(mp.begin(), mp.end(), make_pair(key, 0LL)) - mp.begin();

	ans += mp[pos].second * (j-i);
	mp[pos].second += j-i;

	if (4*powmod(A[i], 3, P) % P == K) {
	    ans += (LL)(j-i) * (j-i-1) / 2;
	}

	i = j;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}