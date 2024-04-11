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

int N, M, K;
int C[200111], mask[200111];

vector<LL> B[4], sums[4];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%d", C+i);
    {
	int len, x;
	scanf("%d", &len);
	REP (i, len) scanf("%d", &x), mask[x-1] |= 1;
	scanf("%d", &len);
	REP (i, len) scanf("%d", &x), mask[x-1] |= 2;
    }

    REP (i, N) B[mask[i]].push_back(C[i]);

    REP (t, 4) {
	sort(B[t].begin(), B[t].end());
	sums[t].assign(B[t].size()+1, 0);
	REP (i, B[t].size()) sums[t][i+1] = sums[t][i] + B[t][i];
    }


    const LL INF = 1LL<<60;
    LL ans = INF;


    REP (g, sums[3].size()) {
	if (g + (int)B[1].size() < K) continue;
	if (g + (int)B[2].size() < K) continue;
	if (g + (int)B[0].size() + (int)B[1].size() + (int)B[2].size() < M) continue;
	int start = max(0, K-g);
	if (g + start + start > M) continue;

	LL low_value = -1, high_value = 1000000001;
	while (high_value - low_value > 1) {
	    LL mid_value = (low_value + high_value) / 2;

	    int cnt = g;
	    int k;
	    k = upper_bound(B[0].begin(), B[0].end(), mid_value) - B[0].begin();
	    cnt += k;

	    k = upper_bound(B[1].begin() + start, B[1].end(), mid_value) - B[1].begin();
	    cnt += k;

	    k = upper_bound(B[2].begin() + start, B[2].end(), mid_value) - B[2].begin();
	    cnt += k;


	    if (cnt >= M) high_value = mid_value;
	    else low_value = mid_value;
	}

	{
	    LL tmp = 0;

	    tmp += sums[3][g];

	    int cnt = g;
	    int k;
	    k = upper_bound(B[0].begin(), B[0].end(), low_value) - B[0].begin();
	    cnt += k;
	    tmp += sums[0][k];

	    k = upper_bound(B[1].begin() + start, B[1].end(), low_value) - B[1].begin();
	    cnt += k;
	    tmp += sums[1][k];

	    k = upper_bound(B[2].begin() + start, B[2].end(), low_value) - B[2].begin();
	    cnt += k;
	    tmp += sums[2][k];

	    tmp += (M - cnt) * high_value;

	    if (cnt <= M) {
		amin(ans, tmp);
	    }
	}
    }


    if (ans == INF) puts("-1");
    else printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}