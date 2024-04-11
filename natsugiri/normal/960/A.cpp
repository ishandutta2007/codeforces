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
char S[100011];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    int posB = N;
    REP (i, N) if (S[i] == 'b') {
	posB = i;
	break;
    }
    int posC = N;
    for (int i=posB; i<N; i++) if (S[i] == 'c') {
	posC = i;
	break;
    }

    bool yes = true;
    REP (i, posB) if (S[i] != 'a') yes = false;
    for (int i=posB; i<posC; i++) if (S[i] != 'b') yes = false;
    for (int i=posC; i<N; i++) if (S[i] != 'c') yes = false;
    if (posB == 0) yes = false;
    if (posB == posC) yes = false;
    if (posC == N) yes = false;
    if (N-posC != posB && N-posC != posC-posB) yes = false;

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}