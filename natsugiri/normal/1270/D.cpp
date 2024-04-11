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

int N, K;
char S[555];

pair<int, int> query(VI idx) {
    EACH (e, idx) (*e)++;
    printf("? ");
    rprintf("%d", idx.begin(), idx.end());
    fflush(stdout);

    int a, b;
    scanf("%d%d", &a, &b);
    return make_pair(a-1, b);
}

void MAIN() {
    scanf("%d%d", &N, &K);
    VI idx;
    REP (i, K) idx.push_back(i);
    pair<int, int> a = query(idx);

    VI idx2 = idx;
    idx2[a.first] = K;
    pair<int, int> b = query(idx2);

    REP (i, K) {
	if (i == a.first) continue;
	// if (i == b.first) continue;

	VI idx3;
	REP (j, K+1) {
	    if (j != i) idx3.push_back(j);
	}
	pair<int, int> c = query(idx3);
	if (a.second < b.second) {
	    if (c == a) S[i] = '+';
	    else S[i] = '-';
	} else {
	    if (c == a) S[i] = '-';
	    else S[i] = '+';
	}
    }

    int ans = count(S, S+K, '-') + 1;
    printf("! %d\n", ans);
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}