#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int N;
int C;
vector<LL> A;
bool has[1000011];

void MAIN() {
    scanf("%d%d", &N, &C);
    A.resize(N);
    REP (i, N) scanf("%lld", &A[i]);

    sort_unique(A);
    N = A.size();
    bool yes;
    if (A[0] != 1) {
	yes = false;
    } else {
	EACH (e, A) has[*e] = true;

	yes = true;
	for (int i=1; i<(int)A.size() && yes; i++) {
	    LL a = A[i];
	    LL rate = 1;
	    int left = i;
	    while (1) {
		int right = lower_bound(A.begin()+left, A.end(), a + A[i]) - A.begin();
		if (left < right) {
		    if (rate <= 1000000 && has[rate]) {
		    } else {
			yes = false;
			break;
		    }
		}

		left = right;
		a += A[i];
		rate++;
		if (left == (int)A.size()) break;
	    }
	}

	EACH (e, A) has[*e] = false;
    }

    puts(yes?"Yes":"No");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}