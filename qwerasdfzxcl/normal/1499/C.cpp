#include <bits/stdc++.h>

typedef __int128_t ll;
using namespace std;
long long tmp[100100];
ll a[100100], dp[100100], dp2[100100], s1[100100], s2[100100];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%lld", tmp+i);
    for (int i=0;i<n;i++) a[i]=tmp[i];
    s1[0]=a[0], s2[1]=a[1];
    for (int i=2;i<n;i++){
        if (i&1) s2[i] = s2[i-2]+a[i];
        else s1[i] = s1[i-2]+a[i];
    }
    ll ans=1e36;
    dp[0]=a[0]*n, dp[1]=a[1]*n;
    ll cur1=a[0], cur2=a[1];
    for (ll i=2;i<n;i++){
        if (i&1){
            if (cur2>a[i]) dp[i]=(ll)s2[i-2]+(ll)(n-i/2)*a[i];
            else dp[i]=dp[i-2]-cur2+a[i];
            cur2=min(cur2, a[i]);
        }
        else{
            if (cur1>a[i]) dp[i]=(ll)s1[i-2]+(ll)(n-i/2)*a[i];
            else dp[i]=dp[i-2]-cur1+a[i];
            cur1 = min(cur1, a[i]);
        }
    }
    for (int i=1;i<n;i++) ans = min(ans, dp[i]+dp[i-1]);
    printf("%lld\n", (long long)ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}