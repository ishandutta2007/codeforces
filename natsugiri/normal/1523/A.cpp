#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
LL M;
char S[100011];
char T[100011];

void MAIN() {
    scanf("%d%lld", &N, &M);
    scanf("%s", S);

    for (LL t=0; t<M; t++) {
	REP (i, N) {
	    T[i] = S[i];
	    if (S[i] == '0') {
		int c = 0;
		if (i && S[i-1] == '1') c++;
		if (i+1 < N && S[i+1] == '1') c++;
		if (c == 1) T[i] = '1';
	    }
	}

	bool updated = false;
	REP (i, N) if (S[i] != T[i]) {
	    S[i] = T[i];
	    updated = true;
	}
	if (!updated) break;
    }
    puts(S);

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}