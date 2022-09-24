#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;

int F(int x) {
    int ret = 0;
    while (x) {
	ret++;
	x /= 10;
    }
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    priority_queue<int> A, B;
    REP (i, N) {
	int x;
	scanf("%d", &x);
	A.push(x);
    }
    REP (i, N) {
	int x;
	scanf("%d", &x);
	B.push(x);
    }

    int ans = 0;
    while (!A.empty()) {
	if (A.top() == B.top()) {
	    A.pop();
	    B.pop();
	} else if (A.top() > B.top()) {
	    int x = A.top(); A.pop();
	    A.push(F(x));
	    ans++;
	} else {
	    int x = B.top(); B.pop();
	    B.push(F(x));
	    ans++;
	}
    }


    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}