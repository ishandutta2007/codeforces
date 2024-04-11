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
char OP[100111];
char buf[100111];
string W[100111];;
bool B[26];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s%s", OP+i, buf);
	W[i] = buf;
    }

    char tar = W[N-1][0];
    bool detected = false;
    int ans = 0;

    REP (i, N) {
	bool C[26] = {};
	EACH (e, W[i]) C[*e-'a'] = true;

	if (OP[i] == '.') {
	    REP (c, 26) if (C[c]) B[c] = true;
	} else if (OP[i] == '!') {
	    if (detected && C[tar-'a']) ans++;
	    REP (c, 26) if (!C[c]) B[c] = true;
	} else if (OP[i] == '?') {
	    if (detected && W[i][0] != tar) ans++;

	    if (W[i][0] == tar) {
		detected = true;
		REP (c, 26) B[c] = true;
		B[tar-'a'] = false;
	    } else {
		B[W[i][0]-'a'] = true;
	    }
	}

	if (!detected && count(B, B+26, false) == 1) detected = true;
    }

    printf("%d\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}