#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
char S[200011];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);


    int left = 0;
    string stay, stk;

    while (left < N) {
	char c = *min_element(S+left, S+N);
	int nxt = left;
	for (int i=left; i<N; i++) {
	    if (S[i] == c) {
		stay.push_back(S[i]);
		nxt = i + 1;
	    }
	}
	for (int i=left; i<nxt; i++) {
	    if (S[i] != c) {
		stk.push_back(min(S[i]+1, (int)'9'));
	    }
	}
	left = nxt;
    }

    sort(stk.begin(), stk.end());
    int i = 0, j = 0;
    while (i < (int)stay.size() || j < (int)stk.size()) {
	if (i == (int)stay.size() || (j < (int)stk.size() && stk[j] < stay[i])) {
	    putchar(stk[j++]);
	} else {
	    putchar(stay[i++]);
	}
    }
    putchar('\n');
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}