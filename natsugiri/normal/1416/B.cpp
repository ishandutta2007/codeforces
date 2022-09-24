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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A[10011];
using Tuple = tuple<int, int, LL>;
vector<Tuple> ans;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i+1);

    LL sum = 0;
    for (int i=1; i<=N; i++) sum += A[i];
    if (sum % N != 0) {
	puts("-1");
	return;
    }

    LL target = sum / N;
    
    ans.clear();

    for (int i=2; i<=N; i++) {
	if (A[i] % i != 0) {
	    LL x = i - A[i] % i;
	    ans.emplace_back(1, i, x);
	    A[1] -= x;
	    A[i] += x;
	}

	{
	    LL x = A[i] / i;
	    ans.emplace_back(i, 1, x);
	    A[i] -= x * i;
	    A[1] += x * i;
	}
    }

    for (int i=2; i<=N; i++) {
	ans.emplace_back(1, i, target);
	A[1] -= target;
	A[i] += target;
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	int a, b; LL c;
	tie(a, b, c) = *e;
	printf("%d %d %lld\n", a, b, c);
    }
    //rprintf("%d", A+1, A+N+1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}