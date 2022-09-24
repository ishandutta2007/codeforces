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
vector<LL> R, B, P;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x;
	char op[11];
	scanf("%d%s", &x, op);
	if (*op == 'R') R.push_back(x);
	if (*op == 'B') B.push_back(x);
	if (*op == 'P') P.push_back(x);
    }

    sort(R.begin(), R.end());
    sort(B.begin(), B.end());
    sort(P.begin(), P.end());

    LL ans = 0;
    if (P.empty()) {
	if (!R.empty()) ans += R.back() - R[0];
	if (!B.empty()) ans += B.back() - B[0];
    } else {
	int idxR = 0, idxB = 0;
	// left;
	if (!R.empty() && R[0] < P[0]) ans += P[0] - R[0];
	while (idxR < (int)R.size() && R[idxR] < P[0]) idxR++;
	if (!B.empty() && B[0] < P[0]) ans += P[0] - B[0];
	while (idxB < (int)B.size() && B[idxB] < P[0]) idxB++;

	// center
	REP (i, (int)P.size()-1) {
	    LL left = P[i];
	    LL right = P[i+1];

	    int nextR = idxR;
	    int nextB = idxB;
	    while (nextR < (int)R.size() && R[nextR] < right) nextR++;
	    while (nextB < (int)B.size() && B[nextB] < right) nextB++;

	    // con left --- right;
	    LL con = right - left;
	    if (idxR < nextR) {
		LL ma = 0;
		amax(ma, R[idxR] - left);
		for (int k=idxR; k+1<nextR; k++) 
		    amax(ma, R[k+1] - R[k]);
		amax(ma, right - R[nextR-1]);
		con += right - left - ma;
	    }
	    if (idxB < nextB) {
		LL ma = 0;
		amax(ma, B[idxB] - left);
		for (int k=idxB; k+1<nextB; k++) 
		    amax(ma, B[k+1] - B[k]);
		amax(ma, right - B[nextB-1]);
		con += right - left - ma;
	    }

	    // cut left -/- right
	    LL cut = 2 * (right - left);

	    ans += min(con, cut);

	    idxR = nextR;
	    idxB = nextB;
	}

	// right;
	if (!R.empty() && P.back() < R.back()) ans += R.back() - P.back();
	if (!B.empty() && P.back() < B.back()) ans += B.back() - P.back();
    }


    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}