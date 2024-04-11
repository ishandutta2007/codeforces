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
char S[200111], P[200111];
int A[200111];
bool use[200111];

int main() {
    scanf("%s%s", S, P);
    N = strlen(S);
    M = strlen(P);
    REP (i, N) scanf("%d", A+i), A[i]--;

    int lo = -1, hi = N - M + 1;
    while (hi - lo > 1) {
	int mid = (lo + hi) >> 1;

	memset(use, 0, sizeof use);
	REP (i, mid) use[A[i]] = true;
	int cnt = 0;
	REP (i, M) {
	    while (cnt < N && (use[cnt] || S[cnt] != P[i])) cnt++;
	    if (cnt == N) { cnt = -1; break; }
	    cnt++;
	}

	if (cnt == -1) hi = mid;
	else lo = mid;
    }

    printf("%d\n", lo);

    return 0;
}