#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, M, A[2011], B[2011];

LL A2[4000111], B2[4000111];
int A2_STOP, B2_STOP;
LL sumsA[2011], sumsB[2011];

LL best, bestA, bestB;
int cost;

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%d", &M);
    REP (i, M) scanf("%d", B+i);

    REP (i, N) sumsA[i+1] = sumsA[i] + A[i];
    REP (i, M) sumsB[i+1] = sumsB[i] + B[i];

    best = llabs(sumsA[N] - sumsB[M]);
    cost = 0;
    bestA = sumsA[N];
    bestB = sumsB[M];
    
    REP (i, N) REP (j, M) {
	LL aa = sumsA[N] - A[i] * 2LL, bb = sumsB[M] - B[j] * 2LL;
	LL tmp = llabs(aa - bb);
	if (best > tmp) {
	    best = tmp;
	    cost = 1;
	    bestA = aa;
	    bestB = bb;
	}
    }

    REP (i, N) REP (j, i) A2[A2_STOP++] = sumsA[N] - A[i] * 2LL - A[j] * 2LL;
    REP (i, M) REP (j, i) B2[B2_STOP++] = sumsB[M] - B[i] * 2LL - B[j] * 2LL;
    sort(A2, A2+A2_STOP);
    sort(B2, B2+B2_STOP);

    {
	int j = 0;
	REP (i, A2_STOP) {
	    while (j < B2_STOP && B2[j] < A2[i]) j++;
	    REP (t, 2) {
		int J=j-t;
		if (J < 0 || B2_STOP <= J) continue;
		LL tmp = llabs(A2[i] - B2[J]);
		if (best > tmp) {
		    best = tmp;
		    cost = 2;
		    bestA = A2[i];
		    bestB = B2[J];
		}
	    }
	}
    }


    printf("%lld\n", best);
    printf("%d\n", cost);
    // eprintf("### %lld %lld\n", bestA, bestB);
    if (cost == 1) {
	REP (i, N) if (sumsA[N] - A[i] * 2LL == bestA) {
	    printf("%d ", i+1);
	    break;
	}
	REP (i, M) if (sumsB[M] - B[i] * 2LL == bestB) {
	    printf("%d\n", i+1);
	    break;
	}
    }
    if (cost == 2) {
	int aaa[2], bbb[2];
	REP (i, N) REP (j, i) if (sumsA[N] - A[i] * 2LL - A[j] * 2LL == bestA) {
	    aaa[0] = j;
	    aaa[1] = i;
	    break;
	}
	REP (i, M) REP (j, i) if (sumsB[M] - B[i] * 2LL - B[j] * 2LL == bestB) {
	    bbb[0] = j;
	    bbb[1] = i; 
	    break;
	}
	REP (t, 2) printf("%d %d\n", aaa[t]+1, bbb[t]+1);
	
    }
    return 0;
}