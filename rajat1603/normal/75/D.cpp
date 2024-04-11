#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n , m;
int sz , inp;
long long ans[N];
long long sum[N];
long long suf[N];
long long pre[N];
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &sz);
        ans[i] = pre[i] = -1e9;
        while(sz--){
            scanf("%d" , &inp);
            sum[i] += inp;
            suf[i] = max(0LL , suf[i]) + inp;
            ans[i] = max(ans[i] , suf[i]);
            pre[i] = max(pre[i] , sum[i]);
        }
    }
    ans[0] = -1e15;
    while(m--){
        scanf("%d" , &inp);
        ans[0] = max(ans[0] , max(0LL , ans[n + 1]) + pre[inp]);
        ans[n + 1] = max(suf[inp] , sum[inp] + max(0LL , ans[n + 1]));
        ans[0] = max(ans[0] , max(ans[inp] , ans[n + 1]));
    }
    printf("%lld\n" , ans[0]);
}