#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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

VI A;
vector<pair<int, int> > ans;
int C[1000011];

bool solve(int k) {
    ans.clear();
    REP (i, A.size()) C[A[i]]++;

    int ma = A.back();
    ans.emplace_back(A[k], ma);
    C[ma]--;
    C[A[k]]--;

    for (int i=2*N; i--;) {
	int b = A[i];
	if (C[b] == 0) continue;

	C[b]--;
	int a = ma - b;
	if (0 <= a && a <= b && C[a]) {
	    C[a]--;
	    ans.emplace_back(a, b);
	    ma = b;
	} else {
	    REP (i, A.size()) C[A[i]] = 0;
	    return false;
	}
    }

    REP (i, A.size()) C[A[i]] = 0;
    return true;
}

void MAIN() {
    scanf("%d", &N);
    A.resize(N*2);
    REP (i, N*2) scanf("%d", &A[i]);

    sort(A.begin(), A.end());

    REP (k, N*2-1) {
	bool b = solve(k);
	if (b) {
	    puts("YES");
	    printf("%d\n", ans[0].first + ans[0].second);
	    REP (i, N) printf("%d %d\n", ans[i].first, ans[i].second);
	    return;
	}
    }

    puts("NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}