#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    ll ans=0;
    for (int i=(n+2)/2;i<n;i++) ans += (ll)(i-1)*(i-1);
    for (int i=(n+2)/2-1;i>=1;i--) ans += (ll)(n-i)*(n-i);
    printf("%lld\n", ans);
    printf("%d ", (n+2)/2);
    for (int i=1;i<(n+2)/2-1;i++) printf("%d ", i);
    for (int i=(n+2)/2+1;i<=n;i++) printf("%d ", i);
    printf("%d ", (n+2)/2-1);
    printf("\n");
    printf("%d\n", n-1);
    for (int i=(n+2)/2;i<n;i++) printf("%d 1\n", i);
    for (int i=(n+2)/2-1;i>=1;i--) printf("%d %d\n", i, n);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}