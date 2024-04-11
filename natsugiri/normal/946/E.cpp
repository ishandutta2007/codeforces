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
char T[200011];

bool ok(int mid) {
    int mask = 0;
    REP (i, mid) mask ^= 1<<(S[i]-'0');

    int pos = N;
    for (int c=9; c>=0; c--) if (mask>>c&1) {
	T[--pos] = c + '0';
    }

    if (mid > pos) return false;
    for (int i=mid; i<pos; i++) if (S[i] > '0') return true;
    for (int i=pos; i<N; i++) if (S[i] != T[i]) return T[i] < S[i];

    return false;
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    if (S[0] == '1') {
	int c = count(S, S+N, '0');
	if (c == N-1 || (c == N-2 && S[N-1] == '1')) {
	    REP (i, N-2) putchar('9');
	    puts("");
	    return;
	}
    }

    int lo = 0, hi = N;
    while (hi - lo > 1) {
	int mid = (hi + lo) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    while (1) {
	S[lo]--;

	int mask = 0;
	REP (i, lo+1) mask ^= 1<<(S[i]-'0');

	int pc = 0;
	for (int c=9; c>=0; c--) if (mask>>c&1) {
	    pc++;
	}
	if (lo + 1 + pc <= N) {
	    for (int i=lo+1; i<N; i++) S[i] = '9';
	    int pos = N;
	    for (int c=0; c<=9; c++) if (mask>>c&1) {
		S[--pos] = c + '0';
	    }
	    break;
	} else {
	    continue;
	}
    }

    puts(S);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}