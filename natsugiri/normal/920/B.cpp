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

int N;
vector<pair<int, int> >B[5011];
int ans[5011];

void MAIN() {
    scanf("%d", &N);
    REP (i, 5011) B[i].clear();

    REP (i, N) {
	int l, r;
	scanf("%d%d", &l, &r);
	B[l].emplace_back(i, r);
    }

    int cur = 0;
    REP (i, 5011) {
	sort(B[i].begin(), B[i].end());
	amax(cur, i);
	EACH (e, B[i]) {
	    int id = e->first;
	    int r = e->second;
	    if (r < cur) {
		ans[id] = 0;
	    } else {
		ans[id] = cur;
		cur++;
	    }
	}
    }
    rprintf("%d", ans, ans+N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}