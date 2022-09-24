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

int N, X;

void MAIN() {
    scanf("%d%d", &N, &X);

    VI ans; ans.reserve(N);
    if (N == 2 && X == 0) {
	puts("NO");
	return;
    } 

    if (N == 1) {
	ans.push_back(X);
    } else {
	int z = 0;
	for (int i=1; i<N; i++) {
	    ans.push_back(i);
	    z ^= i;
	}

	if ((X^z) >= N) {
	    ans.push_back(X^z);
	} else if ((X^z) == 1) {
	    ans[1] |= 1<<17;
	    ans.push_back(X ^ z ^ (1<<17));
	} else {
	    ans[0] |= 1<<17;
	    ans.push_back(X ^ z ^ (1<<17));
	}
    }

    puts("YES");
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}