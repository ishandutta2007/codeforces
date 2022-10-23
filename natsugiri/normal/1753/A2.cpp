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

int N;
int A[200011];
vector<pair<int, int> > ans;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    ans.clear();

    int sum = 0;
    REP (i, N) sum += A[i];

    if (sum % 2 == 0) {
	for (int i=0; i<N; ) {
	    if (A[i] == 0) {
		ans.emplace_back(i, i+1);
		i++;
	    } else if (A[i+1] == 0) {
		int j = i + 1;
		while (A[j] == 0) j++;
		if (A[i] == A[j]) {
		    ans.emplace_back(i, j-1);
		    ans.emplace_back(j-1, j+1);
		    i = j + 1;
		} else {
		    ans.emplace_back(i, j);
		    ans.emplace_back(j, j+1);
		    i = j + 1;
		}
	    } else if (A[i] == A[i+1]) {
		ans.emplace_back(i, i+2);
		i += 2;
	    } else {
		ans.emplace_back(i, i+1);
		ans.emplace_back(i+1, i+2);
		i += 2;
	    }
	}

	printf("%d\n", (int)ans.size());
	EACH (e, ans) {
	    printf("%d %d\n", e->first+1, e->second);
	}
    } else {
	puts("-1");
    }

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}