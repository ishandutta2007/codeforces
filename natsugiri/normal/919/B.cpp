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
VI ans;

void rec(int cur, int sum, int ten) {
    if ((int)ans.size() >= N) return;

    if (ten == 0) {
	if (sum == 10) ans.push_back(cur);
    } else {
	for (int a=0; a<10 && a+sum <= 10; a++) {
	    rec(cur + a * ten, sum + a, ten/10);
	}
    }
}

void MAIN() {
    scanf("%d", &N);
    rec(0, 0, 100000000);
    printf("%d\n", ans[N-1]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}