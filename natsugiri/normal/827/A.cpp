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
char buf[3000111];
char S[3000111];
vector<string> T;
VI G[3000111];

void MAIN() {
    int stop = 0;
    scanf("%d", &N);
    REP (i, N) {
	int K;
	scanf("%s%d", buf, &K);
	T.push_back(buf);
	int len = strlen(buf);
	REP (j, K) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    G[x].push_back(i);
	    amax(stop, x + len);
	}
    }

    VI id, start;
    REP (i, stop) {
	EACH (e, G[i]) {
	    id.push_back(*e);
	    start.push_back(i);
	}

	while (id.size() && start.back() + (int)T[id.back()].size() <= i) {
	    id.pop_back();
	    start.pop_back();
	}

	if (id.empty()) {
	    S[i] = 'a';
	} else {
	    S[i] = T[id.back()][i - start.back()];
	}
    }

    puts(S);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}