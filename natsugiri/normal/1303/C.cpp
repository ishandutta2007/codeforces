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
char S[10011];

bool A[26][26];
bool use[26];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    bool yes;
    string ans;
    if (N <= 1) {
	yes = true;
	REP (c, 26) ans.push_back('a' + c);
    } else {
	memset(A, 0, sizeof A);
	REP (i, N-1) {
	    int a = S[i] - 'a';
	    int b = S[i+1] - 'a';
	    A[a][b] = A[b][a] = true;
	}

	yes = true;
	int start = -1;
	REP (c, 26) {
	    int cnt = count(A[c], A[c] + 26, true);
	    if (cnt > 2) yes = false;
	    if (cnt == 1 && start == -1) start = c;
	}
	if (start == -1) yes = false;

	int prv = start;
	if (yes) {
	    while (1) {
		ans.push_back(start + 'a');
		int nxt = -1;
		REP (c, 26) if (A[start][c] && c != prv) {
		    nxt = c;
		    break;
		}
		if (nxt == -1) break;
		prv = start;
		start = nxt;
	    }

	    memset(use, 0, sizeof use);
	    EACH (e, ans) use[*e - 'a'] = true;
	    REP (c, 26) if (!use[c]) ans.push_back(c+'a');

	    memset(A, 0, sizeof A);
	    REP (i, 25) {
		int a = ans[i] - 'a';
		int b = ans[i+1] - 'a';
		A[a][b] = A[b][a] = true;
	    }

	    REP (i, N-1) {
		int a = S[i] - 'a';
		int b = S[i+1] - 'a';
		if (!A[a][b]) yes = false;
	    }
	}
    }

    if (yes) {
	puts("YES");
	puts(ans.c_str());
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}