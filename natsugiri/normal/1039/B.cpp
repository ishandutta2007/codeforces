#include<random>
#include<chrono>
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

const int MAGIC = 42;

mt19937_64 engine;
LL N;
int K;

bool query(LL left, LL right) {
    printf("%lld %lld\n", left, right-1);
    fflush(stdout);
    char buf[111];
    scanf("%s", buf);
    return *buf == 'Y';
}

LL gen(LL left, LL right) {
    LL len = right - left;
    return engine() % len + left;
}

void MAIN() {
    int x = 0;

    {
	auto s = chrono::steady_clock::now();
	REP (i, 100000) x += i*i;
	auto d = chrono::steady_clock::now() - s;
	LL z = d.count();
	LL t = time(NULL);
//	eprintf("%lld %lld\n", z, t);
	engine = mt19937_64(z^t);
    }

    scanf("%lld%d", &N, &K);

    LL left = 1, right = N+1;
    REP (t, 4500) {
	if (right - left <= MAGIC) {
	    LL pos = gen(left, right);
	    bool b = query(pos, pos+1);
	    if (b) {
		return;
	    }
	} else {
	    LL mid = (left + right) / 2;
	    bool b = query(left, mid);

	    if (b) right = mid;
	    else left = mid;
	}
	left = max(1LL, left-K);
	right = min(N+1LL, right+K);
    }
    printf("%d\n", x);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}