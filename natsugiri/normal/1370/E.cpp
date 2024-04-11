#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
string S, T;
char buf[1000011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    T = buf;

    if (count(S.begin(), S.end(), '0') != count(T.begin(), T.end(), '0')) {
	puts("-1");
	return;
    }

    string D;
    REP (i, N) if (S[i] != T[i]) D.push_back(S[i]);
    D += D;
    VI v;
    for (int i=0; i<(int)D.size(); ) {
	int j = i;
	while (j < (int)D.size() && D[i] == D[j]) j++;
	if (D[i] == '0') v.push_back(j-i);
	else v.push_back(i-j);
	i = j;
    }

    int ans = 0;

    REP (t, 2) {
	int sum = 0;
	EACH (e, v) {
	    sum += *e;
	    amax(ans, sum);
	    amax(sum, 0);
	}

	EACH (e, v) *e = -*e;
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}