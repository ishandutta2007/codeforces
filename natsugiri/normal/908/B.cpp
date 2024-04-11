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

const int dy_[] = {0, 1, 0, -1};
const int dx_[] = {1, 0, -1, 0};
int dd[4] = {0,1,2,3};
int dy(int d) { return dy_[dd[d]]; }
int dx(int d) { return dx_[dd[d]]; }

int N, M;
char F[111][111];
char S[111];

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);
    scanf("%s", S);
    int len = strlen(S);

    int ans = 0;
    do {
	int y, x;
	REP (i, N) REP (j, M) if (F[i][j] == 'S') {
	    y = i;
	    x = j;
	}

	REP (i, len) {
	    int d = S[i] - '0';
	    y += dy(d);
	    x += dx(d);

	    if (in(y, x) && F[y][x] != '#') {
		if (F[y][x] == 'E') {
		    ans++;
		    break;
		}
	    } else {
		break;
	    }
	}
    } while (next_permutation(dd, dd+4));

    printf("%d\n", ans);
    
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}