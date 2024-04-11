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

int N;

void MAIN() {
    scanf("%d", &N);
    int ans = 0;
    int cur = 0;

    const int INF = 1<<29;
    VI st;
    st.push_back(INF);
    int no_overtake = 0;

    REP ($, N) {
	int T;
	scanf("%d", &T);
	if (0) {
	} else if (T == 1) {
	    int S;
	    scanf("%d", &S);
	    cur = S;
	} else if (T == 2) {
	    ans += no_overtake;
	    no_overtake = 0;
	} else if (T == 3) {
	    int S;
	    scanf("%d", &S);
	    st.push_back(S);
	} else if (T == 4) {
	    no_overtake = 0;
	} else if (T == 5) {
	    st.resize(1);
	} else if (T == 6) {
	    no_overtake++;
	}

	while (st.back() < cur) {
	    ans++;
	    st.pop_back();
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