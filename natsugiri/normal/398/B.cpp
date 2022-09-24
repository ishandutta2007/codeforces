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
double E[2011][2011];
bool row[2011], col[2011];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int r, c;
	scanf("%d%d", &r, &c);
	r--; c--;
	row[r] = col[c] = true;
    }

    if (N == 1) {
	puts(M? "0.0": "1.0");
	return 0;
    }

    int r_cnt = 0, c_cnt = 0;
    REP (i, N) {
	if (!row[i]) r_cnt++;
	if (!col[i]) c_cnt++;
    }

    REP (i, r_cnt+1) REP (j, c_cnt+1) {
	if (i == 0 && j == 0) continue;
	if (i && j) E[i][j] += E[i-1][j-1] * i * j;
	if (i) E[i][j] += E[i-1][j] * i * (N-j);
	if (j) E[i][j] += E[i][j-1] * (N-i) * j;
	E[i][j] += (double)N * N;
	E[i][j] /= (double)N * N - (double)(N-i) * (N-j);
    }

    printf("%.9f\n", E[r_cnt][c_cnt]);

    return 0;
}