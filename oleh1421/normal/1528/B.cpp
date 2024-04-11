#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2000010;
const int L=20;
const ll mod=998244353;
ll dp[N];
vector<int>d[N];
void solve(){
    int n;cin>>n;
    dp[0]=1;
    ll sum=0;
    for  (int i=1;i<=n;i++){
        dp[i]+=sum;
        for (int j=i;j<=n;j+=i){
            dp[j]++;
        }
        dp[i]%=mod;
        sum+=dp[i];
        sum%=mod;
    }
    cout<<dp[n]<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
4 4 4
1010
1111
0101
1111
**/