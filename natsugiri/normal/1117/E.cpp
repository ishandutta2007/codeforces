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

string T, S;
string G[3];
string A[3];

void MAIN() {
    cin >> T;

    REP (k, 3) {
	G[k] = string(T.size(), '-');
	REP (i, T.size()) {
	    int m = i;
	    REP (j, k) m /= 26;
	    G[k][i] = m % 26 + 'a';
	}

	printf("? %s\n", G[k].c_str());
	fflush(stdout);
	cin >> A[k];
    }

    S = string(T.size(), '-');
    REP (i, T.size()) {
	int from = 0;
	for (int k=3; k--;) from = from * 26 + (A[k][i]-'a');
	S[from] = T[i];
    }

    printf("! %s\n", S.c_str());
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}