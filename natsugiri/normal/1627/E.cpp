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

int N, M, K;
int A[100011];
int B[100011];
int C[100011];
int D[100011];
int H[100011];
int X[100011];

vector<pair<int, int> > G[200011];
LL dist[200011];


vector<pair<int, int> > P;
int id(int a, int b) {
    auto it = lower_bound(P.begin(), P.end(), make_pair(a, b));
    assert(it->first == a && it->second == b);
    return it - P.begin();
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%d", X+i);

    REP (i, K) {
	scanf("%d%d%d%d%d", A+i, B+i, C+i, D+i, H+i);
    }

    P.clear();
    P.emplace_back(1, 1);
    P.emplace_back(N, M);
    REP (i, K) {
	P.emplace_back(A[i], B[i]);
	P.emplace_back(C[i], D[i]);
    }
    sort_unique(P);

    REP (i, P.size()) G[i].clear();
    REP (i, K) {
	int x = id(A[i], B[i]);
	int y = id(C[i], D[i]);
	G[x].emplace_back(y, H[i]);
    }

    memset(dist, 0x3f, sizeof (LL) * P.size());
    const LL BAD = dist[0];
    dist[0] = 0;

    for (int i=0; i<(int)P.size(); ) {
	int j = i;
	while (j < (int)P.size() && P[i].first == P[j].first) j++;

	LL x = X[P[i].first-1];

	for (int k=i; k+1<j; k++) if (dist[k] != BAD) {
	    amin(dist[k+1], dist[k] + x * (P[k+1].second - P[k].second));
	}
	for (int k=j-2; i<=k; k--) if (dist[k+1] != BAD) {
	    amin(dist[k], dist[k+1] + x * (P[k+1].second - P[k].second));
	}

	for (int k=i; k<j; k++) EACH (e, G[k]) if (dist[k] != BAD) {
	    amin(dist[e->first], dist[k] - e->second);
	}
	i = j;
    }

    LL ans = dist[P.size()-1u];
    if (ans == BAD) {
	puts("NO ESCAPE");
    } else {
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}