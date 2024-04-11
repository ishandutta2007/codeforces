#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=100010;
int a[N];
ll dp[2][128];
int s[N][7];
void solve(){
    int n,p,k;cin>>n>>p>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=0;j<p;j++) cin>>s[i][j];
    }
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++) v.push_back({-a[i],i});
    sort(v.begin(),v.end());
    for (int i=0;i<2;i++) for (int j=0;j<(1<<p);j++) dp[i][j]=-10000000000000001ll;
    dp[0][0]=0;
    for (int t=0;t<n;t++){
        int i=v[t].second;
        for (int mask=0;mask<(1<<p);mask++) dp[(t+1)%2][mask]=dp[t%2][mask];
        for (int mask=0;mask<(1<<p);mask++){
//            cout<<t<<" "<<i<<" "<<mask<<" "<<dp[t%2][mask]<<endl;
            int cn=__builtin_popcount(mask);
            if (t+1-cn<=k) {
//                cout<<"OK\n";
//                if ((t+1)%2==0 && mask==0) cout<<"OK1\n";
                dp[(t+1)%2][mask]=max(dp[(t+1)%2][mask],dp[t%2][mask]+a[i]*1ll);
            }
            for (int j=0;j<p;j++){
                if (mask&(1<<j)) continue;
//                if (j==1) cout<<"dp: "<<i<<" "<<s[i][j]<<" "<<mask<<" "<<dp[t%2][mask]<<endl;
                dp[(t+1)%2][mask^(1<<j)]=max(dp[(t+1)%2][mask^(1<<j)],dp[t%2][mask]+s[i][j]*1ll);
            }
        }
    }
    cout<<dp[n%2][(1<<p)-1]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}