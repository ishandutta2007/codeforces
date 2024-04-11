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
char S[100011];
char T[100011];

void MAIN() {
    scanf("%d%s%s", &N, S, T);

    string S1, T1;
    REP (i, N) {
	if (S[i] == 'a' || S[i] == 'c') S1.push_back(S[i]);
	if (T[i] == 'a' || T[i] == 'c') T1.push_back(T[i]);
    }

    bool yes = true;
    if (S1 != T1) {
	yes = false;
    }

    if (yes) {
	int i = 0, j = 0;
	int a = 0, c = 0;
	while (1) {
	    while (i < N && S[i] != 'b') {
		if (S[i] == 'a') a++;
		if (S[i] == 'c') c++;
		i++;
	    }
	    while (j < N && T[j] != 'b') {
		if (T[j] == 'a') a--;
		if (T[j] == 'c') c--;
		j++;
	    }

	    if (i == N || j == N) break;

	    if (a >= 0 && c == 0) {
	    } else if (c <= 0 && a == 0) {
	    } else {
		yes = false;
		break;
	    }

	    i++;
	    j++;
	}
    }

    puts(yes?"YES":"NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}