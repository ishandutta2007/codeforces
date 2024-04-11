#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[5050];
ll dp[5050];

int solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    for (int i=0;i<n;i++) dp[i]=0;
    ll ans=0;
    for (int i=0;i<n;i++){
        ans += max((ll)a[i]-dp[i]-1, 0LL);
        for (int j=i+2;j<min(n, i+a[i]+1);j++) dp[j]++;
        if (a[i]-dp[i]-1<0 && i+1<n) dp[i+1] += -(a[i]-dp[i]-1);
    }
    //for (int i=0;i<n;i++) printf("%lld ", dp[i]);
    printf("%lld\n", ans);
    return 0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}