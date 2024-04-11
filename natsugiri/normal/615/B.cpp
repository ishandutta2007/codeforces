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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N, M;
VI G[100111];
int deg[100111];
int dp[100111]; // number of vertices

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	if (a > b) swap(a, b);
	G[b].push_back(a);
	deg[a]++;
	deg[b]++;
    }

    LL ans = 0;
    REP (i, N) {
	dp[i] = 1;
	EACH (e, G[i]) {
	    amax(dp[i], dp[*e] + 1);
	}
	amax(ans, (LL)deg[i] * dp[i]);
    }

    printf("%lld\n", ans);
    
    return 0;
}