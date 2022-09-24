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
LL B[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", B+i);

    set<LL> se;
    auto it = se.insert(B[0]).first;
    bool yes = true;

    for (int i=1; i<N; i++) {
	if (B[i-1] < B[i]) {
	    auto nxt = next(it);
	    if (nxt == se.end() || B[i] < *nxt) {
		it = se.insert(B[i]).first;
	    } else if (B[i] == *nxt) {
		it = nxt;
	    } else {
		yes = false;
		break;
	    }
	} else if (B[i] < B[i-1]) {
	    if (it == se.begin()) {
		it = se.insert(B[i]).first;
	    } else {
		auto prv = prev(it);
		if (*prv < B[i]) {
		    it = se.insert(B[i]).first;
		} else if (*prv == B[i]) {
		    it = prv;
		} else {
		    yes = false;
		    break;
		}
	    }
	}
    }

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}