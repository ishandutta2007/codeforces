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

const int MAXN = 400111;
int N;
pair<int, int> W[MAXN];
char S[MAXN];

int ans[MAXN];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", &W[i].first), W[i].second = i+1;
    scanf("%s", S);

    sort(W, W+N);
    priority_queue<pair<int, int> > Q;
    int cur = 0;
    REP (i, N+N) {
	if (S[i] == '0') {
	    Q.push(W[cur]);
	    ans[i] = W[cur++].second;
	} else {
	    ans[i] = Q.top().second;
	    Q.pop();
	}
    }

    rprintf("%d", ans, ans+N+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}