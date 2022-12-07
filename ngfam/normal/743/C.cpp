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

void MAIN(){
    llint n; scanf("%lld", &n);
    for(llint i = n + 1; i <= n * n; ++i){
        llint shift = abs(i - n);
        if((i * n) % shift == 0){
            printf("%lld %lld %lld", n, i, (i * n) / shift);
            return;
        }
    }
    puts("-1");
}