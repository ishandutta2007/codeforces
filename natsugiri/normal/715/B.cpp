#include<queue>
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

const LL INF = 1LL << 60;

int N, M, S, T;
LL L;
int A[100111], B[100111];
LL D[100111];
LL W[100111];
vector<pair<int, int> > G[1111];
LL len[1111];
LL len2[1111];

LL dijkstra() {
    REP (i, N) len[i] = INF;
    len[S] = 0;
    priority_queue<pair<LL, int> > Q;
    Q.push(make_pair(-0, S));
    while (!Q.empty()) {
	int dst = Q.top().second;
	LL cst = -Q.top().first;
	Q.pop();
	if (len[dst] < cst) continue;
	if (dst == T) break;
	EACH (e, G[dst]) {
	    LL tmp = cst + e->second;
	    if (tmp < len[e->first]) {
		len[e->first] = tmp;
		Q.push(make_pair(-tmp, e->first));
	    }
	}
    }

    return len[T];
}

void build(LL m) {
    REP (i, N) G[i].clear();
    REP (i, M) {
	LL w = (W[i] == 0? m: W[i]);
	if (m == -1) w = W[i] + D[i];
	G[A[i]].push_back(make_pair(B[i], w));
	G[B[i]].push_back(make_pair(A[i], w));
    }
}


int main() {
    scanf("%d%d%lld%d%d", &N, &M, &L, &S, &T);
    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	A[i] = x; B[i] = y; W[i] = w;
    }


    LL lo = 0, hi = L + 2;
    while (hi - lo > 1) {
	LL m = (lo + hi) / 2;
	build(m);
	LL t = dijkstra();

	if (t == L) {
	    puts("YES");
	    REP (i, M) printf("%d %d %lld\n", A[i], B[i], (W[i] == 0? (LL)m: W[i]));
	    return 0;
	}
	(t <= L? lo: hi) = m;
    }

    if (lo == 0 || hi == L + 2) {
	puts("NO");
	return 0;
    }

    REP (i, M) if (W[i] == 0) D[i] = lo;

    int left = -1, right = M+1;
    while (right - left > 1) {
	int m = (left + right) / 2;
	REP (i, M) if (W[i] == 0) D[i] = (i >= m? lo : hi);
	build(-1);
	LL t = dijkstra();
	(t <= L? left: right) = m;
    }

    REP (i, M) if (W[i] == 0) D[i] = (i >= left? lo : hi);
//   build(-1);
//    LL t = dijkstra();
//    eprintf("%d %d %lld\n", left, right, t);

    puts("YES");
    REP (i, M) printf("%d %d %lld\n", A[i], B[i], (W[i] == 0? W[i] + D[i]: W[i]));

    return 0;
}