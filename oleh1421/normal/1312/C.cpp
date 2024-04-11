//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll mod=1000000007ll;
const int N=400010;
ll a[N];
bool used[155];
void solve(){
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=100;i++) used[i]=false;
    for (int i=1;i<=n;i++){
        ll x=a[i];
        int j=0;
        while (x){
            if (x%k>1ll){
                cout<<"NO\n";
                return;
            }
            if (x%k==1ll && used[j]){
                cout<<"NO\n";
                return;
            }
            if (x%k) used[j]=true;
            x/=k;
            j++;
        }
    }
    cout<<"YES\n";

}
int32_t main(){
//    freopen("accounts.in","r",stdin);
//    freopen("accounts.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}