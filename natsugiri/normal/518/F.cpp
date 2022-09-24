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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

int R, C;
char buf[2111];
int F[2111][2111];

inline int box(int r0, int c0, int r1, int c1) { // [r0, r1) x [c0, c1)
    return F[r1][c1] - F[r1][c0] - F[r0][c1] + F[r0][c0];
}
inline int dot(int r, int c) {
    return box(r, c, r+1, c+1);
}
inline int line(int r0, int c0, int r1, int c1) { // include
    if (c0 > c1) swap(c0, c1);
    if (r0 > r1) swap(r0, r1);
    return box(r0, c0, r1+1, c1+1);
}

int main() {
    scanf("%d%d", &R, &C);
    REP (i, R) {
	scanf("%s", buf);
	REP (j, C) {
	    F[i+1][j+1] = F[i][j+1] + F[i+1][j] - F[i][j];
	    if (buf[j] == '#') F[i+1][j+1]++;
	}
    }

    LL ans = 0;
    // vertical line
    for (int j=1; j<C-1; j++) if (!line(0, j, R-1, j)) ans++;
    // holizontal
    for (int i=1; i<R-1; i++) if (!line(i, 0, i, C-1)) ans++;

    
    for (int i=1; i<R-1; i++) {
	for (int j=1; j<C-1; j++) {
	    if (!line(0, j, i, j)) { // u
		if (!line(i, 0, i, j)) ans++; // l
		if (!line(i, C-1, i, j)) ans++; // r
	    }
	    if (!line(R-1, j, i, j)) { // d
		if (!line(i, 0, i, j)) ans++; // l
		if (!line(i, C-1, i, j)) ans++; // r
	    }
	}
    }

    // S N U A
    for (int i=1; i<R-1; i++) {
	LL u = 0, d = 0;
	int ub = 0, db = 0; 
	for (int j=1; j<C-1; j++) {
	    if (dot(i, j)) u = d = ub = db = 0;
	    if (!line(0, j, i, j)) ans += u + d + db; // u
	    if (!line(R-1, j, i, j)) ans += u + d + ub; // d

	    u += ub; d += db;
	    ub = !line(0, j, i, j);
	    db = !line(R-1, j, i, j);
	}
    }

    // Z z < >
    for (int j=1; j<C-1; j++) {
	LL l = 0, r = 0;
	int lb = 0, rb = 0;
	for (int i=1; i<R-1; i++) {
	    if (dot(i, j)) l = r = lb = rb = 0;
	    if (!line(i, 0, i, j)) ans += l + r + rb; // l
	    if (!line(i, C-1, i, j)) ans += l + r + lb; // r

	    l += lb; r += rb;
	    lb = !line(i, 0, i, j);
	    rb = !line(i, C-1, i, j);
	}
    }

    printf("%lld\n", ans);
    
    return 0;
}