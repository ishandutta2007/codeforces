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

int query(int pos) {
    printf("%d\n", pos);
    int t;
    fflush(stdout);
    scanf("%d", &t);
    if (t == 0) exit(0);
    return t;
}

int N, M;
int B[111];


void MAIN() {
    scanf("%d%d", &M, &N);
    REP (i, N) {
	B[i] = query(1);
    }
    int cnt = 0;
    int lo = 2, hi = M+1;
    while (hi - lo > 1) {
	int mid = (hi + lo) / 2;
	int t = query(mid);
	t *= B[cnt];
	if (t == 1) lo = mid+1;
	else hi = mid;

	cnt++;
	if (cnt == N) cnt = 0;
    }

    query(lo);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}