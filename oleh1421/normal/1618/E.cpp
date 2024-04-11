#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int ll
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1000100;
ll b[N];
ll a[N];
void solve(){
    int n;cin>>n;
    ll sum=0ll;
    for (int i=1;i<=n;i++) cin>>b[i],sum+=b[i];
    ll cnt=(n+1ll)*n/2ll;
    if (sum%cnt) {
        cout<<"NO\n";
        return;
    }
    sum/=cnt;
    for (int i=1;i<=n;i++){
        int last=i-1;
        if (last==0) last=n;
        ll diff=sum-b[i]+b[last];
        if (diff<=0 || diff%n){
            cout<<"NO\n";
            return;
        }
        a[i]=diff/n;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;

}
/**
10 30 15
12 31 14 18

10 12 14 15 18 30 31
**/