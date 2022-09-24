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

int N;
LL D;
LL A[111];
vector<LL> guess;
void go(LL x) {
    LL mi = abs(x - A[0]);
    REP (i, N) {
	if (x == A[i]) return ;
	amin(mi, abs(x - A[i]));
    }

    if (mi == D) guess.push_back(x);
}

void MAIN() {
    scanf("%d%lld", &N, &D);
    REP (i, N) scanf("%lld", A+i);

    REP (i, N) {
	go(A[i] - D);
	go(A[i] + D);
    }
    sort(guess.begin(), guess.end());
    guess.erase(unique(guess.begin(), guess.end()), guess.end());
    printf("%d\n", (int)guess.size());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}