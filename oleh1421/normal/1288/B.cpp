#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
void solve(){
    ll a,b;cin>>a>>b;
    ll cur=10ll;
    ll cnt=0ll;
    while (cur-1ll<=b){
        cur*=10ll;
        cnt++;
    }
    cout<<a*cnt<<endl;
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