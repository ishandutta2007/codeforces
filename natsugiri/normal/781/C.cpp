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

const int MAXN = 200111;
int N, M, K;
VI G[MAXN];
VI ord;
bool use[MAXN];

void dfs(int v) {
    ord.push_back(v);
    use[v] = true;

    EACH (e, G[v]) if (!use[*e]) {
	dfs(*e);
	ord.push_back(v);
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[y].push_back(x);
	G[x].push_back(y);
    }

    if (N == 1) {
	REP (i, K) puts("1 1");
	return 0;
    }

    dfs(0);
    if (ord.size() > 1u && ord[0] == ord.back()) ord.pop_back();

    int cur = 0;
    int c = (2 * N + K - 1) / K;
    REP (i, K) {
	printf("%d", c);
	REP (j, c) {
	    printf(" %d", ord[cur++] + 1);
	    if (cur == (int)ord.size()) cur = 0;
	}
	puts("");
    }

    return 0;
}