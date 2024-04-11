#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

double ans[100011];

struct Edge {
    int x, y, t;
    Edge() {}
    Edge(int x_, int y_, int t_): x(x_), y(y_), t(t_) {}
} E[200011];


VI G[100011];
int par[100011];
bool use[100011];
LL dp[100011][2];

VI que;

bool yes;
vector<LL> guess;

void solve(int root) {
    que.clear();
    que.push_back(root);
    par[root] = root;
    use[root] = true;

    dp[root][0] = 0;
    dp[root][1] = 1;

    guess.clear();

    for (int i_=0; i_<(int)que.size(); i_++) {
	int v = que[i_];
	EACH (e, G[v]) {
	    int w = v ^ E[*e].x ^ E[*e].y;

	    LL d0 = E[*e].t - dp[v][0];
	    LL d1 = -dp[v][1];
	    if (use[w]) {
		if (dp[w][1] == d1) {
		    if (dp[w][0] != d0) {
			yes = false;
		    }
		} else {
		    // w0 + w1 x == d0 + d1 x
		    // w0 - d0 == (d1 - w1) x;
		    LL sum = dp[w][0] - d0;
		    LL c = d1 - dp[w][1];
		    assert(c == 2 || c == -2);
		    guess.push_back(sum * 2 / c);
		}
	    } else {
		dp[w][0] = d0;
		dp[w][1] = d1;
		par[w] = v;
		use[w] = true;
		que.push_back(w);
	    }
	}
    }

    if (!yes) return;

    sort(guess.begin(), guess.end());

    double x = 0;
    if (guess.empty()) {
	vector<LL> pos;
	EACH (e, que) {
	    pos.push_back(-dp[*e][0] * dp[*e][1]);
	}
	sort(pos.begin(), pos.end());
	x = pos[(int)pos.size() / 2];
    } else if (guess[0] == guess.back()) {
	x = guess[0] * 0.5;
    } else {
	yes = false;
	return;
    }

    EACH (e, que) {
	ans[*e] = dp[*e][0] + dp[*e][1] * x;
    }
}

int N, M;

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	int x, y, t;
	scanf("%d%d%d", &x, &y, &t);
	x--; y--;
	E[i] = Edge(x, y, t);
	G[x].push_back(i);
	G[y].push_back(i);
    }

    yes = true;
    REP (i, N) if (!use[i]) {
	solve(i);
    }

    if (yes) {
	puts("YES");
	rprintf("%.12f", ans, ans+N);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}