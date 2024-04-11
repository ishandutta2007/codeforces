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
int N;
int d0[MAXN], d1[MAXN];
VI G[MAXN];
bool P[MAXN];

VI ord;
int bfs(int s, int *d) {
    ord.clear();
    ord.reserve(N);
    ord.push_back(s);
    memset(d, -1, sizeof (int) * N);
    d[s] = 0;
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (d[*e] == -1) {
	    d[*e] = d[v] + 1;
	    ord.push_back(*e);
	}
    }

    return max_element(d, d+N) - d;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    int x = bfs(0, d1);
    int y = bfs(x, d0);
    bfs(y, d1);

    VI path;
    path.push_back(x);
    P[x] = true;
    int cur = x;
    while (cur != y) {
	EACH (e, G[cur]) {
	    if (d1[cur] - 1 == d1[*e]) {
		cur = *e;
		break;
	    }
	}
	path.push_back(cur);
	P[cur] = true;
    }

    LL ans = 0;
    REP (i, N) if (!P[i]) {
	ans += max(d0[i], d1[i]);
    }

    LL len = path.size();
    ans += len * (len - 1) / 2;

    printf("%lld\n", ans);

    REP (i_, N) {
	int v = ord[N-1-i_];
	if (!P[v]) {
	    if (d0[v] < d1[v]) {
		printf("%d %d %d\n", y+1, v+1, v+1);
	    } else {
		printf("%d %d %d\n", x+1, v+1, v+1);
	    }
	}
    }
    REP (i, (int)path.size()-1) {
	printf("%d %d %d\n", y+1, path[i]+1, path[i]+1);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}