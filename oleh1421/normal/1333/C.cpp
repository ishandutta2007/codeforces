#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=300010;
int a[N];
ll s[N];
int dp[N];
map<ll,int>last;
void solve(){
    last.clear();
    int n;cin>>n;
    s[0]=0ll;
    for (int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
    dp[0]=1ll;
    last[0]=0;
    for (int i=1;i<=n;i++){
        if (last.find(s[i])==last.end()) dp[i]=dp[i-1]+1;
        else {
            dp[i]=min(dp[i-1]+1,i-last[s[i]]);
        }
        last[s[i]]=i;
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=dp[i]-1ll;
    }
    cout<<res<<endl;
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