#include "bits/stdc++.h"
using namespace std;
int n , m;
int cnt[11];
int inp;
long long ans = 0;
int main(){
    scanf("%d %d" , &n , &m);
    memset(cnt , 0 , sizeof(cnt));
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp);
        ans += i - 1 - cnt[inp];
        ++cnt[inp];
    }
    cout << ans;
}