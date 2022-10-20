#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200];
int dp[200200];

void solve(){
    for (int i=0;i<200200;i++) dp[i]=0;
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    sort(a, a+n);
    int ans=0;
    for (int i=0;i<n;i++){
        for (int k=1;k<=a[i];k++){
            if (k>a[i]/k) break;
            if (a[i]/k*k==a[i]){
                dp[a[i]]=max(dp[a[i]], dp[a[i]/k]+1);
                if (k!=a[i]/k) dp[a[i]]=max(dp[a[i]], dp[k]+1);
            }
        }
        ans=max(ans, dp[a[i]]);
        //printf("%d ", dp[a[i]]);
    }
    printf("%d\n", n-ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}