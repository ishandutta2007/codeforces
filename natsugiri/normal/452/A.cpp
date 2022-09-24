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
string P[8] = {
    "vaporeon",
    "jolteon", 
    "flareon",
    "espeon", 
    "umbreon", 
    "leafeon",
    "glaceon",
    "sylveon",
};
int N;
char S[100111];

int main() {
    scanf("%d%s", &N, S);
    REP (i, 8) if (N == (int)P[i].size()) {
	bool yes = true;
	REP (j, N) if (S[j] != '.' && S[j] != P[i][j]) yes = false;
	if (yes) {
	    puts(P[i].c_str());
	    return 0;
	}
    }



    return 0;
}