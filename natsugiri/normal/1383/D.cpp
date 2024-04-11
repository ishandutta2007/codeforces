#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<tuple>
#include<queue>

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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
int A[255][255];
int B[255][255];

int R[255], C[255];
bool use[100011];
bool in[255][255];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", &A[i][j]);

    REP (i, N) REP (j, M) {
	amax(R[i], A[i][j]);
	amax(C[j], A[i][j]);
    }

    sort(R, R+N);
    sort(C, C+M);

    int ri = N-1, ci = M-1;
    int pos_r = 0, pos_c = 0;

    while (1) {
	if (ri < 0 && ci < 0) break;
	int r_value = (ri < 0 ? -1: R[ri]);
	int c_value = (ci < 0 ? -1: C[ci]);
	if (r_value == c_value) {
	    B[pos_r][pos_c] = r_value;
	    pos_r++;
	    pos_c++;
	    ri--;
	    ci--;
	} else if (r_value < c_value) {
	    B[pos_r-1][pos_c] = c_value;
	    pos_c++;
	    ci--;
	} else {
	    B[pos_r][pos_c-1] = r_value;
	    pos_r++;
	    ri--;
	}
    }

    REP (i, N) REP (j, M) use[B[i][j]] = true;

    using Tuple = tuple<int, int, int>;
    priority_queue<Tuple> Q;
    auto update = [&](int i, int j) {
	if (B[i][j] == 0 && !in[i][j]) {
	    if (0 < i && j+1 < M && B[i-1][j] && B[i][j+1]) {
		in[i][j] = true;
		Q.emplace(min(B[i-1][j], B[i][j+1]), i, j);
	    }
	    if (i+1 < N && 0 < j && B[i+1][j] && B[i][j-1]) {
		in[i][j] = true;
		Q.emplace(min(B[i+1][j], B[i][j-1]), i, j);
	    }
	}
    };
    REP (i, N) REP (j, M) update(i, j);
    int idx = N*M;
    while (!Q.empty()) {
	int v, i, j;
	tie(v, i, j) = Q.top();
	Q.pop();
	while (use[idx]) idx--;
	B[i][j] = idx;
	use[idx] = true;
	if (i) update(i-1, j);
	if (j) update(i, j-1);
	if (i+1 < N) update(i+1, j);
	if (j+1 < M) update(i, j+1);
    }

    REP (i, N) rprintf("%d", B[i], B[i]+M);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}