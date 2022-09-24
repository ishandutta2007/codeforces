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

const int dy[] = { -1, -1, 0, +1, +1, +1, 0, -1 };
const int dx[] = { 0, -1, -1, -1, 0, +1, +1, +1 };

int N;
int A[101];
const int BASE = 200;
char F[BASE*2][BASE*2+1];

void rec(int id, int y, int x) {
    if (id == N) return;

    rec(id+1, y + A[id] * dy[id&7], x + A[id] * dx[id&7]);

    REP (i, 2*BASE) REP (j, 2*BASE) if (F[i][j] != '.') {
	int yy, xx;
	if (dy[id&7] == 0) { xx = j; yy = 2*y-i; }
	else if (dx[id&7] == 0) { xx = 2*x-j; yy = i; }
	else if (dy[id&7] == dx[id&7]) { xx = x+(i-y); yy = y+(j-x); }
	else { xx = x-(i-y); yy = y-(j-x); }
	F[yy][xx] = F[i][j];
    }

    for (int t=1; t<=A[id]; t++) {
	int yy = y + t * dy[id&7];
	int xx = x + t * dx[id&7];
	F[yy][xx] = '*';
    }
}



int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(F, '.', sizeof F);
    REP (i, 2 * BASE) F[i][2 * BASE] = 0;

    rec(0, BASE, BASE);
//    REP (i, BASE*2) puts(F[i]);

    int ans = 0;
    REP (i, BASE*2) REP (j, BASE*2) if (F[i][j] != '.') ans++;
    printf("%d\n", ans);


    return 0;
}