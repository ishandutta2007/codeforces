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

int N, K;
char S[100111];
bool C[26];

void MAIN() {
    scanf("%d%d", &N, &K);
    scanf("%s", S);
    REP (i, N) C[S[i]-'a'] = true;

    char mi;
    REP (i, 26) if (C[i]) {
	mi = i + 'a';
	break;
    }

    if (N < K) {
	for (int i=N; i<K; i++) S[i] = mi;
    } else {
	for (int i=K; i--;) {
	    int t = S[i]-'a';
	    for (t+=1; t<26; t++) {
		if (C[t]) {
		    S[i] = t + 'a';
		    for (i+=1; i<K; i++) S[i] = mi;
		    goto END;
		}
	    }
	}

    }

END:;
    S[K] = 0;
    puts(S);
    
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}