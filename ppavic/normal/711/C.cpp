#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long int llint;

const llint INF = 1e17+7;

llint dp[105][105][105];
int c[105];
llint p[105][105];
int n,m,k;

llint f(int i,int s,int last){
    llint sol = INF;
    if(i == n){
        if(s == k) return 0;
        else return INF;
    }
    if(last != -1) if(dp[i][s][last] != -1) return dp[i][s][last];
    if(c[i] == 0){
        for(int j = 1;j<=m;j++){
            if(j != last){
                sol = min(f(i+1,s+1,j)+p[i][j],sol);
            }
            else{
                sol = min(f(i+1,s,j)+p[i][j],sol);
            }
        }
    }
    else{
        if(c[i] == last){
            sol = min(f(i+1,s,last),sol);
        }
        else{
            sol = min(f(i+1,s+1,c[i]),sol);
        }
    }
    dp[i][s][last] = sol;
    return sol;
}

int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<n;i++){
        scanf("%d",&c[i]);
    }
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=m;j++)
            scanf("%I64d",&p[i][j]);
    }
    llint sol = f(0,0,-1);
    if(sol >= INF){
        printf("-1\n");
    }
    else{
        printf("%I64d\n",sol);
    }
}