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
const llint N = 4e3 + 10, mod = 1e9 + 7;

int n, base, sum[N], cnt[10 * N];
string s;

void MAIN(){

    cin >> base >> s;
    n = s.size(); s = " " + s;

    for(int i = 1; i <= n; ++i){
        sum[i] = sum[i - 1] + s[i] - 48;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = i; j >= 1; --j){
            ++cnt[sum[i] - sum[j - 1]];
        }
    }

    llint ans = 0;
    for(int i = 1; i <= n * 9; ++i){
        if(base % i == 0){
            if(base / i > n * 9) continue;
            ans += llint(cnt[i]) * (cnt[base / i]);
        }
    }
    if(base == 0) printf("%lld", ans * 2 + llint(cnt[0]) * cnt[0]);
    else printf("%lld", ans);
}