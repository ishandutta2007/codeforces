#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const ll mod=998244353;
const int N=200010;
ll a[N];
ll dp[N][2];
ll pref[N][2];
int l[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        l[i]=0;
        for (int j=i-1;j>=1;j=l[j]){
            if (a[j]<a[i]){
                l[i]=j;
                break;
            }
        }
    }
    dp[0][0]=1;
    dp[0][1]=0;
    pref[0][0]=1;
    pref[0][1]=0;
    for (int i=1;i<=n;i++){
        for (int rem=0;rem<2;rem++){
//            ll mn=a[i];
            dp[i][rem]=pref[i-1][rem^1];
            if (l[i]){
                dp[i][rem]+=mod-pref[l[i]-1][rem^1];
                dp[i][rem]%mod;
            }
            dp[i][rem]*=a[i];
            if (l[i]) dp[i][rem]+=dp[l[i]][rem];
            dp[i][rem]%=mod;
//            cout<<i<<" "<<rem<<" "<<dp[i][rem]<<endl;
//            for (int j=i;j>=1;j--){
//                mn=min(mn,a[j]);
//                dp[i][rem]+=dp[j-1][rem^1]*mn;
//                dp[i][rem]%=mod;
//            }
            pref[i][rem]=(pref[i-1][rem]+dp[i][rem])%mod;
        }
    }
    cout<<(mod+dp[n][n%2]-dp[n][(n+1)%2])%mod<<endl;
    return 0;
}