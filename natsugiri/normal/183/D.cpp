#include<queue>
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
double P[3011][311];
double dp[311][3011];

double update(int t) {
    REP (i, N) 
	dp[t][i+1] += (1.0 - P[i][t]) * dp[t][i];
    double ret = 0;
    for (int i=N; i--; ) {
	dp[t][i+1] = P[i][t] * dp[t][i];
	ret += dp[t][i+1];
    }
    dp[t][0] = 0;
    return ret;
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) {
	int x;
	scanf("%d", &x);
	P[i][j] = x / 1000.0;
    }
    
    REP (i, M) dp[i][0] = 1;
    priority_queue<pair<double, int> > Q;
    REP (t, M) Q.push(make_pair(update(t), t));

    double ans = 0;
    REP (z, N) {
	pair<double, int> p = Q.top(); Q.pop();
//	printf("%.9f\n", p.first);
	ans += p.first;
	p.first = update(p.second);
	Q.push(p);
    }

    printf("%.9f\n", ans);

    return 0;
}