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
char S[5011];
int B[5011][26];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    double ans = 0;
    REP (c, 26) {
	int cnt = 0;
	REP (i, N) if (S[i] == c + 'a') {
	    cnt++;
	    int k = i;
	    REP (j, N) {
		char w = S[k];
		B[j][w-'a']++;
		k++;
		if (k >= N) k -= N;
	    }
	}

	if (cnt) {
	    int best = 0;
	    REP (i, N) {
		int z = 0;
		REP (d, 26) if (B[i][d]==1) z++;
		amax(best, z);
	    }

//	    eprintf("%c %d %f\n", c+'a', best, (double)best / cnt);
	    ans += (double)best / N;


	    memset(B, 0, sizeof B);
	}
    }

    printf("%.9f\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}