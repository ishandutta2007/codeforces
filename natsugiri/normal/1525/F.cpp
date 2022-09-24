#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

struct Matching2 { // for bipartite graph
    static const int INF = 1<<29;
    const VI* G;
    VI matchM, matchW, dist;
    int ans;
    int SNK;

    bool dfs(int v) {
	if (v == SNK) return true;
	EACH (e, G[v]) if (dist[matchW[*e]] == dist[v]+1 && dfs(matchW[*e])) {
	    matchM[v] = *e;
	    matchW[*e] = v;
	    return true;
	}
	dist[v] = INF;
	return false;
    }

    Matching2(const VI G_[], int sizeM, int sizeW): G(G_), matchM(sizeM, -1), matchW(sizeW, sizeM), dist(sizeM+1), ans(0), SNK(sizeM) {
	VI qu; qu.reserve(sizeM+1);
	while (1) {
	    dist[SNK] = INF;
	    REP (i, sizeM) {
		if (matchM[i] == -1) { dist[i] = 0; qu.push_back(i); }
		else dist[i] = INF;
	    }
	    for (int i=0; i<(int)qu.size(); i++) {
		int v = qu[i];
		if (dist[v] < dist[SNK]) {
		    EACH (e, G[v]) if (dist[matchW[*e]] == INF) {
			dist[matchW[*e]] = dist[v] + 1;
			qu.push_back(matchW[*e]);
		    }
		}
	    }
	    if (dist[SNK] == INF) break;
	    qu.clear();
	    REP (i, sizeM) if (matchM[i] == -1 && dfs(i)) ans++;
	}
	REP (i, sizeW) if (matchW[i] == SNK) matchW[i] = -1;
    }
};

int N;
int M, K;
VI G[55];

vector<pair<int, int> > E;
bool in[55];
bool out[55];

LL R[55];

vector<pair<int, int> > B[55];

int calc() {
    REP (i, N) G[i].clear();

    EACH (e, E) {
	if (!out[e->first] && !in[e->second]) {
	    G[e->first].push_back(e->second);
	}
    }

    Matching2 X(G, N, N);

    return N - X.ans;
}

LL X[55], Y[55];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	E.emplace_back(x, y);
    }

    for (int k=1; k<=K; k++) {
	scanf("%lld%lld", X+k, Y+k);
    }

    int cur = calc();

    for (int k=1; k<=K; k++) {
	while (cur <= k) {
	    pair<int, int> p(0, 0);

	    REP (i, N) {
		if (!in[i]) {
		    in[i] = true;
		    int tmp = calc();
		    if (cur < tmp) {
			p = make_pair(i, -1);
			cur = tmp;
			goto OUT;
		    }
		    in[i] = false;
		}
		if (!out[i]) {
		    out[i] = true;
		    int tmp = calc();
		    if (cur < tmp) {
			p = make_pair(i, 1);
			cur = tmp;
			goto OUT;
		    }
		    out[i] = false;
		}
	    }

OUT:
	    ;

	    B[k].push_back(p);
	}

	// eprintf("[%d] :", k);
	// EACH (e, B[k]) eprintf("%d %d, ", e->first, e->second);
	// eprintf("\n");
    }


    LL ans = -(1LL<<60);
    using Tuple = tuple<int, int, int>;
    vector<Tuple> best;

    // non zero;
    {
	vector<Tuple> guess;
	LL tmp = 0;
	int min_y = 1;
	for (int k=1; k<=K; k++) {
	    if (Y[min_y] > Y[k]) {
		min_y = k;
	    }
	    tmp += X[k];
	    tmp -= Y[min_y] * (LL)B[k].size();

	    EACH (e, B[k]) {
		guess.emplace_back(min_y, e->first, e->second);
	    }
	}

	if (ans < tmp) {
	    ans = tmp;
	    best = guess;
	}
    }

    // zero;
    for (int z=1; z<=K; z++) {
	vector<Tuple> guess;
	LL tmp = 0;
	int min_y = 1;
	memset(R, 0, sizeof R);

	for (int k=1; k<=K; k++) {
	    if (Y[min_y] > Y[k]) {
		min_y = k;
	    }

	    if (k < z) {
		R[min_y] += Y[min_y] * (LL)B[k].size();
		if (X[min_y] < R[min_y]) {
		    goto BAD;
		}
		tmp += X[k];
		tmp -= Y[min_y] * (LL)B[k].size();
	    } else if (z == k) {

	    } else {
		tmp += X[k];
	    }

	    EACH (e, B[k]) {
		if (k < z) {
		    guess.emplace_back(min_y, e->first, e->second);
		} else {
		    guess.emplace_back(z, e->first, e->second);
		}
	    }
	}

	if (ans < tmp) {
	    ans = tmp;
	    best = guess;
	}
BAD:
	;
    }


    eprintf("SCORE = %lld\n", ans);
    VI ANS;
    for (int k=1, idx=0; k<=K; k++) {
	while (idx < (int)best.size() && get<0>(best[idx]) <= k) {
	    int dummy, a, sgn;
	    tie(dummy, a, sgn) = best[idx];
	    ANS.push_back((a+1) * sgn);
	    idx++;
	}
	ANS.push_back(0);
    }
    printf("%d\n", (int)ANS.size());
    rprintf("%d", ANS.begin(), ANS.end());
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}