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


void MAIN() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    bool yes = true;
    VI ans;
    ans.reserve(a+b+c+d);

    if (a > b) {
	if (a == b+1 && c == 0 && d == 0) {
	    REP (i, a+b) ans.push_back(i&1);
	} else {
	    yes = false;
	}
    } else if (c < d) {
	if (c+1 == d && a == 0 && b == 0) {
	    REP (i, c+d) ans.push_back(3-(i&1));
	} else {
	    yes = false;
	}
    } else {
	int one = b-a;
	int two = c-d;
	if (abs(one - two) > 1) {
	    yes = false;
	} else {
	    if (one == two+1) { ans.push_back(1); }
	    REP (i, a) { ans.push_back(0); ans.push_back(1); }
	    REP (i, min(one, two)) { ans.push_back(2); ans.push_back(1); }
	    REP (i, d) { ans.push_back(2); ans.push_back(3); }
	    if (one+1 == two) { ans.push_back(2); }
	}
    }

    if (yes) {
	if (count(ans.begin(), ans.end(), 0) != a) yes = false;
	if (count(ans.begin(), ans.end(), 1) != b) yes = false;
	if (count(ans.begin(), ans.end(), 2) != c) yes = false;
	if (count(ans.begin(), ans.end(), 3) != d) yes = false;
	REP (i, (int)ans.size()-1) if (abs(ans[i] - ans[i+1]) != 1) yes = false;
    }

    if (yes) {
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