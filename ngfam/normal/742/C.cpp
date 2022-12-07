/* Riven is not just my life :) */

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

int a[N], n, done[N], start[N], cur, dp[N];

void cannot(){
    puts("-1");
    exit(0);
}

llint ans = 0;

void dfs(int u){
    done[u] = cur;
    if(done[a[u]] == 0){
        ++dp[start[done[u]]];
        dfs(a[u]);
    }
    else{
        if(a[u] != start[cur]){
            cannot();
        }
    }
}

llint lcm(llint u, llint v){
    return (u * v) / __gcd(u, v);
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }

    llint ans = 1;
    for(int i = 1; i <= n; ++i){
        if(!done[i]){
            ++cur; start[cur] = i;
            dfs(i); ++dp[i];

            if(dp[i] % 2 == 0){
                dp[i] /= 2;
            }

            ans = lcm(ans, dp[i]);
        }
    }
    printf("%d", ans);
}