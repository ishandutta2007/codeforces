#pragma GCC optimize ("Ofast")
/// #pragma GCC target("avx2")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
using namespace std;
int mod=998244353;
int dp[1001][1001];
int cnt[1001][1001];
int a[1001];
int n,k;
int r[1001];
int pref[1001];
int solve(int x){
    for (int i=0;i<=n;i++) for (int j=0;j<=k;j++) dp[i][j]=0;
    r[0]=0;
    for (int i=1;i<=n;i++){
        r[i]=r[i-1];
        while (a[i]-a[r[i]+1]>=x) r[i]++;
    }
    for (int i=1;i<=n;i++) dp[1][i]=1;
    for (int i=2;i<=k;i++){
        pref[0]=0;
        for (int j=1;j<=n;j++){
            pref[j]=(pref[j-1]+dp[i-1][j])%mod;
        }
        for (int j=1;j<=n;j++){
            dp[i][j]=pref[r[j]];
        }
    }
    int res=0ll;
    for (int i=1;i<=n;i++) res=(res+dp[k][i])%mod;
    return res;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int res=0ll;
    for (int i=1;i*k-i<=100000;i++){
        res+=solve(i);
        res%=mod;
    }
    cout<<res;
    return 0;
}