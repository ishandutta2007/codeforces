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
int A[100011];

const LL INF = 1LL<<60;
using Tuple = tuple<int, int, LL, LL>;
vector<Tuple> ans;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    ans.clear();

    for (int i=1; i<N; i+=2) {
	if (A[i-1] > A[i]) {
	    ans.emplace_back(i-1, i, A[i], A[i]);
	    A[i-1] = A[i];
	}
    }
    for (int i=1; i<N; i+=2) {
	if (A[i] != 1) {
	    int x = A[i]+1;
	    while (1) {
		bool ok = true;
		if (__gcd(A[i-1], x) != 1) ok = false;
		if (i+1 < N && __gcd(A[i+1], x) != 1) ok = false;

		if (ok) break;
		else x++;
	    }

	    ans.emplace_back(i-1, i, A[i-1], x);
	    A[i] = x;
	}
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	int i, j, x, y;
	tie(i, j, x, y) = *e;
	printf("%d %d %d %d\n", i+1, j+1, x, y);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}