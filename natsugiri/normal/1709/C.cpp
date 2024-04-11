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
    int le = count(S, S+N, '(');

    int left = -1, right = -1;
    REP (i, N) {
	if (S[i] == '?') {
	    if ((le + 1) * 2 <= N) {
		S[i] = '(';
		le++;
		left = i;
	    } else {
		S[i] = ')';
		if (right == -1) {
		    right = i;
		}
	    }
	}
    }

    bool yes = true;
    if (left == -1 || right == -1) {
	yes = true;
    } else {
	int depth = 0;
	swap(S[left], S[right]);
	bool ok = true;
	REP (i, N) {
	    if (S[i] == '(') depth++;
	    else depth--;
	    if (depth < 0) ok = false;
	}

	if (ok) yes = false;
    }

    puts(yes?"YES":"NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}