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
char S[200011];
int TX, TY;

int X[200011], Y[200011];

bool ok(int i, int r) {
    int x = X[i] + X[N] - X[r];
    int y = Y[i] + Y[N] - Y[r];
    return abs(TX - x) + abs(TY - y) <= r - i;
}

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);
    scanf("%d%d", &TX, &TY);

    if (N < abs(TX) + abs(TY) || N % 2 != (abs(TX) + abs(TY)) % 2) {
	puts("-1");
	return;
    }

    REP (i, N) {
	X[i+1] = X[i];
	Y[i+1] = Y[i];
	if (S[i] == 'U') Y[i+1]++;
	if (S[i] == 'D') Y[i+1]--;
	if (S[i] == 'R') X[i+1]++;
	if (S[i] == 'L') X[i+1]--;
    }

    int ans = N+1;
    int r = 0;
    REP (i, N+1) {
	amax(r, i);
	while (r < N && !ok(i, r)) r++;
	if (ok(i, r)) amin(ans, r-i);
    }
    if (ans == N+1) ans = -1;
    printf("%d\n", ans);
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}