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

int N, M;
int A[100111];
VI G[100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d", A+i);
    LL sum = 0, ans;
    REP (i, M-1) sum += abs(A[i+1] - A[i]);
    ans = sum;

    REP (i, M) {
	if (i && A[i-1] != A[i]) G[A[i]].push_back(A[i-1]);
	if (i < M - 1 && A[i+1] != A[i]) G[A[i]].push_back(A[i+1]);
    }
    REP (i, N+1) if (G[i].size()) {
	sort(G[i].begin(), G[i].end());
	LL diff = 0;
	LL lcnt = 0, rcnt = G[i].size(), lsum = 0, rsum = 0;
	EACH (e, G[i]) {
	    diff += abs(*e - i);
	    rsum += *e;
	}
	EACH (e, G[i]) {
	    lcnt++;
	    rcnt--;
	    lsum += *e;
	    rsum -= *e;
	    amin(ans, sum - diff + rsum - rcnt * *e + lcnt * *e - lsum);
	}
    }

    printf("%lld\n", ans);



    return 0;
}