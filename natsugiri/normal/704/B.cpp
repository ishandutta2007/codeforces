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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, S, E;
LL dp[2][2511][2][2];
LL (*cur)[2][2];
LL (*nxt)[2][2];
int X[5011];
int A[5011];
int B[5011];
int C[5011];
int D[5011];


int main() {
    cur = dp[0];
    nxt = dp[1];
    scanf("%d%d%d", &N, &S, &E);
    S--; E--;

    REP (i, N) scanf("%d", X+i);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);
    REP (i, N) scanf("%d", C+i);
    REP (i, N) scanf("%d", D+i);

    memset(cur, 0x3f, sizeof (LL [2511][2][2]));
    cur[0][0][0] = 0;

    REP (i, N) {
	memset(nxt, 0x3f, sizeof (LL [2511][2][2]));
	REP (c, min(i+1, N / 2 + 1)) REP (l, 2) REP (r, 2) {
	    LL cost = cur[c][l][r];
	    if (cost == nxt[0][0][0]) continue;

	    if (i > 0) cost += (LL)(X[i] - X[i-1]) * (c * 2 + l + r);

	    if (i == S) {
		if (r == 0) {
		    if (c > 0) amin(nxt[c-1][l][1], cost + C[i]);
		    amin(nxt[c][l][1], cost + D[i]);
		    if (i == N-1 && l == 1 && c == 0) amin(nxt[0][0][0], cost + C[i]);
		}
	    } else if (i == E) {
		if (l == 0) {
		    if (c > 0) amin(nxt[c-1][1][r], cost + A[i]);
		    amin(nxt[c][1][r], cost + B[i]);
		    if (i == N-1 && r == 1 && c == 0) amin(nxt[0][0][0], cost + A[i]);
		}
	    } else {
		// -> o ->
		if (c > 0 || r > 0) amin(nxt[c][l][r], cost + A[i] + D[i]);

		// <- o <-
		if (c > 0 || l > 0) amin(nxt[c][l][r], cost + B[i] + C[i]);

		// -> o, <- o
		if (c > 1) amin(nxt[c-1][l][r], cost + A[i] + C[i]);
		if (c > 0 && l > 0) amin(nxt[c-1][l][r], cost + A[i] + C[i]);
		if (c > 0 && r > 0) amin(nxt[c-1][l][r], cost + A[i] + C[i]);
		if (i == N-1 && c == 0 && l > 0 && r > 0) amin(nxt[0][0][0], cost + A[i] + C[i]);

		amin(nxt[c+1][l][r], cost + B[i] + D[i]);
	    }
	}

	swap(cur, nxt);
    }


    printf("%lld\n", cur[0][0][0]);

    return 0;
}