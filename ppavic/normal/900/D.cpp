#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef long long int llint;

const int MOD = 1e9 + 7;

int k,n;

int fastpot(int x){
    llint sol = 1,pot = 2;
    for(;x;x>>=1){
        if(x&1) sol = (sol * pot) % MOD;
        pot = (pot * pot) % MOD;
    }
    return (int)sol;
}

int main(){
    scanf("%d%d",&k,&n);
    if(n%k) {printf("0\n");return 0;}
    else n /= k;
    int oln = n;
    vector < int > prim;
    for(int i = 2;i*i<=n;i++){
        if(n%i) continue;
        prim.push_back(i);
        for(;!(n%i);n/=i);
     }
     if(n>1) prim.push_back(n);
     n = oln;
     int sol = 0;
     for(int i = 0;i<(1<<(prim.size()));i++){
        int div = 1;
        for(int j = 0;j<prim.size();j++)
            if(i&(1<<j))
                div *= prim[j];
        if(__builtin_popcount(i)&1)
            sol = (sol - fastpot(n / div-1) + MOD) % MOD;
        else
            sol = (sol + fastpot(n / div-1)) % MOD;
     }
     printf("%d\n",sol);
}