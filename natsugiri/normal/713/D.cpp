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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

// SparseTable2D
namespace ST2 {
    typedef int T;
    const int SIZE = 1023; // SIZE <= (1 << LOG)
    const int LOG = 10;
    T d[SIZE][SIZE]; // assign all values
    short row[LOG][SIZE][LOG][SIZE];
    short col[LOG][SIZE][LOG][SIZE];

    inline const T& get_d(int rl, int r, int cl, int c) {
	return d[ row[rl][r][cl][c] ][ col[rl][r][cl][c] ];
    }

    void build() {
	REP (r, SIZE) REP (c, SIZE) { // 1x1
	    row[0][r][0][c] = r;
	    col[0][r][0][c] = c;
	}
	REP (r, SIZE) REP (cl, LOG-1) {
	    for (int c=0, c2=min(SIZE-1, 1<<cl); c<SIZE; c++, c2=min(SIZE-1, c2+1)) {
		if (get_d(0, r, cl, c2) < get_d(0, r, cl, c)) {
		    row[0][r][cl+1][c] = row[0][r][cl][c2];
		    col[0][r][cl+1][c] = col[0][r][cl][c2];
		} else {
		    row[0][r][cl+1][c] = row[0][r][cl][c];
		    col[0][r][cl+1][c] = col[0][r][cl][c];
		}
	    }
	}

	REP (rl, LOG-1) {
	    for (int r=0, r2=min(SIZE-1, 1<<rl); r<SIZE; r++, r2=min(SIZE-1, r2+1)) {
		REP (cl, LOG) REP (c, SIZE) {
		    if (get_d(rl, r2, cl, c) < get_d(rl, r, cl, c)) {
			row[rl+1][r][cl][c] = row[rl][r2][cl][c];
			col[rl+1][r][cl][c] = col[rl][r2][cl][c];
		    } else {
			row[rl+1][r][cl][c] = row[rl][r][cl][c];
			col[rl+1][r][cl][c] = col[rl][r][cl][c];
		    }
		}
	    }
	}
    }

    // [r1, r2) x [c1, c2)
    // assert(r1 < r2 && c1 < c2);
    // returns indexes in get_min(,,,, &ret_r, &ret_c);
    const T& get_min(int r1, int c1, int r2, int c2, int *ret_r=NULL, int *ret_c=NULL) { 
	int r3 = __lg(r2-r1);
	int c3 = __lg(c2-c1);
	r2 -= 1<<r3;
	c2 -= 1<<c3;
	int rr[] = { r1, r1, r2, r2 };
	int cc[] = { c1, c2, c1, c2 };
	int p = 0;
	for (int i=1; i<4; i++)
	    if (get_d(r3, rr[i], c3, cc[i]) < get_d(r3, rr[p], c3, cc[p]))
		p = i;

	if (ret_r) *ret_r = rr[p];
	if (ret_c) *ret_c = cc[p];
	return get_d(r3, rr[p], c3, cc[p]);
    }
};



int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) {
	scanf("%d", &ST2::d[i][j]);
	ST2::d[i][j] *= -1;
	if (i && j && ST2::d[i][j]) {
	    amin(ST2::d[i][j], max(max(ST2::d[i-1][j], ST2::d[i][j-1]), ST2::d[i-1][j-1]) - 1);
	}
    }

    ST2::build();

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x1--; y1--;

	int l = 0, h = min(x2-x1, y2-y1)+1;
	while (h - l > 1) {
	    int m = (h + l) / 2;

	    if (m <= -ST2::get_min(x1+m-1, y1+m-1, x2, y2)) {
		l = m;
	    } else {
		h = m;
	    }
	}
	printf("%d\n", l);
    }


    return 0;
}