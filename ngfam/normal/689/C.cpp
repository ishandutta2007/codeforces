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

llint m;

llint cal(llint val){
    llint result = 0;
    for(llint i = 2; i <= 1000000LL; ++i){
        result += val / (i * i * i);
        if(result > m) return result;
    }
    return result;
}

void MAIN(){
    scanf("%lld", &m);
    llint lef = 1, rig = 1e18 + 10, ans = rig;
    while(lef <= rig){
        llint mid = (lef + rig) >> 1;
        llint ginz = cal(mid);
        if(ginz == m){
            ans = min(ans, mid);
        }
        if(ginz >= m){
            rig = mid - 1;
        }
        else{
            lef = mid + 1;
        }
    }
    if(cal(ans) != m) puts("-1");
    else printf("%lld", ans);
}