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

int N;

LL A[150011];
int L[150011];
int R[150011];

void MAIN() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%lld", A+i);
    REP (i, N+2) {
	L[i] = i-1;
	R[i] = i+1;
    }

    
    priority_queue<pair<LL, int> > Q;
    for (int i=1; i<=N; i++) {
	Q.emplace(-A[i], -i);
    }

    while (Q.size() >= 2u) {
	pair<LL, int> p = Q.top(); Q.pop();
	if (p.first != Q.top().first) continue;

	int x = -p.second;
	int y = -Q.top().second; Q.pop();

	R[L[x]] = R[x];
	L[R[x]] = L[x];
	A[y] += A[y];
	Q.emplace(-A[y], -y);
    }

    vector<LL> ans;
    int cur = 0;
    while (1) {
	cur = R[cur];
	if (cur <= N) ans.push_back(A[cur]);
	else break;
    }

    printf("%d\n", (int)ans.size());
    rprintf("%lld", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}