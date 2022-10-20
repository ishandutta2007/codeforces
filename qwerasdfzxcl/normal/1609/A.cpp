#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[100100];

void solve(){
    int n;
    scanf("%d", &n);
    ll cnt = 1;
    for (int i=0;i<n;i++){
        scanf("%lld", a+i);
        while(a[i]%2==0){
            cnt *= 2;
            a[i] /= 2;
        }
    }
    sort(a, a+n);
    ll ans = 0;
    for (int i=0;i<n-1;i++) ans += a[i];
    ans += cnt * a[n-1];
    printf("%lld\n", ans);
}

int main(){
    for (int i=0;i<1e7;i++) clock();
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}