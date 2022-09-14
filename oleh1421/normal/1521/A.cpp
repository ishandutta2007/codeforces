#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=1010;
const ll mod=1000000007;
void solve(){
    ll a,b;cin>>a>>b;
    if (b==1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n"<<a<<" "<<(5ll*b-1ll)*a<<" "<<a*b*5ll<<endl;

}
int32_t main()
{
//    cout<<mod<<endl;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}