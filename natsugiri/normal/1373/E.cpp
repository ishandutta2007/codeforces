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

int N;
int K;

const int SIZE = 1000011;
int sums[SIZE];
string mem[211];

int F(int n) {
    int r = 0;
    while (n) {
	r += n % 10;
	n /= 10;
    }
    return r;
}

void init() {
    for (int i=0; i<10; i++) mem[i] = to_string(i);

    for (int b=10; b<=150; b++) {
	mem[b] = mem[b-9] + "9";
    }

    for (int i=1; i<SIZE-1; i++) {
	sums[i+1] = sums[i] + F(i);
    }
}

int search() {
    for (int i=0; i+K+1<SIZE; i++) if (sums[i+K+1] - sums[i] == N) {
	return i;
    }
    return -1;
}

void solve() {
    if (K == 0) {
	puts(mem[N].c_str());
    } else {
	int index = search();
	string ans;
	if (K == 1 && index == -1) {
	    ans = "-1";
	    if (N % 2 == 0 && N >= 26) {
		string g = mem[(N-26)/2];
		if (!g.empty()) ans = g + "89";
	    }
	    if (N % 2 == 1 && N >= 35) {
		string g = mem[(N-35)/2];
		if (!g.empty()) ans = g + "98";
	    }
	} else {
	    ans = to_string(index);
	}

	puts(ans.c_str());
    }
}

void MAIN() {
    scanf("%d%d", &N, &K);
    solve();
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}