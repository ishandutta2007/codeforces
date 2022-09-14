#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=400010;
ll a[N];
ll b[N];
ll f[N];
//const int K=3010;
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    f[1]=max(0ll,a[1]-b[n]);
    ll sum=f[1];
    for (int i=2;i<=n;i++){
        f[i]=max(0ll,a[i]-b[i-1]);
        sum+=f[i];
    }
    ll res=sum-f[1]+a[1];
    for (int i=2;i<=n;i++){
        res=min(res,sum+a[i]-f[i]);
    }
    cout<<res<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}