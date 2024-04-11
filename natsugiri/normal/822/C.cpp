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

int N, X;
struct Data {
    int l, r, c;
    bool operator<(const Data &y) const {
	return l < y.l;
    }
} D[200111];

struct CMP {
    bool operator()(const Data &x, const Data &y) const {
	return x.r > y.r;
    }
};
LL P[200111];

void MAIN() {
    scanf("%d%d", &N, &X);
    REP (i, N){
	int l, r, c;
	scanf("%d%d%d", &l, &r, &c);
	r++;
	D[i].l = l;
	D[i].r = r;
	D[i].c = c;
    }
    sort(D, D+N);

    memset(P, 0x3f, sizeof P);
    LL ans = P[0];
    priority_queue<Data, vector<Data>, CMP> Q;
    for (int i=0; i<N; i++) {
	while (Q.size() && Q.top().r <= D[i].l) {
	    Data d = Q.top(); Q.pop();
	    amin(P[d.r-d.l], (LL)d.c);
	}

	int k = X - (D[i].r - D[i].l);
	if (k > 0) {
	    amin(ans, D[i].c + P[k]);
	}
	Q.push(D[i]);
    }
    if (ans == P[0]) ans = -1;
    printf("%lld\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}