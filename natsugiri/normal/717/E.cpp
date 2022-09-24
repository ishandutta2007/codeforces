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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, C[200111];
VI G[200111];
VI ans;

void dfs(int v, int p) {
    ans.push_back(v);
    C[v] = -C[v];

    EACH (e, G[v]) if (*e != p) {
	dfs(*e, v);

	ans.push_back(v);
	C[v] = -C[v];

	if (C[*e] == -1) {
	    C[*e] = -C[*e];
	    ans.push_back(*e);
	    C[v] = -C[v];
	    ans.push_back(v);
	}
    }
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", C+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    if (count(C, C+N, -1) == 0) {
	puts("1");
	return 0;
    }
    C[0] = -C[0];
    dfs(0, 0);

    if (C[0] == -1) {
	int w = G[0][0];
	C[w] = -C[w];
	ans.push_back(w);

	C[0] = -C[0];
	ans.push_back(0);

	C[w] = -C[w];
	ans.push_back(w);
    }

    REP (i, ans.size()) printf("%d%c", ans[i]+1, i==(int)ans.size() - 1? '\n': ' ');

    return 0;
}