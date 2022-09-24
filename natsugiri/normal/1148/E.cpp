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

pair<LL, int> S[300011];
LL T[300011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", &S[i].first), S[i].second = i;
    REP (i, N) scanf("%lld", T+i);
    sort(S, S+N);
    sort(T, T+N);

    VI ansI, ansJ;
    vector<LL> ansD;
    VI st;
    REP (i, N) {
	if (S[i].first < T[i]) {
	    st.push_back(i);
	} else {
	    while (S[i].first > T[i] && !st.empty()) {
		int pos = st.back();
		LL d = min(T[pos] - S[pos].first, S[i].first - T[i]);
		S[pos].first += d;
		S[i].first -= d;
		ansI.push_back(pos);
		ansJ.push_back(i);
		ansD.push_back(d);

		if (T[pos] == S[pos].first) st.pop_back();
	    }
	    if (S[i].first > T[i]) {
		puts("NO");
		return;
	    }
	}
    }

    if (st.empty()) {
	puts("YES");
	printf("%d\n", (int)ansI.size());
	REP (i, ansI.size()) printf("%d %d %lld\n", S[ansI[i]].second+1, S[ansJ[i]].second+1, ansD[i]);
	return;
    } else {
	puts("NO");
	return;
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}