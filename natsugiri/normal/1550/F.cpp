#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>
#include<queue>

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

int N, Q, S;
LL D;
LL A[200011];
map<LL, int> A2V;

struct Query {
    int i;
    int to;
    LL k;

    bool operator<(const Query &o) const {
	return k < o.k;
    }
} query[200011];

struct Data {
    LL dist;
    int from;
    int to;
    int sgn1;
    int sgn2;

    Data(){}
    Data(LL d_, int f_, int t_, int s1, int s2):
	dist(d_),
	from(f_),
	to(t_),
	sgn1(s1),
	sgn2(s2)
    {
    }

    bool operator<(const Data &o) const {
	return dist > o.dist;
    }
};

priority_queue<Data> PQ;
LL dist_plus[200011];
LL dist_minus[200011];
bool vis[200011];
bool ans[200011];

void reach(int v) {
    if (vis[v]) return;
    vis[v] = true;
    dist_plus[v] = 0;
    dist_minus[v] = 0;
    bool b = A2V.erase(A[v]);
    assert(b);

    for (int sgn=-1; sgn<=1; sgn+=2) {
	LL x = A[v] + D * sgn;
	auto it = A2V.lower_bound(x);
	if (it != A2V.end()) {
	    assert(!vis[it->second]);
	    LL tmp = it->first - x;
	    if (dist_plus[it->second] > tmp) {
		dist_plus[it->second] = tmp;
		PQ.emplace(tmp, v, it->second, sgn, +1);
	    }
	}
	if (it != A2V.begin()) {
	    it--;
	    assert(!vis[it->second]);
	    LL tmp = x - it->first;
	    if (dist_minus[it->second] > tmp) {
		dist_minus[it->second] = tmp;
		PQ.emplace(tmp, v, it->second, sgn, -1);
	    }
	}
    }
}

void MAIN() {
    scanf("%d%d%d%lld", &N, &Q, &S, &D);
    S--;
    REP (i, N) scanf("%lld", A+i);
    REP (i, Q) {
	int to, k;
	scanf("%d%d", &to, &k);
	to--;

	query[i].i = i;
	query[i].to = to;
	query[i].k = k;
    }

    sort(query, query+Q);
    REP (i, N) A2V.emplace(A[i], i);

    memset(dist_plus, 0x3f, sizeof dist_plus);
    memset(dist_minus, 0x3f, sizeof dist_minus);

    reach(S);

    REP (i_, Q) {
	LL k = query[i_].k;

	while (!PQ.empty() && PQ.top().dist <= k) {
	    Data d = PQ.top();
	    PQ.pop();
	    reach(d.to);

	    LL x = A[d.from] + D * d.sgn1;

	    auto it = A2V.lower_bound(x);
	    if (d.sgn2 == 1) {
		if (it != A2V.end()) {
		    assert(!vis[it->second]);
		    LL tmp = it->first - x;
		    if (dist_plus[it->second] > tmp) {
			dist_plus[it->second] = tmp;
			PQ.emplace(tmp, d.from, it->second, d.sgn1, +1);
		    }
		}
	    } else {
		if (it != A2V.begin()) {
		    it--;
		    assert(!vis[it->second]);
		    LL tmp = x - it->first;
		    if (dist_minus[it->second] > tmp) {
			dist_minus[it->second] = tmp;
			PQ.emplace(tmp, d.from, it->second, d.sgn1, -1);
		    }
		}
	    }
	}

	ans[query[i_].i] = vis[query[i_].to];
    }

    REP (i, Q) puts(ans[i]? "Yes": "No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}