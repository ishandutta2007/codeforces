#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=100010;
const ll mod=998244353;
int L[N],R[N];
int l[N],r[N];
int ans[N];
int dp[N];
int pref[N];
void solve(){
    int n,M;cin>>n>>M;
    for (int i=1;i<=n;i++) cin>>L[i]>>R[i];
    for (int g=1;g<=M;g++){
        for (int i=1;i<=n;i++){
            l[i]=(L[i]+g-1)/g;
            r[i]=R[i]/g;
        }
        int m=M/g;
        dp[0]=pref[0]=1;
        for (int i=1;i<=m;i++) dp[i]=0,pref[i]=1;
        for (int i=1;i<=n;i++){
            for (int j=0;j<=m;j++){
                if (j<l[i]) dp[j]=0;
                else if (j<=r[i]) dp[j]=pref[j-l[i]];
                else dp[j]=(pref[j-l[i]]-pref[j-r[i]-1]+mod)%mod;
            }
            pref[0]=dp[0];
            for (int j=1;j<=m;j++){
                pref[j]=(pref[j-1]+dp[j])%mod;
            }
//            for (int j=1;j<=m;j++) cout<<dp[j]<<" ";
//            cout<<endl;
        }
        ans[g]=pref[m];
    }
    for (int i=M;i>=1;i--){
        for (int j=i*2;j<=M;j+=i) ans[i]=(ans[i]-ans[j]+mod)%mod;
    }
    cout<<ans[1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
ba
ca
aca
a
b
c
ac
*/