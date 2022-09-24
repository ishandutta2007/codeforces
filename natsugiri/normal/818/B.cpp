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
int A[111];
int L[111];
bool use[111];

bool is_perm() {
    memset(use, 0, sizeof use);
    REP (i, N) if (A[i] >= 0) use[A[i]] = true;
    return N == count(use, use + N, true);
}
bool ok() {
    for (int i=1; i<M; i++) {
	int cur = L[i-1];
	if ((cur + A[cur]) % N != L[i]) return false;
    }
    return true;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d", L+i), L[i]--;

    memset(A, -1, sizeof A);
    for (int i=1; i<M; i++) {
	int cur = L[i-1];
	A[cur] = (L[i] - cur + N) % N;
    }

    REP (i, N) if (A[i] >= 0) use[A[i]] = true;
    VI r;
    REP (i, N) if (!use[i]) r.push_back(i);

    if ((int)r.size() != count(A, A+N, -1)) {
	puts("-1");
	return;
    }

    for (int i=0, j=0; i<N; i++) if (A[i] == -1) {
	A[i] = r[j++];
    }

    if (!is_perm()) {
	puts("-1");
	return;
    }

    if (ok()) {
	REP (i, N) if (A[i] == 0) A[i] = N;
	rprintf("%d", A, A+N);
	return;
    } else {
	puts("-1");
	return;
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}