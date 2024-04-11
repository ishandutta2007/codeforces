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
int A[200111];
char S[200111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;
    scanf("%s", S);

    for (int i=0; i<N-1; ) {
	while (i < N-1 && S[i] == '0') i++;
	int j = i;
	while (j < N-1 && S[j] == '1') j++;
	if (i < j) sort(A+i, A+j+1);
	i = j;
    }

    bool yes = true;
    REP (i, N) if (A[i] != i) yes = false;
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}