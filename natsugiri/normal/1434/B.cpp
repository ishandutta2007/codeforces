#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
char op[200011];
int X[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N*2) {
	scanf("%s", op+i);
	if (op[i] == '-') scanf("%d", X+i);
    }

    bool yes = true;
    priority_queue<int> Q;
    VI ans;

    for (int i=N*2; i--;) {
	if (op[i] == '+') {
	    if (Q.empty()) {
		yes = false;
		break;
	    } else {
		ans.push_back(-Q.top());
		Q.pop();
	    }
	} else {
	    if (Q.size() && -Q.top() < X[i]) {
		yes = false;
		break;
	    } else {
		Q.push(-X[i]);
	    }
	}
    }

    if (yes) {
	assert(Q.empty());
	reverse(ans.begin(), ans.end());
	puts("YES");
	rprintf("%d", ans.begin(), ans.end());
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}