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

const int MAXN = 300111;
int N, Q;
VI G[MAXN];
int par[MAXN];
int sz[MAXN];
int C[MAXN];
VI ord;


int main() {
    scanf("%d%d", &N, &Q);
    REP (i, N-1) {
	int x;
	scanf("%d", &x);
	x--;
	par[i+1] = x;
	G[x].push_back(i+1);
    }
    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	}
    }
    REP (i_, N) {
	int v  = ord[N-1-i_];
	int x = -1;
	sz[v] = 1;

	EACH (e, G[v]) {
	    sz[v] += sz[*e];
	    if (x == -1 || sz[x] < sz[*e]) x = *e;
	}

	if (x == -1 || sz[x] * 2 <= sz[v]) {
	    C[v] = v;
	} else {
	    C[v] = C[x];
	    while ((sz[v] - sz[C[v]]) * 2 > sz[v]) C[v] = par[C[v]];
	}
    }

    REP ($, Q) {
	int x;
	scanf("%d", &x);
	x--;
	printf("%d\n", C[x] + 1);
    }


    return 0;
}