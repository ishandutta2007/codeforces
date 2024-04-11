#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    ll n;
    scanf("%lld", &n);
    if (n%2050){
        printf("-1\n");
        return;
    }
    n /= 2050;
    ll ans=0;
    while(n){
        ans += n%10;
        n /= 10;
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}