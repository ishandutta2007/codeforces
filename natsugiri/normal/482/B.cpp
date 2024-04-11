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
int L[100111], R[100111], Q[100111];
int C[100111];
int A[100111];
int T[20][100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d%d%d", L+i, R+i, Q+i), L[i]--;
    REP (t, 31) {
	memset(C, 0, sizeof C);
	REP (i, M) if (Q[i] & (1<<t)) {
	    C[L[i]]++;
	    C[R[i]]--;
	}
	REP (i, N) C[i+1] += C[i];
	REP (i, N) if (C[i]) A[i] |= 1<<t;
    }


    REP (i, N) T[0][i] = A[i];
    REP (t, 19) REP (i, N) if (i + (2<<t) <= N) T[t+1][i] = T[t][i] & T[t][i+(1<<t)];
    
    bool yes = true;
    REP (i, M) {
	int g = __lg(R[i] - L[i]);
	int v = T[g][L[i]] & T[g][R[i] - (1<<g)];
	if (Q[i] != v) yes = false;
    }

    if (yes) {
	puts("YES");
	rprintf("%d", A, A+N);
    } else {
	puts("NO");
    }

    return 0;
}