#include<cassert>
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
char S[11111];

char T[11111];
int q_cnt;

int query(const char *s) {
#ifdef LOCAL
    eprintf("%s\n", s);
    q_cnt++;
    int ret = 0;
    REP (i, N) if (s[i] != T[i]) ret++;
    return ret;
#else
    printf("? %s\n", s);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
#endif
}

void test() {
#ifdef LOCAL
    N = 1000;
    REP (i, N) {
	T[i] = '1';
    }
    T[0] = '0';
#endif
}

void check(int ans0, int ans1) {
#ifdef LOCAL
    eprintf("%s\n", T);
    assert(q_cnt <= 15);
    assert(T[ans0] == '0');
    assert(T[ans1] == '1');
#endif
}


int calc(char head, char other, int all_head) {
    int lo = 1;
    int hi = N;
    while (hi - lo > 1) {
	int mid = (hi + lo) / 2;
	REP (i, N) {
	    if (i < mid) S[i] = other;
	    else S[i] = head;
	}

	int q = query(S);
	if (q != all_head + mid) hi = mid;
	else lo = mid;
    }
    return lo;
}

void MAIN() {
    scanf("%d", &N);
    test();

    REP (i, N) S[i] = '0';
    int h0 = query(S);
    S[0] = '1';
    int h1 = query(S);

    int ans0, ans1;
    if (h0 < h1) { // 0....
	ans0 = 0;
	ans1 = calc('0', '1', h0);
    } else if (h0 > h1) { // 1....
	ans1 = 0;
	REP (i, N) S[i] = '1';
	int q = query(S);
	ans0 = calc('1', '0', q);
    } else {
	assert(false);
    }

    printf("! %d %d\n", ans0+1, ans1+1);
    fflush(stdout);

    check(ans0, ans1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}