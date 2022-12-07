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

llint a[N], p[N];
int n, m;

bool check(llint val){
    int cur = 1;
    for(int i = 1; i <= n; ++i){
        if(p[i] < a[cur]){
            while(cur <= m && a[cur] <= p[i] + val){ ++cur; };
            continue;
        }

        if(cur > m) return true;

        if(val < p[i] - a[cur]){
            return false;
        }
        llint rmax = (val - (p[i] - a[cur])) / 2LL;
        llint lmax = (val - (p[i] - a[cur]) * 2);
        llint result = max(rmax, lmax);
        while(cur <= m && a[cur] <= p[i] + result){
            ++cur;
        }
    }
    return (cur > m);
}

void MAIN(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", p + i);
    }
    for(int i = 1; i <= m; ++i){
        scanf("%lld", a + i);
    }

    llint low = 0, high = 3e10 + 10, ans = high;
    while(low <= high){
        llint val = (low + high) >> 1LL;
        //cerr << low << " " << high << " " << val << endl;
        if(check(val)){
            ans = min(ans, val);
            high = val - 1;
        }
        else{
            low = val + 1;
        }
    }
    //cerr << check(4);
    printf("%lld", ans);
}