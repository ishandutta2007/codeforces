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

int mem[1000211];
int C[10][1000211];

int g(int x) {
    if (x < 10) return x;
    if (x < 1000111 && mem[x]) return mem[x];
    int k = 1, y = x;
    while (y) {
	int t = y % 10;
	if (t) k *= t;
	y /= 10;
    }
    if (x < 1000111) return mem[x] = g(k);
    else return g(k);
}


void MAIN() {
    for (int i=1; i<1000111; i++) {
	REP (t, 10) C[t][i+1] += C[t][i];
	C[g(i)][i+1]++;
    }
    int N;
    scanf("%d", &N);
    REP (i, N) {
	int L, R, K;
	scanf("%d%d%d", &L, &R, &K);
	printf("%d\n", C[K][R+1] - C[K][L]);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}