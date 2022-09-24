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

int key(int i, int j) {
    if (i == j) return 6;
    if (i > j) swap(i, j);
    if (i == 0) return j-1;
    if (i == 1) return j+1;
    return 5;
}
int N;
vector<int> E[4][4];
LL S[4][4];
int C[4];
int deg[4];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int l, v, r;
	scanf("%d%d%d", &l, &v, &r);
	if (l > r) swap(l, r);
	l--; r--;
	E[l][r].push_back(v);
	S[l][r] += v;
    }
    REP (i, 4) REP (j, 4) {
	sort(E[i][j].begin(), E[i][j].end());
    }

    LL ans = 0;
    // 0 1
    // 0 2
    // 0 3
    // 1 2
    // 1 3
    // 2 3
    REP (x, 4) REP (s, 1<<6) {
	memset(C, 0, sizeof C);
	C[x] = true;
	REP (_, 6) REP (i, 4) if (C[i]) REP (j, 4) {
	    int sub = (s>>key(i, j)&1);
	    if ((int)E[i][j].size() > sub) C[j] = true;
	    if ((int)E[j][i].size() > sub) C[j] = true;
	}

	LL tmp = 0;
	memset(deg, 0, sizeof deg);
	REP (i, 4) REP (j, 4) if (C[i] && C[j]) {
	    int sub = (s>>key(i, j)&1);
	    if ((int)E[i][j].size() <= sub) continue;

	    tmp += S[i][j];
	    if (sub) {
		tmp -= E[i][j][0];
	    }
	    deg[i] += (int)E[i][j].size() - sub;
	    deg[j] += (int)E[i][j].size() - sub;
	}
	
	int cnt = 0;
	REP (i, 4) if (deg[i] & 1) cnt++;
	if (cnt <= 2) amax(ans, tmp);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}