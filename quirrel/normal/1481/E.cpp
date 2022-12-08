#include<bits/stdc++.h>
using namespace std;
int a[500009],l[500009],r[500009],cnt[500009],mx[500009],dp[500009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(l[a[i]] == 0) l[a[i]] = i;
        r[a[i]] = i;
    }
    for(int i = n; i >= 1; i--){
        cnt[a[i]]++;
        mx[i] = max(mx[i+1], cnt[a[i]]);
    }
    int ans = mx[1];
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        if(i == r[a[i]]) dp[i] = max(dp[i], cnt[a[i]] + dp[l[a[i]]-1]);
        ans = max(ans, dp[i] + mx[i+1]);
    }
    cout<<n-ans<<endl;
}