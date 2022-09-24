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

int N;
int A[1000011];
double B[1000011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    vector<pair<LL, int> > stk;
    for (int i=N-1; i>=0; i--) {
	LL a = A[i], c = 1;
	while (!stk.empty()) {
	    if (a * stk.back().second > stk.back().first * c) {
		a += stk.back().first;
		c += stk.back().second;
		stk.pop_back();
	    } else {
		break;
	    }
	}
	stk.emplace_back(a, c);
    }

    {
	int i = 0;
	while (!stk.empty()) {
	    double val = (double)stk.back().first / stk.back().second;
	    REP (t, stk.back().second) B[i++] = val;
	    stk.pop_back();
	}
    }

    REP (i, N) printf("%.10f\n", B[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}