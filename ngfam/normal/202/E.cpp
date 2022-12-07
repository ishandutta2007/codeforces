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

int n, m, a[N], sll[N], slc[N];
llint sum[N], odd[N], even[N], turn[N], go[N];

llint cal(int i){
    return turn[i - 1] - sum[i - 1];
}

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        scanf("%d", a + i);
        odd[i] = a[i] - !(a[i] & 1);
        even[i] = a[i] - (a[i] & 1);
        sum[i] = sum[i - 1] + odd[i];
    }

    for(int i = 1; i < n; ++i){
        if(a[i] == 1) continue;
        turn[i] = turn[i - 1] + even[i];
    }
    for(int i = n - 1; i >= 1; --i){
        if(a[i] == 1) continue;
        go[i] = go[i + 1] + even[i];
    }
    llint cur = 0, ans = max(turn[n - 1], go[1]);
    for(int i = 1; i <= n; ++i){
        ans = max(ans, go[i] + sum[i - 1] + cur);
        cur = max(cur, cal(i));
    }

    cur = sum[n - 1];
/*    for(int i = n - 1; i >= 1; --i){
        ans = max(ans, turn[i - 1] - sum[i - 1] + cur);
        cur = max(cur, cal(i));
    }*/
    printf("%lld", ans);
}