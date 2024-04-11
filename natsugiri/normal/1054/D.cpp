#include<map>
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

int N, K;
int A[200011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    const int mask = (1<<K)-1;
    int X = 0;
    map<int, int> mp;
    mp[0] = 1;
    LL tmp = 0;
    REP (i, N) {
	X ^= A[i];
	auto it0 = mp.find(X);
	auto it1 = mp.find(X^mask);
	int cnt0 = (it0 == mp.end()? 0: it0->second);
	int cnt1 = (it1 == mp.end()? 0: it1->second);
	if (cnt0 <= cnt1) {
	    tmp += i+1-cnt0;
	    mp[X]++;
	} else {
	    tmp += i+1-cnt1;
	    mp[X^mask]++;
	    X ^= mask;
	}
    }

    printf("%lld\n", tmp);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}