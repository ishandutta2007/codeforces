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


const int SMAX = 25511;
int N, K, S;
unsigned Q[155];
unsigned dp[155][SMAX];

int main() {
    scanf("%d%d%d", &N, &K, &S);
    REP (i, N) scanf("%d", Q+i);

    memset(dp, 0x3f, sizeof dp);
    amin(S, N*N);
    dp[0][0] = 0;
    REP (i, N) {
        for (int k=min(K, i); k>=0; k--) {
            int p = i - k;
            REP (s, S+1)
                amin(dp[k+1][s+p], dp[k][s] + Q[i]);
        }
    }


    unsigned ans = 0x3f3f3f3f;
    REP (s, S+1) amin(ans, dp[K][s]);
    printf("%u\n", ans);

    return 0;
}