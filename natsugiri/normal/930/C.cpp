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
int S[100111];
int L[100111], R[100111];
int lis[100111];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int l, r;
	scanf("%d%d", &l, &r);
	S[l-1]++;
	S[r]--;
    }

    REP (i, M+10) S[i+1] += S[i];

    memset(lis, 0x3f, sizeof lis);
    REP (i, M) {
	int k = upper_bound(lis, lis+M, S[i]) - lis;
	L[i] = k;
	lis[k] = S[i];
    }
    memset(lis, 0x3f, sizeof lis);
    for (int i=M; i--;) {
	int k = upper_bound(lis, lis+M, S[i]) - lis;
	R[i] = k;
	lis[k] = S[i];
    }

    int ans = 0;
    REP (i, M) amax(ans, L[i] + R[i] + 1);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}