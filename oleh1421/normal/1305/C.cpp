#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=500010;
int a[N];
int cnt[1010];
ll res[1010];
ll binpow(ll a,ll b,ll m){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1ll,m))%m;
    else return binpow((a*a)%m,b/2ll,m);
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int sum=0;
    for (int i=1;i<=n;i++){
        a[i]%=m;
        int x=a[i];
        for (int j=0;j<=x;j++){
            res[x-j]+=cnt[j];
        }
        for (int j=x+1;j<m;j++){
            res[x-j+m]+=cnt[j];
        }
        cnt[x]++;
    }
    ll mult=1ll;
    for (int i=0;i<m;i++){
        mult*=binpow(i,res[i],m);
        mult%=m;
    }
    cout<<mult<<endl;

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