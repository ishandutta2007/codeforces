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

const int INF = 1<<29;

int N, C, D;

vector<pair<int, int> > CC, DD;
VI Cy, Dy;
int ans;

void fine(vector<pair<int, int> > &xx, VI &yy, int z) {
    sort(xx.begin(), xx.end());
    yy.assign(xx.size() + 1, -INF);

    REP (i, xx.size()) {
	yy[i+1] = max(yy[i], xx[i].second);
    }

    if (xx.size() > 1u) {
	for (int i=1; i<(int)xx.size(); i++) {
	    int k = upper_bound(xx.begin(), xx.begin() + i, make_pair(z - xx[i].first, INF)) 
		- xx.begin();

	    if (1 <= k && k <= i) {
		amax(ans, xx[i].second + yy[k]);
	    }
	}
    }
}

void MAIN() {
    scanf("%d%d%d", &N, &C, &D);

    int c0 = -1, d0 = -1;
    REP (i, N) {
	int b, p;
	char op[9];
	scanf("%d%d%s", &b, &p, op);
	if (*op == 'C') {
	    if (p <= C) amax(c0, b);
	    CC.emplace_back(p, b);
	} else {
	    if (p <= D) amax(d0, b);
	    DD.emplace_back(p, b);
	}
    }

    fine(CC, Cy, C);
    fine(DD, Dy, D);

    if (c0 >= 0 && d0 >= 0) amax(ans, c0 + d0);

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}