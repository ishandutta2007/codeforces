#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000;
const int N=300010;
int a[N];
int dp[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=0;i<=n;i++) dp[i]=0;
    for (int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if (i>=a[i]){
            dp[i]=max(dp[i],dp[i-a[i]]+1);
        }
    }
    cout<<dp[n]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}