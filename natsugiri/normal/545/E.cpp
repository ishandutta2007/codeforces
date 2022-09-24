#include<cassert>
#include<queue>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

const LL INF = 1LL<<60;

struct Edge {
    int dst;
    LL cst, sub;
    int id;
    bool operator<(const Edge &y) const {
	return cst == y.cst ? sub < y.sub:
	    cst > y.cst;
    }
};

int N, M, S;
vector<Edge> G[300011];
int A[300011], B[300011];
LL W[300011];
bool use[300011];
VI ans;

int main() {

    scanf("%d%d", &N, &M);
    REP (i, M) {
	int a, b; LL c;
	scanf("%d%d%lld", &a, &b, &c);
	a--; b--;
	A[i] = a;
	B[i] = b;
	W[i] = c;
	G[a].push_back((Edge){ b, c, 0, i} );
	G[b].push_back((Edge){ a, c, 0, i} );
    }

    scanf("%d", &S);
    S--;

    LL sum = 0;
    vector<LL> len(N, INF);
    len[S] = 0;
    priority_queue<Edge> Q;
    Q.push((Edge){ S, 0, 0, -1 });

    while (!Q.empty()) {
	Edge e = Q.top(); Q.pop();
//	eprintf("%d %d %lld %lld\n", e.dst+1, e.id+1, e.cst, e.sub);
	if (len[e.dst] < e.cst) continue;
	if (use[e.dst]) continue;
	else {
	    use[e.dst] = true;
	    if (e.id >= 0) {
		sum += W[e.id];
		ans.push_back(e.id);
	    }
	}

	EACH (f_, G[e.dst]) {
	    Edge f = *f_;
	    LL c = e.cst + f.cst;
	    if (len[f.dst] >= c) {
		len[f.dst] = c;
		Q.push((Edge){ f.dst, c, e.cst, f.id });
	    }
	}
    }


    printf("%lld\n", sum);
    sort(ans.begin(), ans.end());
    assert(N-1 == (int)ans.size());
    REP (i, N-1) printf("%d%c", ans[i]+1, i==N-2?'\n':' ');
    return 0;
}