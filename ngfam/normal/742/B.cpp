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
const llint N = 1e5 + 1, mod = 1e9 + 7;

int n, a[N], cnt[N], x;

void MAIN(){
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        ++cnt[a[i]];
    }

    llint ans = 0;
    for(int i = 1; i <= n; ++i){
        int shift = a[i] ^ x;
        if(shift < N){
            if(a[i] == shift){
                --ans;
            }
            ans += cnt[shift];
        }
    }
    printf("%lld", ans / 2);
}