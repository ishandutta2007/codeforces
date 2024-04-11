#include <cstdio>
#include <algorithm>

const int N = 5e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

using namespace std;

typedef long long int llint;

llint pot[N],dp[N],midje[N];
llint r,l,t,sol = 0;

llint gause(llint x){
    if(x&1) return ((x-1)/2) * x % MOD;
    else return (x/2) * (x-1) % MOD;
}

void precompute(){
    pot[0] = 1;
    for(int i = 1;i<N;i++){
        pot[i] = (pot[i-1] * t) % MOD;
    }
    dp[2] = 1;
    for(int i = 2;i<N;i++){
        if(midje[i]) continue;
        midje[i] = i;
        for(int j = 2;j*i<N;j++){
            if(!midje[i*j])midje[i*j] = i;
        }
    }
    dp[1] = 0;
    for(int i = 2;i<N;i++){
        dp[i] = ((gause(midje[i]) * (i / midje[i])) % MOD + dp[i / midje[i]]) % MOD;
    }
}



int main(){
    scanf("%I64d %I64d %I64d",&t,&l,&r);
    precompute();
    for(int i = l;i<=r;i++){
        sol = (sol + (dp[i] * pot[i - l]) % MOD) % MOD;
    }
    printf("%I64d\n",sol);
}