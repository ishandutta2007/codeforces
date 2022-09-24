#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

// order by C/S;
struct Cmp {
    bool operator()(const pair<LL, LL> &x, const pair<LL, LL> &y) const {
	return x.first * y.second > x.second * y.first;
    }
} cmp;

int N;
char buf[100111];

void MAIN() {
    scanf("%d", &N);
    vector<pair<LL, LL> > X;
    LL ans = 0;
    REP (i, N) {
	scanf("%s", buf);

	LL s = 0, h = 0;
	int len = strlen(buf);
	REP (j, len) {
	    if (buf[j] == 's') {
		s++;
	    } else if (buf[j] == 'h') {
		ans += s;
		h++;
	    }
	}

	if (s | h) {
	    X.emplace_back(s, h);
	}
    }

    sort(X.begin(), X.end(), cmp);

    {
	LL s = 0, h = 0;
	EACH (e, X) {
	    ans += s * e->second;
	    s += e->first;
	    h += e->second;
	}
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}