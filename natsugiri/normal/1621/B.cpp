#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

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

void MAIN() {
    scanf("%d", &N);

    int minL = 0;
    int minLC = 0;
    int maxR = 0;
    int maxRC = 0;

    map<pair<int, int>, int> mp;

    REP (i, N) {
	int l, r, c;
	scanf("%d%d%d", &l, &r, &c);

	if (i == 0) {
	    minL = l;
	    minLC = c;
	    maxR = r;
	    maxRC = c;
	} else {
	    if (l < minL) {
		minL = l;
		minLC = c;
	    } else if (l == minL) {
		amin(minLC, c);
	    }
	    if (maxR < r) {
		maxR = r;
		maxRC = c;
	    } else if (maxR == r) {
		amin(maxRC, c);
	    }
	}

	pair<int, int> key(l, r);
	auto it = mp.find(key);
	if (it != mp.end()) amin(it->second, c);
	else mp[key] = c;

	int ans = minLC + maxRC;

	it = mp.find(make_pair(minL, maxR));
	if (it != mp.end()) {
	    amin(ans, it->second);
	}

	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}