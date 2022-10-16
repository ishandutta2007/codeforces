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

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = 1 << LOG;

int n,x,y;
llint fak[N],inv[N],sol;

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

llint fastpot(llint A,int eks){
    llint sol = 1;
    llint cur = A;
    for(;eks;eks>>=1){
        if(eks&1)
            sol = mul(sol,cur);
        cur = mul(cur,cur);
    }
    return sol;
}

void precompute(){
    fak[0] = 1;
    inv[0] = 1;
    for(int i = 1;i<N;i++){
        fak[i] = mul(fak[i-1],i);
        inv[i] = fastpot(fak[i],MOD - 2);
    }
}


int main(){
    precompute();
    scanf("%d",&n);
    sol = 1;
    int sum = 0;
    for(int i = 0;i<n;i++){
        scanf("%d",&x);
        sol = mul(sol , mul(fak[sum + x - 1 ] , mul(inv[x - 1],inv[sum])));
        sum += x;
    }
    printf("%d\n",sol);
    return 0;


}