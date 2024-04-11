#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
void solve(){
    ll n,g,b;cin>>n>>g>>b;
    ll m=(n+1)/2;
    ll x=(m/g)*(g+b)+m%g;
    if (m%g==0) x-=b;
    cout<<max(x,n)<<endl;

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