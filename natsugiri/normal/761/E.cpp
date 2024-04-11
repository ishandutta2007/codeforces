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

const int dy[] = { 0, 1, 0, -1};
const int dx[] = { 1, 0, -1, 0};
int N;
VI G[33];
LL Y[33], X[33];

void rec(int v, int p, LL x, LL y, int d, LL r) {
    d = (d + 3) % 4;
    Y[v] = y; X[v] = x;
    EACH (e, G[v]) if (*e != p) {
	rec(*e, v, x + dx[d] * r, y + dy[d] * r, d, r>>1);
	d = (d + 1) % 4;
    }
}

int main() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    

    int ma = 0;
    REP (i, N) amax(ma, (int)G[i].size());

    if (ma > 4) puts("NO");
    else {
	puts("YES");
	rec(0, -1, 0, 0, 0, (1LL<<40)-1);
	REP (i, N) printf("%lld %lld\n", X[i], Y[i]);
    }

    return 0;
}