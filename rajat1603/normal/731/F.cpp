#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n;
int inp;
int cnt[N];
long long sum[N];
long long ans;
void solve(int val){
    long long tot = sum[N - 1];
    for(int i = 0 ; i + i < N ; i += val){
        int cn = cnt[i + val - 1] - cnt[i];
        long long sm = sum[i + val - 1] - sum[i];
        tot -= sm - 1LL * cn * i;
    }
    ans = max(ans , tot);
}
int main(){
    scanf("%d" , &n);
    while(n--){
        scanf("%d" , &inp);
        ++cnt[inp];
        sum[inp] += inp;
    }
    for(int i = 1 ; i < N ; ++i){
        sum[i] += sum[i - 1];
        cnt[i] += cnt[i - 1];
    }
    for(int i = 1 ; i + i < N ; ++i){
        if(cnt[i] - cnt[i - 1]){
            solve(i);
        }
    }
    printf("%lld\n" , ans);
}