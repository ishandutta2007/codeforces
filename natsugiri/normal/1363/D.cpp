#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
VI G[1011];
char buf[1011];
bool use[1011];

int query(const VI &v) {
    printf("? %d", (int)v.size());
    REP (i, v.size()) printf(" %d", v[i]+1);
    puts("");
    fflush(stdout);

    int ret;
    scanf("%d", &ret);
    return ret;
}

int query(int a, int b) {
    VI v;
    for (int i=a; i<b; i++) v.push_back(i);
    return query(v);
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, K) G[i].clear();

    REP (i, K) {
	int c;
	scanf("%d", &c);
	REP (j, c) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    G[i].push_back(x);
	}
    }

    int ma = query(0, N);
    int lo = 0, hi = N;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	int q = query(lo, mid);
	if (ma == q) hi = mid;
	else lo = mid;
    }

    int snd = ma;
    REP (i, K) {
	bool has = false;
	EACH (e, G[i]) if (*e == lo) has = true;
	if (has) {
	    memset(use, 0, sizeof use);
	    EACH (e, G[i]) use[*e] = true;
	    VI v;
	    REP (j, N) if (!use[j]) v.push_back(j);
	    snd = query(v);
	    break;
	}
    }

    VI ans;
    REP (i, K) {
	bool has = false;
	EACH (e, G[i]) if (*e == lo) has = true;
	ans.push_back(has? snd: ma);
    }
    printf("! ");
    rprintf("%d", ans.begin(), ans.end());
    fflush(stdout);

    scanf("%s", buf);
    if (buf[0] == 'I') exit(0);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}