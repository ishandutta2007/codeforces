#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N, M;
int A[100111], B[100111];

int deg[100111];
int dp[100111];
VI G[100111];

bool check(int mid) {
    REP (i, N) {
	deg[i] = 0;
	G[i].clear();
	dp[i] = 1;
    }

    REP (i, mid) {
	deg[B[i]]++;
	G[A[i]].push_back(B[i]);
    }

    stack<int> S;
    REP (i, N) {
	if (deg[i] == 0) {
	    S.push(i);
	}
    }

    while (!S.empty()) {
	int v = S.top(); S.pop();
	EACH (e, G[v]) {
	    amax(dp[*e], dp[v] + 1);
	    deg[*e]--;
	    if (deg[*e] == 0) S.push(*e);
	}
    }

    return N == *max_element(dp, dp+N);
}


int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--;
	B[i]--;
    }

    int lo = 0, hi = M+1;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;

	if (check(mid)) hi = mid;
	else lo = mid;
    }

    if (hi == M + 1) puts("-1");
    else printf("%d\n", hi);

    return 0;
}