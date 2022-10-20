#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll r[3], a[1001000], dp[1001000];

ll calc(int x){
    return min(r[1]+r[0], min((a[x]+2)*r[0], a[x]*r[0]+r[2]));
}

int main(){
    int n;
    ll d;
    scanf("%d %lld %lld %lld %lld", &n, r, r+1, r+2, &d);
    for (int i=0;i<n;i++) scanf("%lld", a+i);
    dp[0] = r[0]*a[0]+r[2];
    dp[1] = min(dp[0]+r[0]*a[1]+r[2]+d, d*3+calc(1)+calc(0));
    for (int i=2;i<n;i++){
        dp[i] = dp[i-1] + r[0]*a[i]+r[2]+d;
        dp[i] = min(dp[i], dp[i-2]+d*4+calc(i)+calc(i-1));
        dp[i] = min(dp[i], dp[i-1]+calc(i)+d*3);
    }
    ll ans = dp[n-1];
    ll tmp = 0;
    if (n>2) tmp = dp[n-3]+d;
    ans = min(ans, tmp+d*2+calc(n-2)+r[0]*a[n-1]+r[2]);
    ans = min(ans, dp[n-1]+calc(n-1)+d*3);
    //for (int i=0;i<n;i++) printf("%lld ", dp[i]);
    printf("%lld\n", ans);
    return 0;
}