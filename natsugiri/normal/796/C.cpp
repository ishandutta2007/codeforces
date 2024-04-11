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

int A[300111];
int S[300111];
VI G[300111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[y].push_back(x);
	G[x].push_back(y);
    }
    REP (i, N) S[i] = A[i];
    sort(S, S+N);
    reverse(S, S+N);
    int ans = 1.1e9;

    VI v; v.reserve(N);
    REP (r, N) {
	int tmp = A[r];
	v.clear();
	v.push_back(A[r]);
	EACH (e, G[r]) {
	    v.push_back(A[*e]);
	    amax(tmp, A[*e] + 1);
	}
	sort(v.rbegin(), v.rend());

	int stop = 0;
	REP (i, v.size()) {
	    if (v[i] < S[stop]) {
		amax(tmp, S[stop] + 2);
		break;
	    }
	    if (v[i] == S[stop]) stop++;
	}
	if (stop < N) amax(tmp, S[stop] + 2);

	amin(ans, tmp);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}