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
int N, K, D;
int P[MAXN];
vector<pair<int, int> > G[MAXN];
bool cut[MAXN];
int mark[MAXN];
int len[MAXN];

void MAIN() {
    scanf("%d%d%d", &N, &K, &D);
    REP (i, K) scanf("%d", P+i), P[i]--;
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].emplace_back(y, i);
	G[y].emplace_back(x, i);
    }

    sort(P, P+K); 
    K = unique(P, P+K) - P;
    memset(len, 0x3f, sizeof len);
    memset(mark, -1, sizeof mark);
    VI ord;
    REP (i, K) {
	ord.push_back(P[i]);
	len[P[i]] = 0;
	mark[P[i]] = P[i];
    }
    for (int t=0; t<(int)ord.size(); t++) {
	int v = ord[t];
	EACH (e, G[v]) {
	    if (mark[e->first] == mark[v]) continue;
	    if (len[e->first] <= len[v] + 1 || len[v] == D) {
		cut[e->second] = 1;
	    } else {
		len[e->first] = len[v] + 1;
		mark[e->first] = mark[v];
		ord.push_back(e->first);
	    }
	}
    }

    VI ans;
    REP (i, N-1) if (cut[i]) ans.push_back(i+1);
    printf("%d\n", (int) ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}