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

int Q;
char S[100111];
char W[100111];
int Slen, Wlen;
bool good[26];

bool match(char pattern, char test) {
    if (pattern == '?') return good[test-'a'];
    if (pattern == '*') return !good[test-'a'];
    return pattern == test;
}

void MAIN() {
    scanf("%s", S);
    REP (i, strlen(S)) good[S[i]-'a'] = true;

    scanf("%s", S);
    Slen = strlen(S);
    int q = find(S, S+Slen, '*') - S;
     
    scanf("%d", &Q);
    REP ($, Q) {
	scanf("%s", W);
	Wlen = strlen(W);

	bool yes;
	if (q < Slen) {
	    if (Wlen + 1 < Slen) {
		yes = false;
	    } else {
		// S : [0, q), [q+1, Slen);
		// W : [0, q), [Wlen - (Slen-q-1), Wlen)
		yes = true;
		for (int i=0; i<q; i++) 
		    if (!match(S[i], W[i])) yes = false;
		for (int i=0; i<Slen-q-1; i++) 
		    if (!match(S[Slen-1-i], W[Wlen-1-i])) yes = false;
		for (int i=q; i<Wlen-(Slen-q-1); i++) 
		    if (!match('*', W[i])) yes = false;
	    }
	} else {
	    if (Slen == Wlen) {
		yes = true;
		for (int i=0; i<Slen; i++) 
		    if (!match(S[i], W[i])) yes = false;
	    } else {
		yes = false;
	    }
	}

	puts(yes? "YES" : "NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}