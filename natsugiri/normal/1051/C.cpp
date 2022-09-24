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
const int SIZE = 111;
VI G[SIZE];
char ans[SIZE];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	G[x].push_back(i);
    }

    int one = 0, two = 0, more = 0;
    REP (i, SIZE) {
	if (G[i].size() == 1u) one++;
	if (G[i].size() == 2u) two++;
	if (G[i].size() > 2u) more++;
    }

    if (one % 2 == 1 && more == 0) {
	puts("NO");
    } else {
	puts("YES");
	int t = 0;

	REP (i, N) ans[i] = 'A';

	REP (i, SIZE) if (G[i].size() == 1u) {
	    ans[G[i][0]] = (t*2 < one? 'A': 'B');
	    t++;
	}
	if (one % 2 == 1) {
	    REP (i, SIZE) if (G[i].size() > 2u) {
		ans[G[i][0]] = 'B';
		break;
	    }
	}

	puts(ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}