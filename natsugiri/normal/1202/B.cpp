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

char S[2000011];
bool has[10];
int D[10][10];
bool vis[10];


void MAIN() {
    scanf("%s", S);
    int len = strlen(S);
    REP (x, 10) REP (y, 10) {
	memset(D, 0x3f, sizeof D);
	REP (i, 10) {
	    D[i][(i+x)%10] = 1;
	    D[i][(i+y)%10] = 1;
	}
	REP (k, 10) REP (i, 10) REP (j, 10) amin(D[i][j], D[i][k] + D[k][j]);

	int s = 0;
	int pre = 0;
	int cst = 0;
	if (S[0] == '0') {
	    s = 1;
	} else {
	    cst = 1;
	}
	for (int i=s; i<len; i++) {
	    int a = S[i]-'0';
	    if (D[pre][a] < 100) {
		cst += D[pre][a]-1;
		pre = a;
	    } else {
		cst = -1;
		break;
	    }
	}
	printf("%d%c", cst, " \n"[y==9]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}