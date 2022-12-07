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

typedef pair<int,int> ii;

int n, m, dp[N][2];

ii riki[N];

struct fwt{
    llint bit[N];
    void upd(int i, llint val){
        for(; i < N; i += i & -i){
            bit[i] += val;
        }
    }

    llint get(int i){
        llint result = 0;
        for(; i > 0; i &= i - 1){
            result += bit[i];
        }
        return result;
    }
}fwt1, fwt2, fwt3;

void MAIN(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int val; scanf("%d", &val);
        riki[i] = ii(val, i);
    }

    sort(riki + 1, riki + n + 1);

    //cout << riki[1].first;

    llint ans = 0;
    for(int i = n; i >= 1; --i){
        ans += fwt2.get(riki[i].second);
        fwt2.upd(riki[i].second, fwt1.get(riki[i].second));
        fwt1.upd(riki[i].second, 1);
    }
    printf("%lld", ans);
}