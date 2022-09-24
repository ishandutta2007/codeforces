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
char S[1111];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    int upper = 0, lower = 0, digit = 0;
    REP (i, N) {
	if (isupper(S[i])) upper++;
	else if (islower(S[i])) lower++;
	else digit++;
    }

    int cnt = (int)(upper==0) + (int)(lower==0) + (int)(digit==0);
    if (cnt == 1) {
	int pos = 0;
	REP (i, N) {
	    if (isupper(S[i]) && upper > 1) { pos = i; break; }
	    if (islower(S[i]) && lower > 1) { pos = i; break; }
	    if (isdigit(S[i]) && digit > 1) { pos = i; break; }
	}
	S[pos] = (upper == 0? 'A': (lower == 0? 'a' : '0'));
    } else if (cnt == 2) {
	REP (i, 2) {
	    if (upper == 0) { S[i] = 'A'; upper++; }
	    else if (lower == 0) { S[i] = 'a'; lower++; }
	    else if (digit == 0) { S[i] = '0'; digit++; }
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