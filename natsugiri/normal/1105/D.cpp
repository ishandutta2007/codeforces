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

const int dy[] = {0, 1, 0, -1};
const int dx[] = { 1, 0, -1, 0};

int N, M, P;
char F[1011][1011];
int S[9];
int ans[9];
vector<pair<int, int> > st[9];

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &P);
    REP (i, P) scanf("%d", S+i);
    REP (i, N) scanf("%s", F[i]);

    REP (i, N) REP (j, M) {
	if ('1' <= F[i][j] && F[i][j] <= '9') {
	    st[F[i][j]-'1'].emplace_back(i, j);
	}
    }

    while (1) {
	bool update = false;
	REP (p, P) {
	    vector<pair<int, int> > cur, nxt;
	    swap(cur, st[p]);
	    if (!cur.empty()) update = true;

	    for (int t=0; t<S[p] && !cur.empty(); t++) {
		EACH (e, cur) {
		    int y = e->first, x = e->second;
		    REP (d, 4) {
			int yy = y + dy[d];
			int xx = x + dx[d];
			if (in(yy, xx) && F[yy][xx] == '.') {
			    F[yy][xx] = p+'1';
			    nxt.emplace_back(yy, xx);
			}
		    }
		}
		swap(cur, nxt);
		nxt.clear();
	    }

	    swap(cur, st[p]);
	}

	if (!update) break;
    }

    REP (i, N) REP (j, M) if ('1' <= F[i][j] && F[i][j] <= '9') ans[F[i][j]-'1']++;
    rprintf("%d", ans, ans+P);

//    REP (i, N) puts(F[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}