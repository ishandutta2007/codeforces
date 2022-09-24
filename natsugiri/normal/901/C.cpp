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

const int MAXN = 300111;
int N, M;
VI G[MAXN];
int A[MAXN];
int B[MAXN];
LL sums[MAXN];
int par[MAXN];
int depth[MAXN];

bool use[MAXN];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    memset(A, -1, sizeof A);
    memset(par, -1, sizeof par);
    int cnt = 0;

    REP (i, N+1) B[i] = N;

    REP (i, N) if (!use[i]) {
	VI ord;
	ord.push_back(i);
	use[i] = true;
	for (int j=0; j<(int)ord.size(); j++) {
	    int v = ord[j];
	    EACH (e, G[v]) if (*e != par[v]) {
		if (use[*e]) {
		    if (A[v] == -1) {
			int mi = v, ma = v;
			int posA = v, posB = *e;
			while (posA != posB) {
			    if (depth[posA] < depth[posB]) swap(posA, posB);
			    amax(ma, posA);
			    amin(mi, posA);
			    A[posA] = cnt;
			    posA = par[posA];
			}
			amax(ma, posA);
			amin(mi, posA);
			amin(B[mi], ma);
			A[posA] = cnt;
			cnt++;
		    }
		} else {
		    use[*e] = true;
		    par[*e] = v;
		    depth[*e] = depth[v] + 1;
		    ord.push_back(*e);
		}
	    }
	}
    }

    for (int i=N; i--;) amin(B[i], B[i+1]);
    REP (i, N) sums[i+1] = sums[i] + B[i] - i;

    int Q;
    scanf("%d", &Q);
    REP (i, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;

	// B[lo] < r
	// B[hi] >= r
	int lo = l-1, hi = r;
	while (hi - lo > 1) {
	    int mid = (lo + hi) / 2;
	    (B[mid] < r? lo: hi) = mid;
	}
	
	LL ans = 0;
	ans += sums[hi] - sums[l];
	ans += (LL)(r - hi) * (r - hi + 1) / 2;
	printf("%lld\n", ans);
    }
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}