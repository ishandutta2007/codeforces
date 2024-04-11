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

struct Data {
    int l, r, i;
    bool operator<(const Data &y) const {
	return r != y.r? r < y.r: l > y.l;
    }
} D[300011];
int N;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int l, r;
	scanf("%d%d", &l, &r);
	D[i].l = l;
	D[i].r = r;
	D[i].i = i;
    }

    sort(D, D+N);

    Data g = D[0];
    int k = 1;
    for (int i=1; i<N; i++) {
	while (k < i && D[k].r <= D[i].r) {
	    if (g.l < D[k].l) g = D[k];
	    k++;
	}

	if (D[i].l <= g.l && g.r <= D[i].r) {
	    printf("%d %d\n", g.i+1, D[i].i+1);
	    return;
	}
    }

    puts("-1 -1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}