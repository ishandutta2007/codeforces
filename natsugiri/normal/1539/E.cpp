#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
int M;
int dp[100011][2];

void MAIN() {
    scanf("%d%d", &N, &M);

    set<pair<int, int> > fixL, fixR;

    int prv = 0;
    fixL.emplace(0, -100);
    fixR.emplace(0, -100);


    REP (i, N) {
	int k, al, bl, ar, br;
	scanf("%d%d%d%d%d", &k, &al, &bl, &ar, &br);

	dp[i+1][0] = -2;
	dp[i+1][1] = -2;

	bool r_insert = (!fixL.empty() && al <= prv && prv <= bl && ar <= k && k <= br);
	bool l_insert = (!fixR.empty() && al <= k && k <= bl && ar <= prv && prv <= br);

	if (al <= k && k <= bl) {
	    while (!fixL.empty() && fixL.begin()->first < ar) fixL.erase(fixL.begin());
	    while (!fixL.empty() && br < fixL.rbegin()->first) fixL.erase(prev(fixL.end()));

	    if (!fixL.empty()) {
		// (i, second);
		dp[i+1][0] = fixL.begin()->second;
	    }
	} else {
	    fixL.clear();
	}
	if (ar <= k && k <= br) {
	    while (!fixR.empty() && fixR.begin()->first < al) fixR.erase(fixR.begin());
	    while (!fixR.empty() && bl < fixR.rbegin()->first) fixR.erase(prev(fixR.end()));
	    
	    if (!fixR.empty()) {
		// (second, i);
		dp[i+1][1] = fixR.begin()->second;
	    }
	} else {
	    fixR.clear();
	}

	if (r_insert) {
	    // (i-1, i);
	    fixR.emplace(prv, i-1);
	    dp[i+1][1] = i-1;
	}
	if (l_insert) {
	    // (i, i-1);
	    fixL.emplace(prv, i-1);
	    dp[i+1][0] = i-1;
	}

	prv = k;
    }
    int x = -2, y = -2;
    if (dp[N][0] != -2) {
	x = N-1;
	y = dp[N][0];
    } else if (dp[N][1] != -2) {
	x = dp[N][1];
	y = N-1;
    }
    if (x != -2 && y != -2) {
	puts("Yes");
	VI ans;
	for (int i=N; i--;) {
	    if (x > y) {
		assert(x == i);
		ans.push_back(0);
		if (x == y+1) {
		    x = dp[x][1];
		} else {
		    x--;
		}
	    } else if (x < y) {
		assert(y == i);
		ans.push_back(1);
		if (y == x+1) {
		    y = dp[y][0];
		} else {
		    y--;
		}
	    } else {
		assert(false);
	    }
	}

	reverse(ans.begin(), ans.end());
	rprintf("%d", ans.begin(), ans.end());
    } else {
	puts("No");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}