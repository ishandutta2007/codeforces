#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
void solve(){
    ll x,y,a,b;cin>>x>>y>>a>>b;
    if (x>y) swap(x,y);
    b=min(b,a+a);
    cout<<x*b+(y-x)*a<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}