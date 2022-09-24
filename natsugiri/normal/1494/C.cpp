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

bool hit[200011];
int solve(VI A, VI B) {
    if (A.empty() || B.empty()) return 0;

    REP (i, A.size()) hit[i] = false;

    int init = 0;

    int k = 0;
    REP (i, B.size()) {
	while (k < (int)A.size() && A[k] < B[i]) k++;
	if (k == (int)A.size()) break;
	if (A[k] == B[i]) {
	    hit[k] = true;
	    init++;
	    k++;
	}
    }

    int ans = init;
    k = 0;
    int right = 0;
    REP (i, B.size()) {
	while (k < (int)A.size() && A[k] <= B[i] + k) {
	    if (hit[k]) init--;
	    k++;
	}
	// [B[i], B[i]+k);
	
	amax(right, i+1);
	while (right < (int)B.size() && B[right] < B[i]+k) {
	    right++;
	}
	int tmp = init + min(right-i, k);
	amax(ans, tmp);
    }

    return ans;
}

void MAIN() {
    int N, M;
    scanf("%d%d", &N, &M);

    VI LA, LB, RA, RB;

    REP (i, N) {
	int a;
	scanf("%d", &a);
	if (a < 0) LA.push_back(-a);
	else RA.push_back(a);
    }
    REP (i, M) {
	int b;
	scanf("%d", &b);
	if (b < 0) LB.push_back(-b);
	else RB.push_back(b);
    }

    reverse(LA.begin(), LA.end());
    reverse(LB.begin(), LB.end());
    int ans = solve(LA, LB) + solve(RA, RB);

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}