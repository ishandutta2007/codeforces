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

int K;
char S[100011];
int C[256];
int eval() {
    scanf("%s", S);
    int len = strlen(S);
    memset(C, 0, sizeof C);
    REP (i, len) C[S[i]]++;


    if (K == 1 && C[S[0]] == len) {
	return max(1, C[S[0]]-1);
    }

    int ma = *max_element(C, C+256);

    return min(len, ma + K);
}

void MAIN() {
    scanf("%d", &K);
    int kuro = eval();
    int shiro = eval();
    int katie = eval();

    if (kuro > shiro && kuro > katie) puts("Kuro");
    else if (shiro > kuro && shiro > katie) puts("Shiro");
    else if (katie > kuro && katie > shiro) puts("Katie");
    else puts("Draw");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}