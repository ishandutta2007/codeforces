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

const int SIZE = 65536;
LL H[SIZE];
char S[15];

void MAIN() {
    REP (i, SIZE) H[i] = (LL) i * i;

    scanf("%s", S);
    int len = strlen(S);

    int ans = -1;
    REP (s, 1<<len) {
	if (s == 0) continue;

	int top = -1;
	int cnt = 0;
	int r = 0;
	REP (i, len) if (s>>i&1) {
	    if (top == -1) top = S[i] - '0';
	    cnt++;
	    r = r*10 + S[i]-'0';
	}
	if (top == 0) continue;
	if (r == 0) continue;

	int k = lower_bound(H, H+SIZE, (LL)r) - H;
//	eprintf("%d, %lld\n", r, H[k]);
	if (k < SIZE && H[k] == r) {
	    if (ans == -1 || ans > len-cnt) ans = len-cnt;
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}