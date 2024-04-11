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

//bool vis[1000];
//bool slow(int X, int Y) {
//    memset(vis, 0, sizeof vis);
//    vis[X] = true;
//    for (int i=X; i<=Y; i++) if (vis[i]) {
//	for (int sub=i; sub; sub=(sub-1)&i) {
//	    if (i + sub <= Y) vis[i+sub] = true;
//	}
//    }
//    return vis[Y];
//}

VI stk;

bool solve(int X, int Y) {
    for (int t=30; t>=0; t--) {
	if ((X>>t&1) && (Y>>t&1)) {
	    X ^= 1<<t;
	    Y ^= 1<<t;
	}
	if ((X>>t&1) != (Y>>t&1)) {
	    break;
	}
    }

    if (X > Y) return false;

    stk.clear();
    for (int t=30; t>=0; t--) {
	if (X>>t&1) stk.push_back(t);
    }

    REP (t, 31) {
	if (Y>>t&1) {
	    if (stk.size() && stk.back() <= t) {
		stk.pop_back();
	    } else {
		return false;
	    }
	}
    }

    return true;
}

void MAIN() {
    int X, Y;
    scanf("%d%d", &X, &Y);

    puts(solve(X, Y)? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}