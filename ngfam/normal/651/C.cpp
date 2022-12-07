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
typedef pair<int,int> ii;

bool cmp(ii x, ii y){
    if(y.second == x.second) return x.first < y.first;
    return x.second < y.second;
}

ii ginz[N];
llint ans = 0;

void MAIN(){
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int u, v; scanf("%d%d", &u, &v);
        ginz[i] = ii(u, v);
    }

    int m = 0, cnt = 0;
    sort(ginz + 1, ginz + n + 1);
    ginz[0] = ii(-mod, -mod);

    for(int i = 1; i <= n; ++i){
        if(ginz[i] == ginz[i - 1]){
            ++cnt;
        }
        else{
            ans -= (llint(cnt) * llint(cnt - 1)) / 2;
            cnt = 1;
        }
    }

    ans -= (llint(cnt) * llint(cnt - 1)) / 2;
    cnt = 0;
    m = n;
    for(int i = 1; i <= m; ++i){
        if(ginz[i].first == ginz[i - 1].first){
            ++cnt;
        }
        else{
            ans += (llint(cnt) * llint(cnt - 1)) / 2;
            cnt = 1;
        }
    }
    ans += (llint(cnt) * llint(cnt - 1)) / 2;
    cnt = 0;
    sort(ginz + 1, ginz + m + 1, cmp);

    for(int i = 1; i <= m; ++i){
        if(ginz[i].second == ginz[i - 1].second){
            ++cnt;
        }
        else{
            ans += (llint(cnt) * llint(cnt - 1)) / 2;
            cnt = 1;
        }
    }
    ans += (llint(cnt) * llint(cnt - 1)) / 2;
    printf("%lld", ans);
}