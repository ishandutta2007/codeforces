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

const char COLOR[] = "RBYG";
int N;
int pos[4];
int C[4];
char S[111];

int main() {
    scanf("%s", S);
    N = strlen(S);
    REP (i, N) {
	REP (d, 4) if (S[i] == COLOR[d]) pos[i % 4] = d;
    }
    REP (i, N) if (S[i] == '!') C[pos[i % 4]]++;

    rprintf("%d", C, C+4);

    return 0;
}