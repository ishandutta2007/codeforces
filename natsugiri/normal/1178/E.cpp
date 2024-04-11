#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
char S[1000011];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    int L = 0, R = N-1;
    string ans;
    while (R-L+1 >= 4) {
	if (S[L] == S[R] || S[L] == S[R-1]) {
	    ans.push_back(S[L]);
	} else {
	    ans.push_back(S[L+1]);
	}
	L += 2;
	R -= 2;
    }
    printf("%s", ans.c_str());
    if (L <= R) putchar(S[L]);
    reverse(ans.begin(), ans.end());
    printf("%s", ans.c_str());
    puts("");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}