#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5 + 500;
const int MOD = 1e9 + 7;

typedef long long int llint;

llint dp[N][5],pref[N],suff[N];
int par[N],col[N],n,m;
vector < int > v[N];

llint f(int i,int x){
    if(v[i].size() == 0 && col[i] && x) return 1;
    if(v[i].size() == 0 && !col[i] && !x) return 1;
    if(v[i].size() == 0) return 0;
    if(dp[i][x] > -1) return dp[i][x];
    llint sol = 0;
    for(int j = 0;j<v[i].size();j++){
        f(v[i][j],0);f(v[i][j],1);
    }
    for(int j = 0;j<v[i].size();j++){
        pref[j] = (f(v[i][j],0) + f(v[i][j],1)) % MOD;
        if(j)
            pref[j] =pref[j] * pref[j-1] % MOD;
    }
    for(int j = (int)v[i].size()-1;j>=0;j--){
        suff[j] = (f(v[i][j],0) + f(v[i][j],1)) % MOD;
        if(j < (int)v[i].size() - 1)
            suff[j] =suff[j] * suff[j+1] % MOD;
    }
    if((x == 0 && col[i] == 0) || (x == 1 && col[i] == 1)){
        sol =  pref[(int)v[i].size()-1];

    }
    else if(x == 0 && col[i])
        sol = 0;
    else{
        if(v[i].size() == 1) sol = f(v[i][0],1);
        else{
            sol = (suff[1] * f(v[i][0],1) % MOD + pref[v[i].size()-2] * f(v[i][v[i].size()-1],1) % MOD) % MOD;
            for(int j = 1;j<v[i].size()-1;j++){
                 sol = (sol+(pref[j-1] * f(v[i][j],1) % MOD * suff[j+1] % MOD)) % MOD;
            }
        }
    }
    dp[i][x] = sol;
    return sol;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        scanf("%d",par+i);
        v[par[i]].push_back(i);
    }
    for(int i = 0;i<n;i++)
        scanf("%d",col+i);
    printf("%I64d\n",f(0,1));
}