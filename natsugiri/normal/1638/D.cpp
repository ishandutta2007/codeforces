#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<tuple>

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

int N, M;
int A[1011][1011];
bool in[1011][1011];

using Tuple = tuple<int, int, int>;
vector<Tuple> ans;
vector<pair<int, int> > stk;

void check(int i, int j) {
    if (i < 0) return;
    if (j < 0) return;
    if (N <= i+1) return;
    if (M <= j+1) return;
    if (in[i][j]) return;

    static VI v;
    v.clear();
    if (A[i][j] != -1) v.push_back(A[i][j]);
    if (A[i+1][j] != -1) v.push_back(A[i+1][j]);
    if (A[i][j+1] != -1) v.push_back(A[i][j+1]);
    if (A[i+1][j+1] != -1) v.push_back(A[i+1][j+1]);

    sort(v.begin(), v.end());

    if (v.size() && v[0] == v.back()) {
	ans.emplace_back(i, j, v[0]);
	A[i][j] = -1;
	A[i+1][j] = -1;
	A[i][j+1] = -1;
	A[i+1][j+1] = -1;
	in[i][j] = true;
	stk.emplace_back(i, j);
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", &A[i][j]);

    ans.clear();
    stk.clear();
    REP (i, N) REP (j, M) in[i][j] = false;

    REP (i, N-1) REP (j, M-1) {
	check(i, j);
    }
    while (!stk.empty()) {
	int i = stk.back().first;
	int j = stk.back().second;
	stk.pop_back();

	for (int y=i-1; y<=i+1; y++) for (int x=j-1; x<=j+1; x++) {
	    check(y, x);
	}
    }

    bool yes = true;
    REP (i, N) REP (j, M) {
	if (A[i][j] != -1) yes = false;
    }
    if (yes) {
	printf("%d\n", (int)ans.size());
	reverse(ans.begin(), ans.end());
	EACH (e, ans) {
	    int i, j, c;
	    tie(i, j, c) = *e;
	    printf("%d %d %d\n", i+1, j+1, c);
	}
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}