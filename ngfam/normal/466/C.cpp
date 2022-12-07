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
const llint N = 5e5 + 1, mod = 1e9 + 7;

llint a[N], sum[N], dwn[N], base;
int n;

struct fenwick{
    int bit[N];
    void upd(int i, int val){
        for(; i > 0; i &= i - 1){
            bit[i] += val;
        }
    }
    int get(int i){
        int result = 0;
        for(; i < N; i += i & -i){
            result += bit[i];
        }
        return result;
    }
}fwt;

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", a + i);
        sum[i] = sum[i - 1] + a[i];
    }

    if(sum[n] % 3LL != 0){
        puts("0");
        return;
    }
    base = sum[n] / 3LL;

    for(int i = n; i >= 1; --i){
        dwn[i] = dwn[i + 1] + a[i];
    }

    for(int i = 1; i <= n; ++i){
        if(dwn[i] == base){
            fwt.upd(i, 1);
        }
    }

    llint ans = 0;
    for(int i = 1; i <= n; ++i){
        if(sum[i] == base){
            ans += fwt.get(i + 2);
        }
    }
    printf("%lld", ans);
}