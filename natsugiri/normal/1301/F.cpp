#include<deque>
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M, K;
int A[1011][1011];
int D[1000051];
int E[40][1011][1011];

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) REP (j, M) {
	scanf("%d", A[i]+j);
	A[i][j]--;
    }


    REP (k, K) {
	memset(D, 0x3f, sizeof D);
	D[N*M+k] = 0;
	deque<int> dq;
	dq.push_back(N*M+k);
	while (dq.size()) {
	    int key = dq.front(); dq.pop_front();
	    if (key < N*M) {
		int i = key/M;
		int j = key%M;
		REP (dir, 4) {
		    int y = i + dy[dir];
		    int x = j + dx[dir];
		    if (in(y, x) && D[y*M+x] > D[key]+1) {
			D[y*M+x] = D[key] + 1;
			dq.push_back(y*M+x);
		    }
		}
		if (D[N*M+A[i][j]] > D[key]+1) {
		    D[N*M+A[i][j]] = D[key]+1;
		    dq.push_back(N*M+A[i][j]);
		}
	    } else {
		int c = key - N*M;
		REP (i, N) REP (j, M) if (A[i][j] == c && D[i*M+j] > D[key]) {
		    D[i*M+j] = D[key];
		    dq.push_front(i*M+j);
		}
	    }
	}
	REP (i, N) REP (j, M) E[k][i][j] = D[i*M+j];
    }

    int Q;
    scanf("%d", &Q);
    REP (i, Q) {
	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	r1--; c1--;
	r2--; c2--;
	int ans = abs(r1-r2) + abs(c1-c2);
	REP (k, K) {
	    amin(ans, E[k][r1][c1] + E[k][r2][c2] + 1);
	}

	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}