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

const LL MOD = 1000000007;

const int NUM = 2011;
LL comb[NUM+1][NUM/2+1];
void make_comb() {
    comb[0][0]=1;
    for (int i=1; i<=NUM; i++) {
        comb[i][0]=1;
        for (int j=1; j<=NUM/2; j++) {
            comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
	    comb[i][j] %= MOD;
        }
    }
}

LL nCk(int n, int k) {
    return comb[n][min(k, n-k)];
}

int N;
int C[1011];

int main() {
    make_comb();
    
    scanf("%d", &N);
    REP (i, N) scanf("%d", C+i);

    LL ans = 1;
    LL sum = 0;
    REP (i, N) {
	ans = ans * nCk(sum+C[i]-1, C[i]-1) % MOD;
	sum += C[i];
    }
    printf("%d\n", (int)ans);
    return 0;
}