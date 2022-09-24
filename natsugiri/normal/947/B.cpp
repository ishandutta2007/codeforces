#include<queue>
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

const int MAXN = 100011;
int N;
LL V[MAXN], T[MAXN];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", V+i);
    REP (i, N) scanf("%lld", T+i);

    LL melt = 0;
    priority_queue<LL> Q;
    REP (i, N) {
	LL ans = 0;
	Q.push(-(V[i] + melt));
	while (!Q.empty()) {
	    LL rest = -Q.top() - melt;
	    if (rest <= T[i]) {
		ans += rest;
		Q.pop();
	    } else {
		break;
	    }
	}

	ans += (LL)Q.size() * T[i];
	melt += T[i];


	printf("%lld%c", ans, " \n"[i==N-1]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}