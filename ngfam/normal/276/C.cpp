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

int a[N], query[N], n, q;

void MAIN(){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= q; ++i){
        int low, high;
        scanf("%d%d", &low, &high);
        ++query[low]; --query[high + 1];
    }
    partial_sum(query + 1, query + n + 1, query + 1);


    sort(query + 1, query + n + 1);
    llint ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += llint(a[i]) * llint(query[i]);
    }
    printf("%lld", ans);
}