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
char buf[111];
bool X[111][111];

VI ans;
void add(int y1, int x1, int y2, int x2, int y3, int x3) {
    X[y1][x1] = !X[y1][x1];
    X[y2][x2] = !X[y2][x2];
    X[y3][x3] = !X[y3][x3];

    ans.push_back(y1);
    ans.push_back(x1);
    ans.push_back(y2);
    ans.push_back(x2);
    ans.push_back(y3);
    ans.push_back(x3);
}

void MAIN() {
    ans.clear();
    scanf("%d%d", &N, &M);
    REP (i, N) {
	scanf("%s", buf);
	REP (j, M) X[i][j] = (buf[j] == '1');
    }

    REP (i, N-2) {
	REP (j, M-1) if (X[i][j]) {
	    if (X[i][j+1]) {
		add(i, j, i, j+1, i+1, j);
	    } else {
		add(i, j, i+1, j, i+1, j+1);
	    }
	}
	if (X[i][M-1]) {
	    int j = M-2;
	    add(i, j+1, i+1, j, i+1, j+1);
	}
    }

    {
	int i = N-2;
	REP (j, M-1) {
	    if (X[i][j] && X[i+1][j]) {
		add(i, j, i+1, j, i, j+1);
	    } else if (X[i][j]) {
		add(i, j, i, j+1, i+1, j+1);
	    } else if (X[i+1][j]) {
		add(i+1, j, i, j+1, i+1, j+1);
	    }
	}
    }

    {
	int i = N-2;
	int j = M-2;
	if (X[i][j+1] && X[i+1][j+1]) {
	    add(i, j, i+1, j, i, j+1);
	    add(i, j, i+1, j, i+1, j+1);
	} else if (X[i][j+1]) {
	    add(i, j+1, i, j, i+1, j);
	    add(i+1, j+1, i, j+1, i, j);
	    add(i+1, j, i+1, j+1, i, j+1);
	} else if (X[i+1][j+1]) {
	    add(i+1, j+1, i, j+1, i, j);
	    add(i+1, j, i+1, j+1, i, j+1);
	    add(i, j, i+1, j, i+1, j+1);
	}
    }

    REP (i, N) REP (j, M) assert(!X[i][j]); 

    printf("%d\n", (int)ans.size() / 6);
    for (int i=0; i<(int)ans.size(); ) {
	int y1 = ans[i++] + 1;
	int x1 = ans[i++] + 1;
	int y2 = ans[i++] + 1;
	int x2 = ans[i++] + 1;
	int y3 = ans[i++] + 1;
	int x3 = ans[i++] + 1;
	printf("%d %d %d %d %d %d\n", y1, x1, y2, x2, y3, x3);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}