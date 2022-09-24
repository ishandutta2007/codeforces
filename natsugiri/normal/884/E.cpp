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
char buf[(1<<12) + 11];
int U[2<<14];

int code(char c) {
    if (isdigit(c)) return c - '0';
    return c - 'A' + 10;
}

int root(int x) {
    if (U[x] == x) return x;
    return U[x] = root(U[x]);
}
void link(int x, int y) {
    x = root(x);
    y = root(y);
    if (x > y) swap(x, y);
    U[y] = x;
}

void MAIN() {
    scanf("%d%d", &N, &M);

    int ans = 0;
    REP (i, M*2) U[i] = -1;

    REP (z, N) {
	scanf("%s", buf);

	REP (i, M) {
	    if (U[i] == -1) U[i+M] = -1;
	    else U[i+M] = U[i] + M;
	    U[i] = -1;
	}

	bool left = false;

	REP (i, M) {
	    bool my = (code(buf[i>>2]) >> ((i&3)^3)) & 1;

	    if (my) {
		U[i] = i;
		if (U[i+M] != -1) {
		    link(i, i+M);
		}
		if (left) {
		    link(i, i-1);
		}
	    } else {
		U[i] = -1;
	    }

	    left = my;
	}

	for (int i=M; i<M*2; i++) if (U[i] == i) ans++;
    }
    REP (i, M) if (U[i] == i) ans++;


    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}