#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=450010;
int a[N];
ll f(ll x){
    return (x*(x+1ll))/2ll;
}
void solve(){
    ll n,m;cin>>n>>m;
    n-=m;
    ll k=(n/(m+1ll));
    ll g=(n%(m+1ll));
    cout<<f(n+m)-(f(k)*(m+1ll-g)+f(k+1ll)*g)<<endl;
}
int32_t main()
{
//    freopen("repair.in","r",stdin);
//    freopen("repair.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}