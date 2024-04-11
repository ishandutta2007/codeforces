#include<map>
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

int N;
map<char, int> G[300111];

int ans[300111];
int DEPTH;
void rec(const VI &w) {
    REP (i, 26) {
	char c = i + 'a';
	VI k;
	EACH (e, w) {
	    auto it = G[*e].find(c);
	    if (it != G[*e].end()) k.push_back(it->second);
	}

	if (k.size() > 1u) {
	    ans[DEPTH] += k.size() - 1;
	    rec(k);
	}
    }
}

void dfs(int v, int depth) {
    if (G[v].empty()) return;
    if (G[v].size() == 1u) {
	ans[depth]++;
    } else {
	VI w; w.reserve(G[v].size());
	EACH (e, G[v]) w.push_back(e->second);
	DEPTH = depth;
	ans[depth] += w.size();
	rec(w);
    }

    EACH (e, G[v]) {
	dfs(e->second, depth+1);
    }
}

int main() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	char c[111];
	scanf("%d%d%s", &x, &y, c);
	x--; y--;
	G[x].insert(make_pair(c[0], y));
    }


    dfs(0, 1);

    int pos = max_element(ans, ans + N + 10) - ans;
//    rprintf("%d", ans, ans + N + 1);
    printf("%d\n%d\n", N - ans[pos], pos);


    return 0;
}