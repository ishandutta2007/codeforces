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

llint k, n, pos[N], len[N];

void MAIN(){
    scanf("%lld%lld", &n, &k);
    for(int i = 0; i < n; ++i){
        if(k & (1LL << i)){
            printf("%d", i + 1);
            return;
        }
    }
}