#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll dp[100100], a[100100], b[100100], c[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", c+i);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    for (int i=0;i<n;i++) scanf("%lld", b+i);
    ll ans=0;
    for (int i=1;i<n;i++){
        dp[i]=c[i]+1+abs(a[i]-b[i]);
        if (a[i]!=b[i]) dp[i]=max(dp[i], dp[i-1]-abs(a[i]-b[i])+c[i]+1);
        ans=max(ans, dp[i]);
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