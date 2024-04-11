#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>

#define debag(x) cerr << #x << " = " << (x) << endl;

using namespace std;

typedef long long int llint;
typedef pair < int,int> pii;
typedef long double ld;

const int N = 105;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = 1 << LOG;

llint n,m;
llint fak[N*N],inv[N*N],sol,precomp[N][N];
int dp[N][N*N],k;

inline llint add(llint A,llint B){
    if(A + B > MOD) return A + B - MOD;
    return A + B;
}

inline llint sub(llint A,llint B){
    if(A - B  < 0) return A - B + MOD;
    return A - B;
}

inline llint mul(llint A,llint B){
    return A * B  % MOD;
}

llint fastpot(llint A,llint eks){
    llint sol = 1;
    llint cur = A;
    for(;eks;eks>>=1LL){
        if(eks&1)
            sol = mul(sol,cur);
        cur = mul(cur,cur);
    }
    return sol;
}

void precompute(){
    fak[0] = 1;
    inv[0] = 1;
    for(int i = 1;i<N*N;i++){
        fak[i] = mul(fak[i-1],i);
        inv[i] = fastpot(fak[i],MOD - 2);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=n;j++){
            precomp[i][j] = fastpot(mul(fak[n] , mul(inv[j] , inv[n - j])), m / n + int((m%n) > i));
        }
    }

}

int f(int i,int j){
    if(i == n) return int(j == 0);
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 0;
    for(int l = 0;l<=n;l++){
        dp[i][j] = add(mul((llint)f(i + 1, j - l) , precomp[i][l]),dp[i][j]);
    }
    return dp[i][j];
}

int main(){
    scanf("%I64d %I64d %d",&n,&m,&k);
    precompute();
    memset(dp,-1,sizeof(dp));
    printf("%d\n",f(0 , k));
}