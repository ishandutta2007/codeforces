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

int N, M;
char buf[111];
string S[111];


int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	scanf("%s", buf);
	S[i] = buf;
    }

    REP (j, M) {
	bool yes = true;;
	REP (i, N-1) {
	    if (S[i+1].compare(0, j+1, S[i], 0, j+1) < 0) { yes = false; break; }
	}
	
	if (!yes) {
	    REP (i, N) S[i][j] = '*';
	}
    }

    int ans = count(S[0].begin(), S[0].end(), '*');
    printf("%d\n", ans);
    return 0;
}