#pragma GCC optimize ("Ofast")
/// #pragma GCC target("avx2")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int dp[101];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    dp[0]=0;
    for (int i=1;i<=30;i++) dp[i]=4ll*dp[i-1]+1ll;
    while (tt--){
        int n,k;cin>>n>>k;
        if (n==2 && k==3) cout<<"NO\n";
        else if (n<=30 && dp[n]<k) cout<<"NO\n";
        else {
        k--;
        int a=n-1;
        for (int i=2;i<=n;i++){
             if ((1ll<<i)-1ll<=k){
                k-=(1ll<<i)-1ll;
                a--;
             } else break;
        }
        cout<<"YES "<<a<<endl;
        }

    }
    return 0;
}
///4^i-1

//3,7,31