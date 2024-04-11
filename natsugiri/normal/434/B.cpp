#include<cassert>
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

const int MAX = 1011;
// const int MAX = 5;

struct Field {
    bool F[MAX][MAX];
    int up[MAX][MAX];
    Field() {
	memset(F, 0, sizeof F);
    }

    void build() {
	memset(up, 0, sizeof up);
	REP (i, MAX) REP (j, MAX) {
	    if (F[i][j]) up[i][j] = (i? up[i-1][j] + 1: 1);
	    else up[i][j] = 0;
	}
    }
    void put(int r, int c) {
	F[r][c] = !F[r][c];
    }
    void flip(int r, int c) {
	F[r][c] = !F[r][c];
	REP (i, MAX)
	    if (F[i][c]) up[i][c] = (i? up[i-1][c] + 1: 1);
	    else up[i][c] = 0;
    }
    int area(int r, int c) {
	vector<pair<int, int> > S;
	int ret = 0;
	REP (j, MAX) {
	    int last = j;
	    while (!S.empty() && S.back().first > up[r][j]) {
		if (S.back().second <= c && c < j) 
		    amax(ret, (j - S.back().second) * S.back().first);
		last = S.back().second;
		S.pop_back();
	    }
	    S.push_back(make_pair(up[r][j], last));
	}
	return ret;
    }

    void show() {
	REP (i, MAX) rprintf("%d", F[i], F[i]+MAX);
	puts("");
    }
};


int N, M, Q;
bool F[MAX][MAX];
Field X[4];

void rot(int &r, int &c) {
    int tmp = r;
    r = c;
    c = MAX - 2 - tmp;
}
void put(int r, int c) {
    REP (t, 4) {
	X[t].put(r, c);
	rot(r, c);
    }
}
void flip(int r, int c) {
    REP (t, 4) {
	X[t].flip(r, c);
	rot(r, c);
    }
}
int area(int r, int c) {
    int ret = 0;
    REP (t, 4) {
	amax(ret, X[t].area(r, c));
	rot(r, c);
    }
    return ret;
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, N) {
	char op[9];
	REP (j, M) {
	    scanf("%s", op);
	    if (*op == '1') put(i, j);
	}
    }

    REP (t, 4) {
	X[t].build();
    }

    REP ($, Q) {
	char op[9];
	int r, c;
	scanf("%s%d%d", op, &r, &c);
	r--; c--;
	if (*op == '1') flip(r, c);
	else printf("%d\n", area(r, c));

    }

    return 0;
}