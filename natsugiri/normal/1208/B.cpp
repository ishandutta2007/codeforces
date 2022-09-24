#include<map>
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
int A[2011];

map<int, VI> mp;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) {
	mp[A[i]].push_back(i);
    }

    int ans = N;
    {
	bool yes = true;
	EACH (e, mp) if (e->second.size() >= 2u) yes = false;
	if (yes) ans = 0;
    }
    REP (l, N) {
	bool yes = true;
	int r = l+1;
	EACH (e, mp) if (e->second.size() >= 2u) {
	    if (e->second[1] < l) {
		yes = false;
		break;
	    }
	    if (e->second[0] < l) {
		amax(r, e->second.back()+1);
	    } else {
		amax(r, e->second.rbegin()[1]+1);
	    }
	}
	if (yes) {
	    amin(ans, r-l);
	}
    }

    printf("%d\n", ans);


}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}