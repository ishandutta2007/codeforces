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
pair<int, int> P[400111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int l, r;
	scanf("%d%d", &l, &r);
	P[i*2] = make_pair(l, 0);
	P[i*2+1] = make_pair(r, 1);
    }

    int NN = N + N;
    sort(P, P+NN);
    bool yes = true;
    int cnt = 0;
    for (int i=0; i<NN; ) {
	int j = i;
	while (j < NN && P[i].first == P[j].first && P[j].second == 0) {
	    cnt++;
	    j++;
	}
	if (cnt > 2) {
	    yes = false;
	}
	while (j < NN && P[i].first == P[j].first) {
	    cnt--;
	    j++;
	}
	i = j;
    }

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}