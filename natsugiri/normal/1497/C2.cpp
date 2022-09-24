#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int K;
VI ans;

void MAIN() {
    scanf("%d%d", &N, &K);
    ans.clear();

    REP (i, K-3) {
	ans.push_back(1);
	N--;
    }

    if (N % 2 == 1) {
	int g = N/2;
	ans.push_back(1);
	ans.push_back(g);
	ans.push_back(g);
    } else if (N % 4 == 2) {
	int g = (N-2) / 2;
	ans.push_back(2);
	ans.push_back(g);
	ans.push_back(g);
    } else {
	int g = N / 4;
	ans.push_back(g);
	ans.push_back(g);
	ans.push_back(N/2);
    }
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}