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

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int N, M;
char F[1000011];
int deg[1000011];

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F + i*M);

    vector<pair<int, int> > stk;

    REP (i, N) REP (j, M) {
	int v = i*M+j;
	deg[v] = 0;

	if (F[v] == '.') {
	    REP (d, 4) {
		int y = i + dy[d];
		int x = j + dx[d];
		int w = y*M + x;
		if (in(y, x) && F[w] != '#') deg[v]++;
	    }
	} else if (F[v] == 'L') {
	    deg[v] = 0;
	    stk.emplace_back(i, j);
	} else {
	    deg[v] = -1;
	}
    }

    while (!stk.empty()) {
	int i = stk.back().first;
	int j = stk.back().second;
	stk.pop_back();
	int v = i*M+j;

	if (F[v] == '.') {
	    F[v] = '+';
	}

	REP (d, 4) {
	    int y = i + dy[d];
	    int x = j + dx[d];
	    int w = y*M + x;
	    if (in(y, x) && F[w] == '.') {
		deg[w]--;
		if (deg[w] == 0 || deg[w] == 1) {
		    stk.emplace_back(y, x);
		    deg[w] = -1;
		}
	    }
	}
    }

    REP (i, N) {
	REP (j, M) putchar(F[i*M+j]);
	putchar('\n');
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}