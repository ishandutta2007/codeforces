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

int LEN[4];
int A[4][150011];

int PA[3];
pair<int, int> B[3][200011];

LL dp[4][150011];

LL aux[150011];

void MAIN() {
    REP (i, 4) scanf("%d", LEN+i);
    REP (i, 4) {
	REP (j, LEN[i]) scanf("%d", A[i]+j);
    }

    REP (i, 3) {
	scanf("%d", PA+i);
	REP (j, PA[i]) {
	    int x, y;
	    scanf("%d%d", &x, &y);
	    x--; y--;
	    B[i][j] = make_pair(x, y);
	}
    }

    memset(dp, 0x3f, sizeof dp);
    const LL INF = dp[0][0];

    REP (j, LEN[0]) dp[0][j] = A[0][j];
    vector<LL> tmp;

    REP (i, 3) {
	sort(B[i], B[i] + PA[i], [](const pair<int, int> &x, const pair<int, int> &y) {
		return x.second < y.second;
		});

	REP (j, LEN[i]) aux[j] = dp[i][j];
	sort(aux, aux + LEN[i]);

	int b_idx = 0;
	REP (j, LEN[i+1]) {
	    int b_idx2 = b_idx;
	    tmp.clear();
	    while (b_idx2 < PA[i] && B[i][b_idx2].second == j) {
		tmp.push_back(dp[i][B[i][b_idx2].first]);
		b_idx2++;
	    }

	    sort(tmp.begin(), tmp.end());
	    tmp.push_back(INF);

	    REP (k, LEN[i]) {
		if (aux[k] != tmp[k]) {
		    assert(aux[k] < tmp[k]);
		    amin(dp[i+1][j], aux[k] + A[i+1][j]);
		    break;
		}
	    }

	    b_idx = b_idx2;
	}
    }

    LL ans = *min_element(dp[3], dp[3] + LEN[3]);
    if (ans == INF) {
	puts("-1");
    } else {
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}