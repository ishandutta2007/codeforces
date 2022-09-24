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

const char *No = "No";
const char *Yes = "Yes";

char S[100011];
int C[26];
int N;

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    REP (i, N) C[S[i]-'a']++;
    sort(C, C+26);
    reverse(C, C+26);

    bool yes = false;
    if (C[0] == 0) {
	yes = false;
    } else if (C[1] == 0) {
	yes = false;
    } else if (C[2] == 0) {
	yes = (C[1] >= 2);
    } else if (C[3] == 0) {
	yes = (C[0] >= 2);
    } else if (C[4] == 0) {
	yes = true;
    } else {
	yes = false;
    }

    puts(yes? Yes: No);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}