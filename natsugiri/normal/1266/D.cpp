#include<tuple>
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

int N, M;
LL D[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int a, b;
	LL d;
	scanf("%d%d%lld", &a, &b, &d);
	a--;
	b--;
	D[a] -= d;
	D[b] += d;
    }

    using Tuple = tuple<int, int, LL>;
    vector<Tuple> ans;

    int o = 0, i = 0;
    while (1) {
	while (i < N && D[i] <= 0) i++;
	while (o < N && D[o] >= 0) o++;

	if (i == N) {
	    assert(o == N);
	    break;
	}

	LL d = min(D[i], -D[o]);
	ans.emplace_back(o, i, d);
	D[i] -= d;
	D[o] += d;
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	LL d;
	tie(o, i, d) = *e;
	printf("%d %d %lld\n", o+1, i+1, d);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}