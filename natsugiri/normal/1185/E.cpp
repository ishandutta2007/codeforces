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

int H, W;
char F[2011][2011];
char X[2011][2011];
int rmax[26], rmin[26], cmax[26], cmin[26];

void MAIN() {
    scanf("%d%d", &H, &W);
    REP (i, H) scanf("%s", F[i]);

    memset(rmax, -1, sizeof rmax);
    memset(cmax, -1, sizeof cmax);
    memset(rmin, 0x3f, sizeof rmin);
    memset(cmin, 0x3f, sizeof cmin);

    int num = 0;
    REP (i, H) REP (j, W) if (F[i][j] != '.') {
	int p = F[i][j] - 'a';
	amax(num, p+1);

	amax(rmax[p], i);
	amin(rmin[p], i);
	amax(cmax[p], j);
	amin(cmin[p], j);
    }

    REP (i, H) {
	memset(X[i], '.', sizeof (char) * W);
	X[i][W] = 0;
    }
    bool yes = true;
    for (int c=num; c--;) {
	if (rmax[c] == -1) {
	    rmax[c] = rmax[c+1];
	    cmax[c] = cmax[c+1];
	    rmin[c] = rmin[c+1];
	    cmin[c] = cmin[c+1];
	} else {
	    if (rmax[c] != rmin[c] && cmax[c] != cmin[c]) {
		yes = false;
		break;
	    }
	    for (int i=rmin[c]; i<=rmax[c]; i++) {
		for (int j=cmin[c]; j<=cmax[c]; j++) {
		    if (X[i][j] == '.') X[i][j] = c + 'a';
		}
	    }
	}
    }

    if (yes) {
	REP (i, H) REP (j, W) if (F[i][j] != X[i][j]) {
	    yes = false;
	}
    }

    if (yes) {
	puts("YES");
	printf("%d\n", num);
	REP (c, num) printf("%d %d %d %d\n", rmin[c]+1, cmin[c]+1, rmax[c]+1, cmax[c]+1);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}