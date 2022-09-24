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

// ab?cd --> ? = e;

const int AL = 8;
int N;
char S[100011];
int buf[2][AL][AL];
int (*cur)[AL] = buf[0];
int (*nxt)[AL] = buf[1];

char AT(int i, int x) {
    if (x < AL-1) return 'a' + x;
    if (i < 0) return 0;
    return S[i];
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    memset(cur, 0x3f, sizeof buf[0]);
    const int INF = cur[0][0];
    REP (x, AL) REP (y, AL) cur[x][y] = 0;

    REP (i, N) {
	memset(nxt, 0x3f, sizeof buf[0]);
	REP (x, AL) REP (y, AL) if (cur[x][y] != INF) {
	    char cx = AT(i-2, x);
	    char cy = AT(i-1, y);

	    REP (z, AL) {
		char cz = AT(i, z);
		int cst = (S[i] == cz? 0: 1);
		if (cz != cx && cz != cy) {
		    amin(nxt[y][z], cur[x][y] + cst);
		}
	    }
	}
	swap(cur, nxt);
    }

    int ans = INF;
    REP (x, AL) REP (y, AL) {
	char cx = AT(N-2, x);
	char cy = AT(N-1, y);
	if (cx != cy) amin(ans, cur[x][y]);
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}