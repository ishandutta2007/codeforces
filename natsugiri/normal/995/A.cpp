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

int N, K;
int F[4][55];
int ord_row[111];
int ord_col[111];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, 4) REP (j, N) scanf("%d", F[i]+j);

    bool filled = true;
    bool neighbor = false;
    REP (i, N) {
	if (F[1][i] == 0) filled = false;
	if (F[2][i] == 0) filled = false;

	if (F[1][i]>0 && F[0][i] == F[1][i]) neighbor = true;
	if (F[2][i]>0 && F[3][i] == F[2][i]) neighbor = true;
    }

    if (filled && !neighbor) {
	puts("-1");
    } else {
	VI car, row, col;
	REP (i, N) {
	    ord_row[i] = 1;
	    ord_col[i] = i;
	    ord_row[i+N] = 2;
	    ord_col[i+N] = N-1-i;
	}

	while (1) {
	    int cnt = 0;
	    REP (i, N+N) if (F[ord_row[i]][ord_col[i]] > 0) cnt++;
	    if (cnt == 0) break;
	    REP (i, N) {
		if (F[1][i]>0 && F[0][i] == F[1][i]) {
		    car.push_back(F[1][i]);
		    row.push_back(0);
		    col.push_back(i);
		    F[1][i] = 0;
		    cnt--;
		}
		if (F[2][i]>0 && F[3][i] == F[2][i]) {
		    car.push_back(F[2][i]);
		    row.push_back(3);
		    col.push_back(i);
		    F[2][i] = 0;
		    cnt--;
		}
	    }
	    if (cnt == 0) break;

	    REP (i, N+N) if (F[ord_row[i]][ord_col[i]] == 0) {
		int pre_row;
		int pre_col;

		REP (t, N+N-1) {
		    pre_row = ord_row[i];
		    pre_col = ord_col[i];
		    i--;
		    if (i<0) i += N+N;

		    if (F[ord_row[i]][ord_col[i]] > 0) {
			car.push_back(F[ord_row[i]][ord_col[i]]);
			row.push_back(pre_row);
			col.push_back(pre_col);
			F[pre_row][pre_col] = F[ord_row[i]][ord_col[i]];
			F[ord_row[i]][ord_col[i]] = 0;
		    }
		}
		break;
	    }
	}

	printf("%d\n", (int)car.size());
	REP (i, car.size()) {
	    printf("%d %d %d\n", car[i], row[i]+1, col[i]+1);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}