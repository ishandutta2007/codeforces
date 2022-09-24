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

string query(int r, int c) {
    printf("%d %d\n", r+1, c+1);
    fflush(stdout);
    static char buf[111];
    scanf("%s", buf);
    return buf;
}


void MAIN() {
    int r = 0, c = 7;
    while (1) {
START:

	for (int s=0; ; s++) {
	    for (int nxt_c = s&1; nxt_c<8; nxt_c++) {
		if (nxt_c == c) continue;
		c = nxt_c;
		string q = query(r, c);

		if (q == "Done") {
		    return;
		} else if (q[0] == 'D') {
		    r++;
		    q = query(r, c);

		    if (q == "Done") {
			return;
		    }

		    goto START;
		}
	    }
	}
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}