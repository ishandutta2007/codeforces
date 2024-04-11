#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
int A[1011][1011];
int B[1011][1011];
int aux[1011];

char S[100011];

void I() {
    REP (i, N) {
	REP (j, N) aux[A[i][j]] = j;
	REP (j, N) A[i][j] = aux[j];
    }
}

void C() {
    REP (j, N) {
	REP (i, N) aux[A[i][j]] = i;
	REP (i, N) A[i][j] = aux[i];
    }
}

pair<int, int> P[3];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, N) scanf("%d", A[i]+j), A[i][j]--;
    scanf("%s", S);

    REP (a, 3) P[a] = make_pair(a, 0);

    REP (i, M) {
	if (S[i] == 'R') P[1].second++;
	else if (S[i] == 'L') P[1].second--;
	else if (S[i] == 'D') P[0].second++;
	else if (S[i] == 'U') P[0].second--;
	else if (S[i] == 'I') swap(P[1], P[2]);
	else if (S[i] == 'C') swap(P[0], P[2]);
    }

    int X[3], Y[3];
    REP (i, N) REP (j, N) {
	X[0] = i;
	X[1] = j;
	X[2] = A[i][j];
	REP (a, 3) {
	    Y[a] = X[P[a].first] + P[a].second;
	    Y[a] %= N;
	    if (Y[a] < 0) Y[a] += N;
	}
	
	B[Y[0]][Y[1]] = Y[2] + 1;
    }

    REP (i, N) rprintf("%d", B[i], B[i]+N);
    puts("");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}