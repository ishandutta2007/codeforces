#include<queue>
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
LL T;

vector<pair<int, int> > G[MAXN]; // (time, id);
VI ansv;

void solve() {
    priority_queue<pair<int, int> > Q; // (time, id);
    LL sum = 0;
    for (int k=N; k>=1; k--) {
	EACH (e, G[k]) {
	    sum += e->first;
	    Q.push(*e);
	}
	while ((int)Q.size() > k) {
	    sum -= Q.top().first;
	    Q.pop();
	}
	if ((int)Q.size() == k && sum <= T) {
	    while (!Q.empty()) {
		ansv.push_back(Q.top().second+1);
		Q.pop();
	    }
	    return;
	}
    }

}

void MAIN() {
    scanf("%d%lld", &N, &T);
    REP (i, N) {
	int a, t;
	scanf("%d%d", &a, &t);
	G[a].emplace_back(t, i);
    }

    solve();
    printf("%d\n", (int)ansv.size());
    printf("%d\n", (int)ansv.size());
    rprintf("%d", ansv.begin(), ansv.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}