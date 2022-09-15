#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[100001];
ll a1[100001];
ll dp[200001];
int main(){

    int n;cin>>n;
    for (int i=1;i<=2*n;i++) {
        int b;cin>>b;
        if (a[b]) a1[b]=i*1ll;
        else a[b]=i*1ll;
    }
    dp[1]=a[1]-1ll+a1[1]-1ll;
    for (int i=2;i<=n;i++){
        dp[i]=dp[i-1]*1ll+min(abs(a[i-1]-a[i])*1ll+abs(a1[i-1]-a1[i])*1ll,abs(a[i-1]-a1[i])*1ll+abs(a1[i-1]-a[i])*1ll)*1ll;
    }
    cout<<dp[n]*1ll;

    return 0;
}