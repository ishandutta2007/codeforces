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

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }
char F[16][16];

int main() {
    REP (i, 8) scanf("%s", F[i]);

    int W = 99, B = 99;
    REP (c, 8) REP (r, 8) {
	if (F[r][c] == 'B') break;
	if (F[r][c] == 'W') amin(W, r);
    }
    REP (c, 8) REP (r_, 8) {
	int r = 7-r_;
	if (F[r][c] == 'W') break;
	if (F[r][c] == 'B') amin(B, r_);
    }

    puts(B < W ? "B" : "A");
    // eprintf("%d %d\n", W, B);
    return 0;
}