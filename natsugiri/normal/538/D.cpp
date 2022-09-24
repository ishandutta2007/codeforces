#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N;
char F[55][55], G[55][55];

int BASE = 55;
int A[111][111];


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%s", F[i]);

    
    REP (i, N) REP (j, N) if (F[i][j] == 'o') {
	REP (y, N) REP (x, N) {
	    if (F[y][x] == 'x') A[y-i+BASE][x-j+BASE] |= 1;
	    if (F[y][x] == '.') A[y-i+BASE][x-j+BASE] |= 2;
	}
    }

    REP (i, N) REP (j, N) if (F[i][j] == 'o') {
	G[i][j] = 'o';
	REP (y, N) REP (x, N) if (A[y-i+BASE][x-j+BASE] == 1 && (G[y][x] == 0 || G[y][x] == '.'))
	    G[y][x] = 'x';
    } else if (G[i][j] == 0) {
	G[i][j] = '.';
    }

    bool yes = true;
    REP (i, N) REP (j, N) if (F[i][j] != G[i][j]) yes = false;

    if (yes) {
	puts("YES");
	for (int i=BASE-N+1; i<=BASE+N-1; i++) {
	    for (int j=BASE-N+1; j<=BASE+N-1; j++) {
		if (i == BASE && j == BASE) putchar('o');
		else if (A[i][j] == 1 || A[i][j] == 0) putchar('x');
		else putchar('.');
	    }
	    putchar('\n');
	}
    } else {
	puts("NO");
    }
    return 0;
}