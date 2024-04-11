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

const int MAXN = 1000011;
int N;
char OP[MAXN];
int G[MAXN][2];
bool R[MAXN];
int T[MAXN];
VI ord;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", OP+i);
	if (OP[i] == 'I') {
	    int x;
	    scanf("%d", &x);
	    R[i] = x;
	    G[i][0] = G[i][1] = -1;
	} else if (OP[i] == 'N') {
	    int x;
	    scanf("%d", &x);
	    x--;
	    G[i][0] = x;
	    G[i][1] = -1;
	} else {
	    int x, y;
	    scanf("%d%d", &x, &y);
	    x--; y--;
	    G[i][0] = x;
	    G[i][1] = y;
	}
    }

    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	REP (t, 2) {
	    int w = G[v][t];
	    if (w == -1) continue;
	    ord.push_back(w);
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	int x = G[v][0], y = G[v][1];

	if (OP[v] == 'I') {
	    ;
	} else if (OP[v] == 'N') {
	    R[v] = !R[x];
	} else if (OP[v] == 'A') {
	    R[v] = R[x] && R[y];
	} else if (OP[v] == 'O') {
	    R[v] = R[x] || R[y];
	} else if (OP[v] == 'X') {
	    R[v] = (int)R[x] ^ (int)R[y];
	}
    }

    // 0
    // 1
    // 2: x
    // 3: !x
    T[0] = 2;

    REP (i_, N) {
	int v = ord[i_];
	int x = G[v][0], y = G[v][1];

	if (OP[v] == 'I') continue;

	if (T[v] == 0 || T[v] == 1) {
	    REP (t, 2) {
		int w = G[v][t];
		if (w == -1) continue;
		T[w] = T[v];
	    }
	} else if (OP[v] == 'N') {
	    T[x] = T[v]^1;
	} else if (OP[v] == 'A') {

	    if (R[y]) T[x] = T[v];
	    else T[x] = T[v] - 2;

	    if (R[x]) T[y] = T[v];
	    else T[y] = T[v] - 2;

	} else if (OP[v] == 'O') {

	    if (R[y]) T[x] = 3 - T[v];
	    else T[x] = T[v];

	    if (R[x]) T[y] = 3 - T[v];
	    else T[y] = T[v];

	} else if (OP[v] == 'X') {

	    if (R[y]) T[x] = T[v] ^ 1;
	    else T[x] = T[v];

	    if (R[x]) T[y] = T[v] ^ 1;
	    else T[y] = T[v];

	}
    }

    REP (v, N) if (OP[v] == 'I') {
	int ans;
	if (T[v] == 0 || T[v] == 1) {
	    ans = T[v];
	} else if (T[v] == 2) {
	    ans = !R[v];
	} else {
	    ans = R[v];
	}
	putchar('0' + ans);
    }
    puts("");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}