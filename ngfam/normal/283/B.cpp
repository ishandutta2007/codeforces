/*** Riven is not just my life :) ***/

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

int n, a[N], done[N][2], cycle[N][2], cur;
llint dp[N][2];

void dfs(int i, int mask){
    if(done[i][mask]) return;
    done[i][mask] = cur;
    if(i <= 0 || i > n) return;
    int j = (mask ? i - a[i] : i + a[i]);
    //if(i == 2 && mask == 1) cerr << j;
    if(j == 1){
        if(mask == 1) cycle[i][mask] = 1;
        else{
            dp[i][mask] = a[i];
        }
        return;
    }

    if(j <= 0 || j > n){
        dp[i][mask] = a[i];
        return;
    }

    if(done[j][1 - mask] == 0){
        dfs(j, 1 - mask);
        cycle[i][mask] = cycle[j][1 - mask];
        dp[i][mask] = max(dp[i][mask], dp[j][1 - mask]);
    }
    else if(done[j][1 - mask] == cur){
        cycle[i][mask] = 1;
        return;
    }
    else{
        if(cycle[j][1 - mask]){
            cycle[i][mask] = 1;
        }
        dp[i][mask] = max(dp[i][mask], dp[j][1 - mask]);
    }
    dp[i][mask] += a[i];
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i){
        scanf("%d", a + i);
    }

    for(int i = 2; i <= n; ++i){
        if(!done[i][0]){
            ++cur;
            dfs(i, 0);
        }
        if(!done[i][1]){
            ++cur;
            dfs(i, 1);
        }
    }
    for(int i = 1; i < n; ++i){
        a[1] = i;
        dfs(1 + i, 1);
        if(cycle[i + 1][1]){
            puts("-1");
        }
        else{
            printf("%lld\n", i + dp[i + 1][1]);
        }
    }
}