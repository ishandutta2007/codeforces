#include<cassert>
#include<tuple>
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

const int BITS = 30;
const int MAXN = 100111;
int N, M;
vector<pair<int, int> > G[MAXN];

typedef tuple<int, int, int> Edge;
vector<Edge> E;

int par[MAXN];
int dist[MAXN];

void build_tree() {
    memset(par, -1, sizeof par);
    par[0] = 0;
    dist[0] = 0;

    VI ord; ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	assert(i_ < (int)ord.size());
	int v = ord[i_];
	EACH (e, G[v]) {
	    if (par[e->first] == -1) {
		par[e->first] = v;
		dist[e->first] = dist[v] ^ e->second;
		ord.push_back(e->first);
	    } else {
		E.emplace_back(v, e->first, e->second);
	    }
	}
    }
}

VI C;
void cycles() {
    EACH (e, E) {
	int x, y, w;
	tie(x, y, w) = *e;
	C.push_back(dist[x] ^ dist[y] ^ w);
    }

    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());
}

void ge() {
    if (C.empty()) return;
    int n = C.size();
    int stop = 0;
    VI ret(BITS, 0);
    for (int j=BITS; j--;) {
	int i = stop;
	while (i < n && (~C[i] >>  j & 1)) i++;
	if (i < n) {
	    int x = ret[j] = C[i];
	    swap(C[i], C[stop++]);
	    for (i=stop; i<n; i++) {
		if (C[i] >> j & 1) C[i] ^= x;
	    }
	}
    }
    C = ret;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	G[x].emplace_back(y, w);
	G[y].emplace_back(x, w);
    }

    build_tree();
    cycles();
    ge();

    int W = dist[N-1];
    for (int i=BITS; i--;) {
	if ((W >> i) & 1) {
	    EACH (e, C) {
		int k = *e;
		if ((k >> i) == 1) {
		    W ^= k;
		    break;
		}
	    }
	}
    }
    printf("%d\n", W);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}