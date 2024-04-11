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

int N, M;
int A[1511][1511];
int B[1511][1511];

VI G[1511];
int deg[1511];
bool sep[1511];

VI que;

struct Data {
    int key;
    int cur_index;
    int a_index;

    bool operator<(const Data &o) const {
	return key != o.key ? key < o.key : cur_index < o.cur_index;
    }
} D[1511];


void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", A[i]+j);
    REP (i, N) REP (j, M) scanf("%d", B[i]+j);

    bool same = true;
    REP (i, N) REP (j, M) if (A[i][j] != B[i][j]) same = false;
    if (same) {
	puts("0");
	puts("");
	return;
    }

    REP (j, M) {
	REP (i, N-1) if (B[i][j] > B[i+1][j]) {
	    G[i].push_back(j);
	    deg[j]++;
	}
    }

    REP (j, M) if (deg[j] == 0) {
	que.push_back(j);
    }

    for (int k=0; k<(int)que.size(); k++) {
	int j = que[k];
	REP (i, N-1) {
	    if (!sep[i+1]) {
		if (B[i][j] < B[i+1][j]) {
		    sep[i+1] = true;
		    EACH (e, G[i]) {
			deg[*e]--;
			if (deg[*e] == 0) {
			    que.push_back(*e);
			}
		    }
		}
	    }
	}
    }


    reverse(que.begin(), que.end());

    REP (i, N) D[i].a_index = i;

    REP (k, que.size()) {
	int j = que[k];
	REP (i, N) {
	    D[i].key = A[D[i].a_index][j];
	    D[i].cur_index = i;
	}

	sort(D, D+N);
    }

    same = true;
    REP (b_index, N) {
	int a_index = D[b_index].a_index;
	REP (j, M) if (B[b_index][j] != A[a_index][j]) same = false;
    }

    if (same) {
	printf("%d\n", (int)que.size());
	EACH (e, que) (*e)++;
	rprintf("%d", que.begin(), que.end());
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}