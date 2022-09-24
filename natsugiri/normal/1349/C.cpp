#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

int N, M, T;
char F[1011][1011];
int D[1011][1011];

int in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &T);
    REP (i, N) scanf("%s", F[i]);

    memset(D, -1, sizeof D);
    REP (i, N) REP (j, M) {
	if (i && F[i-1][j] == F[i][j]) {
	    D[i-1][j] = D[i][j] = 0;
	}
	if (j && F[i][j-1] == F[i][j]) {
	    D[i][j-1] = D[i][j] = 0;
	}
    }

    vector<pair<int, int> > que;
    REP (i, N) REP (j, M) {
	if (D[i][j] == 0) que.emplace_back(i, j);
    }

    for (int k=0; k<(int)que.size(); k++) {
	int i = que[k].first;
	int j = que[k].second;
	REP (d, 4) {
	    int y = i + dy[d];
	    int x = j + dx[d];
	    if (in(y, x) && D[y][x] == -1) {
		D[y][x] = D[i][j]+1;
		que.emplace_back(y, x);
	    }
	}
    }

    REP ($, T) {
	int i, j;
	LL p;
	scanf("%d%d%lld", &i, &j, &p);
	i--; j--;

	int ans = F[i][j] - '0';
	if (D[i][j] == -1) {

	} else if (p <= D[i][j]) {

	} else {
	    p -= D[i][j];
	    if (p & 1) ans ^= 1;
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