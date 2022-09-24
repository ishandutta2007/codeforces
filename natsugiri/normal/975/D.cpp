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
LL A, B;

struct Data {
    LL d;
    LL vx, vy;
    bool operator<(const Data &r) const {
	return d != r.d? d < r.d:
	    vx != r.vx? vx < r.vx:
	    vy < r.vy;
    }

    bool operator==(const Data &r) const {
	return d == r.d
	    && vx == r.vx
	    && vy == r.vy;
    }
} D[200011];

void MAIN() {
    scanf("%d%lld%lld", &N, &A, &B);
    REP (i, N) {
	LL x, y, vx, vy;
	scanf("%lld%lld%lld", &x, &vx, &vy);
	y = A * x + B;

	LL x1 = x + vx;
	LL y1 = y + vy;

	LL d = A * x1 - y1 + B;
	D[i].d = d;
	D[i].vx = vx;
	D[i].vy = vy;
    }

    sort(D, D+N);
    LL ans = 0;
    
    for (int i=0; i<N; ) {
	int j = i+1;
	while (j < N && D[i].d == D[j].d) j++;
	// [i, j)
	LL r = j-i;
	for (int a=i; a<j;) {
	    int b = a+1;
	    while (b < j && D[a] == D[b]) b++;
	    LL t = b-a;
	    ans += t * (r-t);
	    a = b;
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