#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N, M;

int A[200011];
int idx[200011];

bool LT(int i, int j) {
    REP (k, N) {
	if (A[k*M+i] != A[k*M+j]) return A[k*M+i] < A[k*M+j];
    }
    return i < j;
}
bool EQ(int i, int j) {
    REP (k, N) {
	if (A[k*M+i] != A[k*M+j]) return false;
    }
    return true;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N*M) scanf("%d", A+i);


    REP (j, M) idx[j] = j;
    sort(idx, idx+M, LT);

    bool lt = true;
    REP (j, M-1) {
	REP (k, N) {
	    if (A[k*M+idx[j]] > A[k*M+idx[j+1]]) lt = false;
	}
    }

    if (!lt) {
	puts("-1");
	return;
    }

    VI X;
    
    for (int i=0; i<M; ) {
	int j = i;
	while (j < M && EQ(idx[i], idx[j])) j++;

	for (int k=i; k<j; k++) {
	    if (idx[k] < i || j <= idx[k]) X.push_back(idx[k]);
	}

	i = j;
    }

    if (X.size() <= 1u) {
	puts("1 1");
    } else if (X.size() == 2u) {
	sort(X.begin(), X.end());
	printf("%d %d\n", X[0]+1, X[1]+1);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}