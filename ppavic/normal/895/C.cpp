#include <cstdio>
#include <map>
#include <vector>
#include <cassert>
#include <cstring>

using namespace std;

typedef long long int llint;

const int N = 2050;
const int M = 1e5 + 500;
const llint MOD = 1e9 + 7;

int prim[20] = {2,3,5,7,11,13,17,19,23,29,31};
map < int , int > wild;


llint dp[N][N];
llint msk[N],pot[M];
int n;

void make_pot(){
    pot[0] = 1;
    for(int i = 1;i<M;i++)
        pot[i] = 2 * pot[i-1] % MOD;
}


llint f(int i, int j){
    if(i == N) return int(j == 0);
    if(dp[i][j] != -1) return dp[i][j];
    if(msk[i] == 0) return dp[i][j] = f(i+1,j);
    return dp[i][j] = ((f(i+1,j) + f(i+1,j^i)) % MOD) * pot[msk[i]-1] % MOD;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    make_pot();
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x == 1){msk[0]++;continue;}
        int mask = 0;
        for(int j = 0;j<11;j++){
            int cc = 0;
            while((x % prim[j]) == 0) {cc++;x/=prim[j];}
            if(cc&1) mask |= (1 << j);
        }
        if(x == 1) msk[mask]++;
        else wild[x]++;
    }
    llint sol = f(0,0);
    for(map<int,int>::iterator it = wild.begin();it != wild.end();it++){
        int x = it->second;
        llint kof = pot[x-1];
        sol = (sol * kof) % MOD;
    }
    sol = (sol-1+MOD) % MOD;
    assert(sol >= 0);
    printf("%d\n",sol);
}